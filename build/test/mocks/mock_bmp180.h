/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_BMP180_H
#define _MOCK_BMP180_H

#include "bmp180.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_bmp180_Init(void);
void mock_bmp180_Destroy(void);
void mock_bmp180_Verify(void);




#define bmp180ReadTemp_IgnoreAndReturn(cmock_retval) bmp180ReadTemp_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void bmp180ReadTemp_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int16_t cmock_to_return);
#define bmp180ReadTemp_ExpectAndReturn(cmock_retval) bmp180ReadTemp_CMockExpectAndReturn(__LINE__, cmock_retval)
void bmp180ReadTemp_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int16_t cmock_to_return);
typedef int16_t (* CMOCK_bmp180ReadTemp_CALLBACK)(int cmock_num_calls);
void bmp180ReadTemp_StubWithCallback(CMOCK_bmp180ReadTemp_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
