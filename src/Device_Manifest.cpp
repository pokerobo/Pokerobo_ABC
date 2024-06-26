#include "Device_Manifest.h"
#include "Pokerobo_Dev.h"

UserInformation _userInformationObject;
VendorSignature _vendorSignatureObject;
DeviceSignature _deviceSignatureObject;

static uint8_t DeviceManifest::vendorCodeMaxLength = VENDOR_CODE_LENGTH;
static uint8_t DeviceManifest::phoneNumberMaxLength = PHONE_NUMBER_LENGTH;
static uint8_t DeviceManifest::userNameMaxLength = USER_NAME_LENGTH;

DeviceManifest::DeviceManifest() {
  loadManifest(getDeviceSignatureIndex(), _deviceSignatureObject);
  loadManifest(getVendorSignatureIndex(), _vendorSignatureObject);
  loadManifest(getUserInformationIndex(), _userInformationObject);
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
