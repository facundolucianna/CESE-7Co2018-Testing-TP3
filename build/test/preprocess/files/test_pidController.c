#include "build/temp/_test_pidController.c"
#include "pidController.h"
#include "unity.h"


static int16_t errorPID = 0;

static int16_t lastError = 0;

static int32_t errorAcumulated = 0;



static uint8_t heater = 2;

static uint32_t Kp = 10;

static uint32_t Kd = 10;

static float deltaT = 0.1;



void setUp(void)

{



  Kp = 10;

  Kd = 1;

  deltaT = 0.1;

  errorPID = 4;

  lastError = 4;

  errorAcumulated = 0;



}



void tearDown(void)

{

}







void test_pidController_error_negative_heater_off(void)

{



    errorPID = -2;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_on(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), UNITY_GREATER_THAN, (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_proportional(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((40)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_saturation(void)

{



    errorPID = 40;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0xFF)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_derivative_scheme(void)

{



    Kp = 0;

    lastError = 2;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((20)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_last_error(void)

{



    lastError = 2;

    errorPID = 8;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((8)), (UNITY_INT)(UNITY_INT16)((lastError)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT16);



}







void test_pidController_error_positive_derivative_control(void)

{

    Kp = 1;

    Kd = 10;

    errorPID = 2;

    lastError = 1;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((102)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_proportional_derivative_control_non_negative_output(void)

{

    Kp = 1;

    Kd = 10;

    errorPID = 2;

    lastError = 6;



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_UINT8);



}





void test_pidController_sum_error(void)

{



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);

    errorPID = -2;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, Kp, Kd, deltaT);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((2)), (UNITY_INT)(UNITY_INT32)((errorAcumulated)), (

   ((void *)0)

   ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT32);



}
