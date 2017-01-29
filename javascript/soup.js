var Vendor1 = require('./vendor1')


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
