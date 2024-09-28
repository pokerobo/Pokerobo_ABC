#ifndef __POKEROBO_ABC_DEVICE_STRUCT_H__
#define __POKEROBO_ABC_DEVICE_STRUCT_H__

#include <Arduino.h>
#include <EEPROM.h>

#define USER_NAME_LENGTH            16
#define PHONE_NUMBER_LENGTH         15
#define VENDOR_CODE_LENGTH          20
#define RESERVED_BYTES_LENGTH        4

// 19 = 16 + 1 + 2
struct UserInformation {
  char userName[USER_NAME_LENGTH + 1];
  uint16_t userId = 0;

  int getUserNameLength();
  char* getUserName();
};

// 37 = 15 + 1 + 20 + 1
struct VendorSignature {
  char phoneNumber[PHONE_NUMBER_LENGTH + 1];
  char code[VENDOR_CODE_LENGTH + 1];

  int getVendorCodeLength();
  char* getVendorCode();
  int getPhoneNumberLength();
  char* getPhoneNumber();
};

// 4 = 2 + 2
struct DeviceSignature {
  uint16_t deviceId = 0;
  uint16_t header = 0;
};

// total: 60 = 19 + 37 + 4

uint16_t getDeviceSignatureIndex();
uint16_t getVendorSignatureIndex();
uint16_t getUserInformationIndex();

template<typename T> T &loadManifest(uint16_t idx, T &t){
    return EEPROM.get(idx, t);
}

template<typename T> const T &saveManifest(uint16_t idx, const T &t){
    return EEPROM.put(idx, t);
}

size_t _strnlen(const char * s, size_t len);

#endif//__POKEROBO_ABC_DEVICE_STRUCT_H__
