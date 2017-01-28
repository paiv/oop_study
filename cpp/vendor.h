#pragma once

namespace soup {

  class Device {
  public:
    virtual ~Device() {}
    virtual void op1(int param) = 0;
  };

  class DeviceA : public Device {
  public:
    virtual int op2(int param) = 0;
  };

  class DeviceB : public Device {
  public:
    virtual int op2(int x, int y) = 0;
  };

  class Vendor {
  public:
    virtual ~Vendor() {}

    virtual DeviceA* createDeviceA(int index) = 0;
    virtual DeviceB* createDeviceB(int index) = 0;
  };

}
