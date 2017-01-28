
namespace Vendor1 {
  using namespace soup;

  typedef struct {
    char type;
    int x;
  } Vendor1Device;


  class Vendor1DeviceA : public DeviceA {
    Vendor1Device dev;
  public:
    Vendor1DeviceA(int index) : dev({'A', index}) {}

    virtual void op1(int param) {
      dev.x = param;
    }

    virtual int op2(int param) {
      return ++dev.x;
    }
  };

  class Vendor1DeviceB : public DeviceB {
    Vendor1Device dev;
  public:
    Vendor1DeviceB(int index) : dev({'B', index}) {}

    virtual void op1(int param) {
      dev.x *= param;
    }

    virtual int op2(int x, int y) {
      return dev.x * x + y;
    }
  };


  class Vendor1Vendor : public Vendor {
  public:
    virtual DeviceA* createDeviceA(int index) {
      return new Vendor1DeviceA(index);
    }

    virtual DeviceB* createDeviceB(int index) {
      return new Vendor1DeviceB(index);
    }
  };


  Vendor* GetVendor() {
    return new Vendor1Vendor();
  }

}
