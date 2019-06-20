#ifndef _BMP180_H
#define _BMP180_H

/*==================[inclusiones]============================================*/
#include <stdint.h>

/*==================[macros]=================================================*/
#define BMP180_SENSOR_TURN_OFF -1
/*==================[tipos de datos declarados por el usuario]===============*/
/*==================[declaraciones de datos externos]========================*/
/*==================[declaraciones de funciones externas]====================*/

int16_t bmp180ReadTemp(void);

/*==================[fin del archivo]========================================*/
#endif // _BMP180_H
