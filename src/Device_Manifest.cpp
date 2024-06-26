#include "Pokerobo_DEV.h"
#include "Device_Manifest.h"
#include <EEPROM.h>

size_t _strnlen(const char * s, size_t len) {
  size_t i = 0;
  for ( ; i < len && s[i] != '\0'; ++i);
  return i;
}

UserInformation _userInformationObject;
VendorSignature _vendorSignatureObject;
DeviceSignature _deviceSignatureObject;

uint16_t getFirstIndex() {
  return EEPROM.length();
}

void loadDeviceSignature() {
  int stampAddr = getFirstIndex() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature);
  EEPROM.get(stampAddr, _deviceSignatureObject);
}

void loadVendorSignature() {
  int stampAddr = getFirstIndex() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature)
      - sizeof(VendorSignature);
  EEPROM.get(stampAddr, _vendorSignatureObject);
}

void loadUserInformation() {
  int stampAddr = getFirstIndex() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature)
      - sizeof(VendorSignature)
      - sizeof(UserInformation);
  EEPROM.get(stampAddr, _userInformationObject);
}

static uint8_t DeviceManifest::vendorCodeMaxLength = VENDOR_CODE_LENGTH;
static uint8_t DeviceManifest::phoneNumberMaxLength = PHONE_NUMBER_LENGTH;
static uint8_t DeviceManifest::userNameMaxLength = USER_NAME_LENGTH;

DeviceManifest::DeviceManifest() {
  loadDeviceSignature();
  loadVendorSignature();
  loadUserInformation();
}

bool DeviceManifest::available() {
  return _deviceSignatureObject.header != 0;
}

uint16_t DeviceManifest::getHeader() {
  return _deviceSignatureObject.header;
}

uint16_t DeviceManifest::getDeviceId() {
  return _deviceSignatureObject.deviceId;
}

int DeviceManifest::getVendorCodeLength() {
  return _strnlen(_vendorSignatureObject.code, VENDOR_CODE_LENGTH);
}

char* DeviceManifest::getVendorCode() {
  _vendorSignatureObject.code[VENDOR_CODE_LENGTH] = '\0';
  return _vendorSignatureObject.code;
}

int DeviceManifest::getPhoneNumberLength() {
  return _strnlen(_vendorSignatureObject.phoneNumber, PHONE_NUMBER_LENGTH);
}

char* DeviceManifest::getPhoneNumber() {
  _vendorSignatureObject.phoneNumber[PHONE_NUMBER_LENGTH] = '\0';
  return _vendorSignatureObject.phoneNumber;
}

uint16_t DeviceManifest::getUserId() {
  return _userInformationObject.userId;
}

int DeviceManifest::getUserNameLength() {
  return _strnlen(_userInformationObject.userName, USER_NAME_LENGTH);
}

char* DeviceManifest::getUserName() {
  _userInformationObject.userName[USER_NAME_LENGTH] = '\0';
  return _userInformationObject.userName;
}
