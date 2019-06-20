#include "build/temp/_test_pidController.c"
#include "pidController.h"
#include "unity.h"


static int16_t errorPID = 0;

static int16_t lastError = 0;

static uint8_t heater = 2;

static uint32_t Kp = 10;

static float deltaT = 0.1;



void setUp(void)

{



  Kp = 10;

  deltaT = 0.1;

  errorPID = 4;

  lastError = 4;



}



void tearDown(void)

{

}







void test_pidController_error_negative_heater_off(void)

{



    errorPID = -2;



    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_on(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), UNITY_GREATER_THAN, (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_proportional(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((40)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_saturation(void)

{



    errorPID = 40;



    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0xFF)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_derivative_scheme(void)

{



    Kp = 0;

    lastError = 2;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((20)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_last_error(void)

{



    lastError = 2;

    errorPID = 8;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((8)), (UNITY_INT)(UNITY_INT16)((lastError)), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT16);



}
