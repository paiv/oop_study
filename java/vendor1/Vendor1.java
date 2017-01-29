package vendor1;

import soup.*;


public class Vendor1 implements Vendor {

  public DeviceA createDeviceA(int index) {
    return new Vendor1DeviceA(index);
  }

  public DeviceB createDeviceB(int index) {
    return new Vendor1DeviceB(index);
  }

  class Vendor1Device {
    int x;
  }

  class Vendor1DeviceA extends Vendor1Device implements DeviceA {
    public Vendor1DeviceA(int index) { x = index; }
    public void op1(int param) { x += param; }
    public int op2(int param) { return x; }
  }

  class Vendor1DeviceB extends Vendor1Device implements DeviceB {
    public Vendor1DeviceB(int index) { x = index; }
    public void op1(int param) { x *= param; }
    public int op2(int x, int y) { return this.x * x + y; }
  }
}
