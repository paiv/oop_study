
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
      x = param
    }

    func op2(param: Int) -> Int {
      x += 1
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
      self.x = self.x * x + y
      return self.x
    }
  }
}

// type erasure; see http://stackoverflow.com/a/37360490

#if false

struct ControllerOps {
  let dev: Device
  func op1(param: Int) -> Void {
    dev.op1(param: param * param)
  }
}

protocol Controller {
  var ops: ControllerOps { get }
}

#else

struct ControllerOps : Device {
  let dev: Device
  func op1(param: Int) -> Void {
    dev.op1(param: param * param)
  }
}

protocol Controller {
  associatedtype DeviceType: Device
  var ops: DeviceType { get }
}

#endif

extension Controller {
  func foo(param: Int) {
    ops.op1(param: param)
  }
}


class ControllerA : Controller {
  let dev: DeviceA
  let ops: ControllerOps

  init(dev: DeviceA) {
    self.dev = dev
    ops = ControllerOps(dev: dev)
  }

  func run(param: Int) -> Int {
    return dev.op2(param: param)
  }
}


class ControllerB : Controller {
  let dev: DeviceB
  let ops: ControllerOps

  init(dev: DeviceB) {
    self.dev = dev
    ops = ControllerOps(dev: dev)
  }

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
