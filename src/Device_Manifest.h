#ifndef __POKEROBO_ABC_DEVICE_MANIFEST_H__
#define __POKEROBO_ABC_DEVICE_MANIFEST_H__

#include <Arduino.h>

class DeviceManifest {
  public:
    static uint8_t vendorCodeMaxLength;
    static uint8_t phoneNumberMaxLength;
    static uint8_t userNameMaxLength;

    DeviceManifest();
    bool available();
    uint16_t getHeader();
    uint16_t getDeviceId();

    int getVendorCodeLength();
    char* getVendorCode();

    int getPhoneNumberLength();
    char* getPhoneNumber();

    int getUserNameLength();
    char* getUserName();

    uint16_t getUserId();
};

#endif
