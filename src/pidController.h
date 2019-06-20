#ifndef _PIDCONTROLLER_H
#define _PIDCONTROLLER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>
#include "bmp180.h"

/*==================[macros]=================================================*/
/*==================[tipos de datos declarados por el usuario]===============*/
typedef struct {
   float Kp;
   float Kd;
   float Ki;
} pid_variables_t;

/*==================[declaraciones de datos externos]========================*/
/*==================[declaraciones de funciones externas]====================*/

void PIDInitVariables(pid_variables_t *, uint32_t, uint32_t, uint32_t, float);
uint8_t PIDloop(int16_t, int16_t *, int32_t *, pid_variables_t *);
int16_t upwinding_scheme(int16_t, int16_t);
int8_t obtain_error(int16_t *, int16_t);

/*==================[fin del archivo]========================================*/
#endif // _PIDCONTROLLER_H
