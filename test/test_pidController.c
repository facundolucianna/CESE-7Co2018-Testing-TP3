#include "unity.h"
#include "pidController.h"

static  int16_t errorPID = 0;
static  int16_t lastError = 0;
static  uint8_t heater = 2;
static  uint32_t Kp = 10;
static  float deltaT = 0.1;

void setUp(void)
{
  //Variable PID
  Kp = 10;
  deltaT = 0.1;
  errorPID = 4;
  lastError = 4;

}

void tearDown(void)
{
}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// negativa, el calefactor se debe apagar
void test_pidController_error_negative_heater_off(void)
{

    errorPID = -2;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_EQUAL_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender (cualquier valor posivo).
void test_pidController_error_positive_heater_on(void)
{

    errorPID = 4;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_GREATER_THAN_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender proporcional a error (Control P).
void test_pidController_error_positive_heater_proportional(void)
{

    errorPID = 4;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_EQUAL_UINT8(40, heater);

}

//Test a implementar, cuando el valor de calefacto supera el valor maximo, se
//satura al maximo valor.
void test_pidController_error_positive_heater_saturation(void)
{

    errorPID = 40;

    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_EQUAL_UINT8(0xFF, heater);

}

//Test a implementar, el controlPID debe calcular la derivada del error con
//un esquema upwinding ( (errorNew - errorLast)/deltaT )
void test_pidController_error_positive_heater_derivative_scheme(void)
{

    Kp = 0;
    lastError = 2;
    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_EQUAL_UINT8(20, heater);

}

//Test a implementar, luego de un bucle, el control PID debe almacenar el ultimo
//valor de error.
void test_pidController_error_positive_heater_last_error(void)
{

    lastError = 2;
    errorPID = 8;
    heater = PIDloop(errorPID, &lastError, Kp, deltaT);

    TEST_ASSERT_EQUAL_INT16(8, lastError);

}
