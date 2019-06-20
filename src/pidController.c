#include "pidController.h"

uint8_t PIDloop(int16_t error)
{

  uint8_t output = 0;

  //Cuando el error entre la SETPOINT y la temperatura medida es negativa, el calefactor se debe apagar
  //Cuando el error entre la SETPOINT y la temperatura medida es positivo, el calefactor se debe prender.
  if( error > 0 ) {

    output = 1;

  }

  return output;

}
