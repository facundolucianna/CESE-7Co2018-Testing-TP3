#include "pidController.h"

uint8_t PIDloop(int16_t error, int16_t * lastError, uint32_t Kp, uint32_t Kd, float deltaT)
{

  uint16_t output = 0;

  //Cuando el error entre la SETPOINT y la temperatura medida es negativa, el calefactor se debe apagar
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender.
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender proporcional al error (Control P).
  if( error > 0 ) {

    //El controlPID debe calcular la derivada del error con un esquema upwinding
    output = (uint16_t) Kd * (((error - (*lastError)) / deltaT));
    output = output + Kp * error;

    //cuando el valor de calefactor supera el valor maximo, se satura al maximo valor.
    if (output > 0xFF) {

      output = 0xFF;

    }

  }

  *lastError = error; //Guarda el ultimo valor de error

  return (uint8_t) output;

}
