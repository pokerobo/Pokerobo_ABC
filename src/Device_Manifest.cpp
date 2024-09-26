#include "Device_Manifest.h"
#include "Pokerobo_Dev.h"

UserInformation _userInformationObject;
VendorSignature _vendorSignatureObject;
DeviceSignature _deviceSignatureObject;

uint8_t DeviceManifest::vendorCodeMaxLength = VENDOR_CODE_LENGTH;
uint8_t DeviceManifest::phoneNumberMaxLength = PHONE_NUMBER_LENGTH;
uint8_t DeviceManifest::userNameMaxLength = USER_NAME_LENGTH;

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
  return _vendorSignatureObject.getVendorCodeLength();
}

char* DeviceManifest::getVendorCode() {
  return _vendorSignatureObject.getVendorCode();
}

int DeviceManifest::getPhoneNumberLength() {
  return _vendorSignatureObject.getPhoneNumberLength();
}

char* DeviceManifest::getPhoneNumber() {
  return _vendorSignatureObject.getPhoneNumber();
}

uint16_t DeviceManifest::getUserId() {
  return _userInformationObject.userId;
}

int DeviceManifest::getUserNameLength() {
  return _userInformationObject.getUserNameLength();
}

char* DeviceManifest::getUserName() {
  return _userInformationObject.getUserName();
}
