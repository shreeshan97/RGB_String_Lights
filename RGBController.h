#ifndef _RGBCONTROLLER_H_
#define _RGBCONTROLLER_H_

#include <SinricProDevice.h>
#include <Capabilities/ModeController.h>

class RGBController 
: public SinricProDevice
, public ModeController<RGBController> {
  friend class ModeController<RGBController>;
public:
  RGBController(const String &deviceId) : SinricProDevice(deviceId, "RGBController") {};
};

#endif