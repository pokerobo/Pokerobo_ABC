#include "Pokerobo_DEV.h"

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
  return _strnlen(code, VENDOR_CODE_LENGTH);
}

char* VendorSignature::getVendorCode() {
  code[VENDOR_CODE_LENGTH] = '\0';
  return code;
}

int VendorSignature::getPhoneNumberLength() {
  return _strnlen(phoneNumber, PHONE_NUMBER_LENGTH);
}

char* VendorSignature::getPhoneNumber() {
  phoneNumber[PHONE_NUMBER_LENGTH] = '\0';
  return phoneNumber;
}

int UserInformation::getUserNameLength() {
  return _strnlen(userName, USER_NAME_LENGTH);
}

char* UserInformation::getUserName() {
  userName[USER_NAME_LENGTH] = '\0';
  return userName;
}
