#ifndef _PIDCONTROLLER_H
#define _PIDCONTROLLER_H

#include <stdint.h>

uint8_t PIDloop(int16_t, int16_t *, uint32_t, float );

#endif // _PIDCONTROLLER_H