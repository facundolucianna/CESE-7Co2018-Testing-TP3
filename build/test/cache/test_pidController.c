#include "build/temp/_test_pidController.c"
#include "mock_bmp180.h"
#include "pidController.h"
#include "unity.h"


static pid_variables_t PIDVariables;

static int16_t errorPID = 0;

static int16_t lastError = 0;

static int32_t errorAcumulated = 0;

static int32_t setpoint = 36;



static int8_t allOk = 0;



static uint8_t heater = 2;

static uint32_t Kp = 10;

static uint32_t Kd = 10;

static uint32_t Ki = 0;

static float deltaT = 0.1;



void setUp(void)

{



  Kp = 10;

  Kd = 1;

  Ki = 0;

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



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_on(void)

{



    errorPID = 4;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), UNITY_GREATER_THAN, (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_proportional(void)

{



    errorPID = 4;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((40)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_saturation(void)

{



    errorPID = 40;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0xFF)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_derivative_scheme(void)

{



    Kp = 0;

    Ki = 0;

    Kd = 1;



    lastError = 2;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((20)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_error_positive_heater_last_error(void)

{



    lastError = 2;

    errorPID = 8;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((8)), (UNITY_INT)(UNITY_INT16)((lastError)), (

   ((void *)0)

   ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT16);



}







void test_pidController_error_positive_derivative_control(void)

{



    Kp = 1;

    Kd = 10;

    Ki = 0;



    errorPID = 2;

    lastError = 1;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((102)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_proportional_derivative_control_non_negative_output(void)

{



    Kp = 1;

    Kd = 10;

    Ki = 0;



    errorPID = 2;

    lastError = 6;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_UINT8);



}





void test_pidController_sum_error(void)

{

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    errorPID = -2;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((2)), (UNITY_INT)(UNITY_INT32)((errorAcumulated)), (

   ((void *)0)

   ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_INT32);



}







void test_pidController_integral_error(void)

{



    Kp = 0;

    Kd = 0;

    Ki = 1;

    errorPID = 4;

    lastError = 4;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    errorPID = 20;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    errorPID = 0;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((2)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(196), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_integral_control(void)

{

    Kp = 10;

    Kd = 0;

    Ki = 2;

    errorPID = 4;

    lastError = 2;



    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);



    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    errorPID = 20;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    errorPID = 0;

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((4)), (UNITY_INT)(UNITY_UINT8 )((heater)), (

   ((void *)0)

   ), (UNITY_UINT)(218), UNITY_DISPLAY_STYLE_UINT8);



}







void test_pidController_calculate_error(void)

{



    setpoint = 36;







    bmp180ReadTemp_CMockExpectAndReturn(231, 32);





    allOk = obtain_error(&errorPID, setpoint);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((4)), (UNITY_INT)(UNITY_INT16)((errorPID)), (

   ((void *)0)

   ), (UNITY_UINT)(235), UNITY_DISPLAY_STYLE_INT16);



}







void test_pidController_sensor_disconnected(void)

{



    setpoint = 36;







    bmp180ReadTemp_CMockExpectAndReturn(248, -1);





    allOk = obtain_error(&errorPID, setpoint);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((-1)), (UNITY_INT)(UNITY_INT8 )((allOk)), (

   ((void *)0)

   ), (UNITY_UINT)(252), UNITY_DISPLAY_STYLE_INT8);



}
