#include "Pokerobo_Dev.h"

char* _sanitize(uint8_t* arr, uint16_t bound) {
  arr[bound] = '\0';
  for(uint16_t i=bound; i>= 0 && (arr[i] == 0xFF || arr[i] == 0); i--) {
    arr[i] = '\0';
  }
  return arr;
}

size_t _strnlen(const char * s, size_t len) {
  size_t i = 0;
  for ( ; i < len && s[i] != '\0'; ++i);
  return i;
}

uint16_t getDeviceSignatureIndex() {
  return EEPROM.length() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature);
}

uint16_t getVendorSignatureIndex() {
  return EEPROM.length() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature)
      - sizeof(VendorSignature);
}

uint16_t getUserInformationIndex() {
  return EEPROM.length() - RESERVED_BYTES_LENGTH
      - sizeof(DeviceSignature)
      - sizeof(VendorSignature)
      - sizeof(UserInformation);
}

int VendorSignature::getVendorCodeLength() {
  return _strnlen(getVendorCode(), VENDOR_CODE_LENGTH);
}

char* VendorSignature::getVendorCode() {
  return _sanitize(code, VENDOR_CODE_LENGTH);
}

int VendorSignature::getPhoneNumberLength() {
  return _strnlen(getPhoneNumber(), PHONE_NUMBER_LENGTH);
}

char* VendorSignature::getPhoneNumber() {
  return _sanitize(phoneNumber, PHONE_NUMBER_LENGTH);
}

int UserInformation::getUserNameLength() {
  return _strnlen(getUserName(), USER_NAME_LENGTH);
}

char* UserInformation::getUserName() {
  return _sanitize(userName, USER_NAME_LENGTH);
}
