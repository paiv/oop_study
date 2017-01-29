import soup.*;
import vendor1.Vendor1;


interface Controller {
  Device getDevice();

  default void foo(int param) {
    getDevice().op1(param * param);
  }
}


class ControllerA implements Controller {
  DeviceA dev;

  public ControllerA(DeviceA dev) {
    this.dev = dev;
  }

  public DeviceA getDevice() { return dev; }

  int run(int param) {
    return dev.op2(param);
  }
}


class ControllerB implements Controller {
  DeviceB dev;

  public ControllerB(DeviceB dev) {
    this.dev = dev;
  }

  public DeviceB getDevice() { return dev; }

  int run(int param) {
    return dev.op2(param, param);
  }
}


class Runner {
  public int runDevices(int init1, int init2, int param) {
    Vendor vendor1 = new Vendor1();

    DeviceA devA = vendor1.createDeviceA(1);
    DeviceB devB = vendor1.createDeviceB(2);

    ControllerA ctlA = new ControllerA(devA);
    ControllerB ctlB = new ControllerB(devB);

    ctlA.foo(init1);
    ctlB.foo(init2);
    return ctlB.run( ctlA.run(param) );
  }
}


class soup {

  public static void main(String[] args) {

    int res = new Runner().runDevices(13, 15, 42);
    System.out.println(res);
  }
}
