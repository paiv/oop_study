

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


class Controller {
  constructor(dev) { this.dev = dev }
  
  foo(param) {
    this.dev.op1(param * param)
  }
}

class ControllerA extends Controller {
  run(param) { return this.dev.op2(param) }
}

class ControllerB extends Controller {
  run(param) { return this.dev.op2(param, param) }
}


function deviceRunner(init1, init2, param) {
  var vendor1 = new Vendor1()

  var devA = vendor1.createDeviceA(1)
  var devB = vendor1.createDeviceB(2)

  var ctlA = new ControllerA(devA)
  var ctlB = new ControllerB(devB)

  ctlA.foo(init1)
  ctlB.foo(init2)
  return ctlB.run( ctlA.run(param) )
}

var x = deviceRunner(13, 15, 42)
console.log(x)
