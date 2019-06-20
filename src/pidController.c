#include "pidController.h"

uint8_t PIDloop(int16_t error, int16_t * lastError, int32_t * errorAcumulated, uint32_t Kp, uint32_t Kd, uint32_t Ki, float deltaT)
{

  int16_t output = 0;

  //Cuando el error entre la SETPOINT y la temperatura medida es negativa, el calefactor se debe apagar
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender.
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender proporcional al error (Control P).

  //El controlPID debe calcular la derivada del error con un esquema upwinding
  output = Kd * upwinding_scheme(error, *lastError, deltaT);
  output = output + Kp * error;
  output = output + Ki * (*errorAcumulated)*deltaT;

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

//Primera derivada en esquema upwinding
int16_t upwinding_scheme(int16_t xi, int16_t ximinusone, float deltaT)
{

  int16_t output = 0;

  output = (int16_t) ((xi - ximinusone) / deltaT);

}
