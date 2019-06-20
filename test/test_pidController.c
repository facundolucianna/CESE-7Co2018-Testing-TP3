#include "unity.h"
#include "pidController.h"
#include "mock_bmp180.h"

static  pid_variables_t PIDVariables;
static  int16_t errorPID = 0;
static  int16_t lastError = 0;
static  int32_t errorAcumulated = 0;
static  int32_t setpoint = 36;

static  int8_t allOk = 0;

static  uint8_t heater = 2;
static  uint32_t Kp = 10;
static  uint32_t Kd = 10;
static  uint32_t Ki = 0;
static  float deltaT = 0.1;

void setUp(void)
{
  //Variables PID
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

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// negativa, el calefactor se debe apagar
void test_pidController_error_negative_heater_off(void)
{

    errorPID = -2;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender (cualquier valor posivo).
void test_pidController_error_positive_heater_on(void)
{

    errorPID = 4;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_GREATER_THAN_UINT8(0, heater);

}

// Test a implementar, cuando el error entre la SETPOINT y la temperatura medida es
// positivo, el calefactor se debe prender proporcional a error (Control P).
void test_pidController_error_positive_heater_proportional(void)
{

    errorPID = 4;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(40, heater);

}

//Test a implementar, cuando el valor de calefacto supera el valor maximo, se
//satura al maximo valor.
void test_pidController_error_positive_heater_saturation(void)
{

    errorPID = 40;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(0xFF, heater);

}

//Test a implementar, el controlPID debe calcular la derivada del error con
//un esquema upwinding ( (errorNew - errorLast)/deltaT )
void test_pidController_error_positive_heater_derivative_scheme(void)
{

    Kp = 0;
    Ki = 0;
    Kd = 1;

    lastError = 2;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(20, heater);

}

//Test a implementar, luego de un bucle, el control PID debe almacenar el ultimo
//valor de error.
void test_pidController_error_positive_heater_last_error(void)
{

    lastError = 2;
    errorPID = 8;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_INT16(8, lastError);

}

//Test a implementar, luego de un bucle, la derivada debe multiplicarse
//por su coeficiente y sumarse con el control proporcional (control derivativo)
void test_pidController_error_positive_derivative_control(void)
{

    Kp = 1;
    Kd = 10;
    Ki = 0;

    errorPID = 2;
    lastError = 1;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(102, heater);

}

//Test a implementar, luego de un bucle, la salida en el PD en el calefactor
//no debe ser negativa
void test_pidController_proportional_derivative_control_non_negative_output(void)
{

    Kp = 1;
    Kd = 10;
    Ki = 0;

    errorPID = 2;
    lastError = 6;

    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_UINT8(0, heater);

}

//Test a implementar, en cada bucle se debe ir acumulando el error historico
void test_pidController_sum_error(void)
{
    PIDInitVariables(&PIDVariables, Kp, Kd, Ki, deltaT);

    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);
    errorPID = -2;
    heater = PIDloop(errorPID, &lastError, &errorAcumulated, &PIDVariables);

    TEST_ASSERT_EQUAL_INT32(2, errorAcumulated);

}

//Test a implementar, en cada bucle se debe tener en cuenta la integral del error para
//calcula el calefactor
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

    TEST_ASSERT_EQUAL_UINT8(2, heater);

}

//Test a implementar, en cada bucle se debe tener en cuenta la componente integral
//del control PID
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

    TEST_ASSERT_EQUAL_UINT8(4, heater);

}

// El sistema realiza una lectura de la temperatura mediante el sensor de temp y
//calcula con la temperatura seteada para obtener el error
void test_pidController_calculate_error(void)
{

    setpoint = 36;
    //temperature = 32;

    //When
    bmp180ReadTemp_ExpectAndReturn(32); //Mock up of bmp180ReadTemp (not implemented yet)

    //Then
    allOk = obtain_error(&errorPID, setpoint);
    TEST_ASSERT_EQUAL_INT16(4, errorPID);

}

// El sistema realiza una lectura de la temperatura mediante el sensor de temp y
// el sensor esta desconectado
void test_pidController_sensor_disconnected(void)
{

    setpoint = 36;
    //temperature = 32;

    //When
    bmp180ReadTemp_ExpectAndReturn(BMP180_SENSOR_TURN_OFF); //Mock up of bmp180ReadTemp (not implemented yet)

    //Then
    allOk = obtain_error(&errorPID, setpoint);
    TEST_ASSERT_EQUAL_INT8(BMP180_SENSOR_TURN_OFF, allOk);

}
