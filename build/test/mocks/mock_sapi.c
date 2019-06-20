/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_sapi.h"

static const char* CMockString_dataToReadBuffer = "dataToReadBuffer";
static const char* CMockString_dataToReadBufferSize = "dataToReadBufferSize";
static const char* CMockString_i2cNumber = "i2cNumber";
static const char* CMockString_i2cRead = "i2cRead";
static const char* CMockString_i2cSlaveAddress = "i2cSlaveAddress";
static const char* CMockString_receiveDataBuffer = "receiveDataBuffer";
static const char* CMockString_receiveDataBufferSize = "receiveDataBufferSize";
static const char* CMockString_sendReadStop = "sendReadStop";
static const char* CMockString_sendWriteStop = "sendWriteStop";

typedef struct _CMOCK_i2cRead_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_i2cNumber;
  uint8_t Expected_i2cSlaveAddress;
  uint8_t* Expected_dataToReadBuffer;
  uint16_t Expected_dataToReadBufferSize;
  uint8_t Expected_sendWriteStop;
  uint8_t* Expected_receiveDataBuffer;
  uint16_t Expected_receiveDataBufferSize;
  uint8_t Expected_sendReadStop;

} CMOCK_i2cRead_CALL_INSTANCE;

static struct mock_sapiInstance
{
  int i2cRead_IgnoreBool;
  uint8_t i2cRead_FinalReturn;
  CMOCK_i2cRead_CALLBACK i2cRead_CallbackFunctionPointer;
  int i2cRead_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE i2cRead_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_sapi_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.i2cRead_IgnoreBool)
    Mock.i2cRead_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_i2cRead);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.i2cRead_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.i2cRead_CallbackFunctionPointer != NULL)
    Mock.i2cRead_CallInstance = CMOCK_GUTS_NONE;
}

void mock_sapi_Init(void)
{
  mock_sapi_Destroy();
}

void mock_sapi_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.i2cRead_CallbackFunctionPointer = NULL;
  Mock.i2cRead_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint8_t i2cRead(uint8_t i2cNumber, uint8_t i2cSlaveAddress, uint8_t* dataToReadBuffer, uint16_t dataToReadBufferSize, uint8_t sendWriteStop, uint8_t* receiveDataBuffer, uint16_t receiveDataBufferSize, uint8_t sendReadStop)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_i2cRead_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_i2cRead);
  cmock_call_instance = (CMOCK_i2cRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.i2cRead_CallInstance);
  Mock.i2cRead_CallInstance = CMock_Guts_MemNext(Mock.i2cRead_CallInstance);
  if (Mock.i2cRead_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.i2cRead_FinalReturn;
    Mock.i2cRead_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.i2cRead_CallbackFunctionPointer != NULL)
  {
    return Mock.i2cRead_CallbackFunctionPointer(i2cNumber, i2cSlaveAddress, dataToReadBuffer, dataToReadBufferSize, sendWriteStop, receiveDataBuffer, receiveDataBufferSize, sendReadStop, Mock.i2cRead_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_i2cNumber);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_i2cNumber, i2cNumber, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_i2cSlaveAddress);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_i2cSlaveAddress, i2cSlaveAddress, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_dataToReadBuffer);
    if (cmock_call_instance->Expected_dataToReadBuffer == NULL)
      { UNITY_TEST_ASSERT_NULL(dataToReadBuffer, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_dataToReadBuffer, dataToReadBuffer, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_dataToReadBufferSize);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_dataToReadBufferSize, dataToReadBufferSize, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_sendWriteStop);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_sendWriteStop, sendWriteStop, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_receiveDataBuffer);
    if (cmock_call_instance->Expected_receiveDataBuffer == NULL)
      { UNITY_TEST_ASSERT_NULL(receiveDataBuffer, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_receiveDataBuffer, receiveDataBuffer, 1, cmock_line, CMockStringMismatch); }
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_receiveDataBufferSize);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_receiveDataBufferSize, receiveDataBufferSize, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_i2cRead,CMockString_sendReadStop);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_sendReadStop, sendReadStop, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_i2cRead(CMOCK_i2cRead_CALL_INSTANCE* cmock_call_instance, uint8_t i2cNumber, uint8_t i2cSlaveAddress, uint8_t* dataToReadBuffer, uint16_t dataToReadBufferSize, uint8_t sendWriteStop, uint8_t* receiveDataBuffer, uint16_t receiveDataBufferSize, uint8_t sendReadStop)
{
  cmock_call_instance->Expected_i2cNumber = i2cNumber;
  cmock_call_instance->Expected_i2cSlaveAddress = i2cSlaveAddress;
  cmock_call_instance->Expected_dataToReadBuffer = dataToReadBuffer;
  cmock_call_instance->Expected_dataToReadBufferSize = dataToReadBufferSize;
  cmock_call_instance->Expected_sendWriteStop = sendWriteStop;
  cmock_call_instance->Expected_receiveDataBuffer = receiveDataBuffer;
  cmock_call_instance->Expected_receiveDataBufferSize = receiveDataBufferSize;
  cmock_call_instance->Expected_sendReadStop = sendReadStop;
}

void i2cRead_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_i2cRead_CALL_INSTANCE));
  CMOCK_i2cRead_CALL_INSTANCE* cmock_call_instance = (CMOCK_i2cRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.i2cRead_CallInstance = CMock_Guts_MemChain(Mock.i2cRead_CallInstance, cmock_guts_index);
  Mock.i2cRead_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.i2cRead_IgnoreBool = (int)1;
}

void i2cRead_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t i2cNumber, uint8_t i2cSlaveAddress, uint8_t* dataToReadBuffer, uint16_t dataToReadBufferSize, uint8_t sendWriteStop, uint8_t* receiveDataBuffer, uint16_t receiveDataBufferSize, uint8_t sendReadStop, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_i2cRead_CALL_INSTANCE));
  CMOCK_i2cRead_CALL_INSTANCE* cmock_call_instance = (CMOCK_i2cRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.i2cRead_CallInstance = CMock_Guts_MemChain(Mock.i2cRead_CallInstance, cmock_guts_index);
  Mock.i2cRead_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_i2cRead(cmock_call_instance, i2cNumber, i2cSlaveAddress, dataToReadBuffer, dataToReadBufferSize, sendWriteStop, receiveDataBuffer, receiveDataBufferSize, sendReadStop);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void i2cRead_StubWithCallback(CMOCK_i2cRead_CALLBACK Callback)
{
  Mock.i2cRead_IgnoreBool = (int)0;
  Mock.i2cRead_CallbackFunctionPointer = Callback;
}
