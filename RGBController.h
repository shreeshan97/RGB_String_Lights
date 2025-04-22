#ifndef _RGBCONTROLLER_H_
#define _RGBCONTROLLER_H_

#include <SinricProDevice.h>
#include <Capabilities/ModeController.h>
#include <Capabilities/PowerStateController.h>

class RGBController 
: public SinricProDevice
, public ModeController<RGBController>
, public PowerStateController<RGBController> {
  friend class ModeController<RGBController>;
  friend class PowerStateController<RGBController>;
public:
  RGBController(const String &deviceId) : SinricProDevice(deviceId, "RGBController") {};
};

#endif
