/*==================[inclusiones]============================================*/
#include "pidController.h"
/*==================[definiciones de datos internos]=========================*/
/*==================[declaraciones de funciones internas]====================*/
/*==================[definiciones de funciones internas]=====================*/
/*==================[definiciones de funciones externas]=====================*/

/*-----------------------------------------------------------------
* PIDInitVariables
* Inicializa las variables Kp, Ki, Kd con respecto al deltaT elegido
* Cada bucle del control PID le va a llevar el mismo tiempo siempre,
* por lo que el calculo siempre es constante.
* Argumentos:
* PIDVariables - Puntero donde se almancenan los coeficientes del control PID
* Kp - coeficiente proporcional
* Kd - coeficiente diferencial
* Ki - coeficiente integral
* deltaT - Tiempo en segundos entre bucle y bucle
*-----------------------------------------------------------------*/
void PIDInitVariables(pid_variables_t * PIDVariables, uint32_t Kp, uint32_t Kd, uint32_t Ki, float deltaT)
{

  PIDVariables->Kp = Kp;
  PIDVariables->Kd = Kd / deltaT;
  PIDVariables->Ki = Ki * deltaT;

  //Que tan constante es cada bucle de tiempo se testeará en un orden superior,
  //cuando se arme las tareas del sistema operativo de tiempo real que usara
  //este modulo. A fines de estos test unitarios se asume que se cumple
}

/*-----------------------------------------------------------------
* PIDloop
* Calcula la potencia del calefactor en el ciclo de PID
* Argumentos:
* error - Error entre la temperatura medida y seteada
* lastError - puntero al ultimo error medido (usado para la parte derivativa)
* errorAcumulated - puntero al error acumulado (usado para la parte integral)
* PIDVariables - Puntero donde se almancenan los coeficientes del control PID
* Salida: Valor de PWM para alimentar al calefactor
*-----------------------------------------------------------------*/
uint8_t PIDloop(int16_t error, int16_t * lastError, int32_t * errorAcumulated, pid_variables_t * PIDVariables)
{

  int16_t output = 0;

  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender.
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender proporcional al error (Control P).

  //El controlPID debe calcular la derivada del error con un esquema upwinding
  output = (int16_t) PIDVariables->Kd * upwinding_scheme(error, *lastError);
  output = output + (int16_t) (PIDVariables->Kp * error);
  output = output + (int16_t) (PIDVariables->Ki * (*errorAcumulated));

  //cuando el valor de calefactor supera el valor maximo, se satura al maximo valor.
  if (output > 0xFF) {
    output = 0xFF;
  }
  //Si el valor es menor de cero, el calefactor se apaga
  if (output < 0) {
    output = 0;
  }

  *lastError = error; //Guarda el ultimo valor de error
  *errorAcumulated = *errorAcumulated + error; //Acumula el error

  return (uint8_t) output;

}

/*-----------------------------------------------------------------
* upwinding_scheme
* Calcula la derivada usando el esquema upwinding
* Argumentos:
* xi - Valor actual
* ximinusone - Valor anterior
* Salida: La diferencia ente valores. Como el salto en el tiempo es
* constante no se divide en el tiempo.
*-----------------------------------------------------------------*/
int16_t upwinding_scheme(int16_t xi, int16_t ximinusone)
{

  int16_t output = 0;

  output = (int16_t) (xi - ximinusone);

}

/*-----------------------------------------------------------------
* obtain_error
* Calcula el error entre la temperatura medida por el sensor de temperatura
* y el valor seteado
* Argumentos:
* errorPID - Puntero al error entre temperatura medida y seteada
* setpoint - Valor anterior de temperatura seteada
* Salida: Si es cero, la lecutra fue correcta, un valor negativo significa
* que hubo algun problema en el sensor.
*-----------------------------------------------------------------*/
int8_t obtain_error(int16_t * errorPID, int16_t setpoint)
{
  int8_t output = 0;

  int16_t temp = bmp180ReadTemp();

  //Si no hubo un error en la lectura del sensor
  if (temp > 0) {
    *errorPID = setpoint - temp;
  }
  else { //En cambio si hubo, da el error que hubo
    *errorPID = 0;
    output = temp;
  }

  return output;

}
/*==================[fin del archivo]========================================*/
