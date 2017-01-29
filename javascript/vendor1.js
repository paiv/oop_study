
class Vendor1Device {
  constructor(index) { this.x = index }
}

class Vendor1DeviceA extends Vendor1Device {
  op1(param) { this.x += param }
  op2(param) { return this.x }
}

class Vendor1DeviceB extends Vendor1Device {
  op1(param) { this.x *= param }
  op2(x, y) { return this.x * x + y }
}

class Vendor1 {
  createDeviceA(index) { return new Vendor1DeviceA(index) }
  createDeviceB(index) { return new Vendor1DeviceB(index) }
}


module.exports = Vendor1
