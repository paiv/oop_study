
protocol Device {
  func op1(param: Int) -> Void
}

protocol DeviceA : Device {
  func op2(param: Int) -> Int
}

protocol DeviceB : Device {
  func op2(x: Int, y: Int) -> Int
}

protocol Vendor {
  func createDeviceA(index: Int) -> DeviceA
  func createDeviceB(index: Int) -> DeviceB
}


class Vendor1 : Vendor {
  func createDeviceA(index: Int) -> DeviceA {
    return Vendor1DeviceA(index: index)
  }

  func createDeviceB(index: Int) -> DeviceB {
    return Vendor1DeviceB(index: index)
  }

  class Vendor1DeviceA : DeviceA {
    var x: Int = 0

    init(index: Int) {
      x = index
    }

    func op1(param: Int) -> Void {
      x += param
    }

    func op2(param: Int) -> Int {
      return x
    }
  }

  class Vendor1DeviceB : DeviceB {
    var x: Int = 0

    init(index: Int) {
      x = index
    }

    func op1(param: Int) -> Void {
      x *= param
    }

    func op2(x: Int, y: Int) -> Int {
      return self.x * x + y
    }
  }
}


protocol Controller {
  var device: Device { get }
}

extension Controller {
  func foo(param: Int) {
    device.op1(param: param * param)
  }
}


struct ControllerA : Controller {
  let dev: DeviceA

  var device: Device { get { return dev } }

  func run(param: Int) -> Int {
    return dev.op2(param: param)
  }
}


struct ControllerB : Controller {
  let dev: DeviceB

  var device: Device { get { return dev } }

  func run(param: Int) -> Int {
    return dev.op2(x: param, y: param)
  }
}


func RunDevices(init1: Int, init2: Int, param: Int) -> Int {
  let vendor1 = Vendor1()

  let devA = vendor1.createDeviceA(index: 1)
  let devB = vendor1.createDeviceB(index: 2)

  let ctlA = ControllerA(dev: devA)
  let ctlB = ControllerB(dev: devB)

  ctlA.foo(param: init1)
  ctlB.foo(param: init2)
  return ctlB.run(param: ctlA.run(param: param))
}


let res = RunDevices(init1: 13, init2: 15, param: 42)
print(res)
