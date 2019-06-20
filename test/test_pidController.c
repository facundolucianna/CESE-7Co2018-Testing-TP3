#include "unity.h"
#include "pidController.h"

static  int16_t errorPID = 0;
static  uint8_t heater = 2;
static  uint32_t Kp = 10;

void setUp(void)
{
  //Variable PID
  Kp = 10;
}

void tearDown(void)
{
}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// negativa, el calefactor se debe apagar
void test_pidController_error_negative_heater_off(void)
{

    errorPID = -2;

    heater = PIDloop(errorPID, Kp);

    TEST_ASSERT_EQUAL_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender (cualquier valor posivo).
void test_pidController_error_positive_heater_on(void)
{

    errorPID = 4;

    heater = PIDloop(errorPID, Kp);

    TEST_ASSERT_GREATER_THAN_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender proporcional a error (Control P).
void test_pidController_error_positive_heater_proportional(void)
{

    errorPID = 4;

    heater = PIDloop(errorPID, Kp);

    TEST_ASSERT_EQUAL_UINT8(40, heater);

}
