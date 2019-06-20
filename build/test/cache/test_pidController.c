#include "build/temp/_test_pidController.c"
#include "pidController.h"
#include "unity.h"


static int16_t errorPID = 0;

static uint8_t heater = 2;

static uint32_t Kp = 10;



void setUp(void)

{



  Kp = 10;

}



void tearDown(void)

{

}







void test_pidController_error_negative_heater_off(void)

{



    errorPID = -2;



    heater = PIDloop(errorPID, Kp);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_on(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, Kp);



    UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), UNITY_GREATER_THAN, (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_proportional(void)

{



    errorPID = 4;



    heater = PIDloop(errorPID, Kp);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((40)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_UINT8);



}
