#include "pidController.h"

uint8_t PIDloop(int16_t error, uint32_t Kp)
{

  uint8_t output = 0;

  //Cuando el error entre la SETPOINT y la temperatura medida es negativa, el calefactor se debe apagar
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender.
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender proporcional al error (Control P).
  if( error > 0 ) {

    output = Kp * error;

  }

  return output;

}
