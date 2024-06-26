#ifndef __POKEROBO_ABC_DEVICE_STRUCTURE_H__
#define __POKEROBO_ABC_DEVICE_STRUCTURE_H__

#include <Arduino.h>

#define USER_NAME_LENGTH            16
#define PHONE_NUMBER_LENGTH         15
#define VENDOR_CODE_LENGTH          20

#define RESERVED_BYTES_LENGTH        4

// 19 = 2 + 16 + 1
typedef struct {
  char userName[USER_NAME_LENGTH + 1];
  uint16_t userId = 0;
} UserInformation;

// 37 = 15 + 1 + 20 + 1
typedef struct {
  char phoneNumber[PHONE_NUMBER_LENGTH + 1];
  char code[VENDOR_CODE_LENGTH + 1];
} VendorSignature;

// 4 = 2 + 2
typedef struct {
  uint16_t deviceId = 0;
  uint16_t header = 0;
} DeviceSignature;

// total: 60 = 19 + 37 + 4

#endif
