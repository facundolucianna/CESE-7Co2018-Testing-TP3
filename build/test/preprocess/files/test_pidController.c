#include "build/temp/_test_pidController.c"
#include "pidController.h"
#include "unity.h"


static int16_t errorPID = 0;

static uint8_t heater = 2;



void setUp(void)

{

}



void tearDown(void)

{

}







void test_pidController_error_negative_heater_off(void)

{

    errorPID = -2;



    heater = PIDloop(errorPID);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);



}
