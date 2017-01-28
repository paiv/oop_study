#!/usr/bin/env python3
from vendor1 import Vendor1


class ControllerOps:
    def foo(self, param):
        self.dev.op1(param * param)


class ControllerA(ControllerOps):
    def __init__(self, devA):
        self.dev = devA

    def run(self, param):
        return self.dev.op2(param)


class ControllerB(ControllerOps):
    def __init__(self, devB):
        self.dev = devB

    def run(self, param):
        return self.dev.op2(param, param)


def run_devices(init1, init2, param):
    vendor1 = Vendor1()
    devA = vendor1.createDeviceA(1)
    devB = vendor1.createDeviceB(2)

    ctlA = ControllerA(devA)
    ctlB = ControllerB(devB)

    ctlA.foo(init1)
    ctlB.foo(init2)
    return ctlB.run( ctlA.run(param) )


if __name__ == '__main__':
    x = run_devices(13, 15, 42)
    print(x)
