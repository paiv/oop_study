

object soup {

    trait Device {
        def op1(param: Int)
    }

    trait DeviceA extends Device {
        def op2(param: Int): Int
    }

    trait DeviceB extends Device {
        def op2(x: Int, y: Int): Int
    }

    trait Vendor {
        def createDeviceA(index: Int): DeviceA
        def createDeviceB(index: Int): DeviceB
    }
}


object control {
    import soup._

    trait Controller[T <: Device] {
        val dev: T
        def foo(param: Int) {
            dev.op1(param * param)
        }
    }

    class ControllerA(val dev: DeviceA) extends Controller[DeviceA] {
        def run(param: Int): Int = {
            dev.op2(param)
        }
    }

    class ControllerB(val dev: DeviceB) extends Controller[DeviceB] {
        def run(param: Int): Int = {
            dev.op2(param, param)
        }
    }
}


object vendor1 {
    import soup._

    class Vendor1DeviceA(var x: Int) extends DeviceA {
        def op1(param: Int): Unit = { x = param }
        def op2(param: Int): Int = { x += 1; x }
    }

    class Vendor1DeviceB(var x: Int) extends DeviceB {
        def op1(param: Int): Unit = { x *= param }
        def op2(x: Int, y: Int): Int = { this.x * x + y }
    }

    class Vendor1 extends Vendor {
        def createDeviceA(index: Int): DeviceA = new Vendor1DeviceA(index)
        def createDeviceB(index: Int): DeviceB = new Vendor1DeviceB(index)
    }
}



object runner {
    import control._


    def run_devices(init1: Int, init2: Int, param: Int): Int = {
        val v1 = new vendor1.Vendor1()
        val devA = v1.createDeviceA(1)
        val devB = v1.createDeviceB(2)

        val ctlA = new ControllerA(devA)
        val ctlB = new ControllerB(devB)

        ctlA.foo(init1)
        ctlB.foo(init2)
        ctlB.run( ctlA.run(param) )
    }

    def main(args: Array[String]) = {
        val x = runner.run_devices(13, 15, 42)
        println(x)
    }
}
