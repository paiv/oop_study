from soup import Vendor, DeviceA, DeviceB


class Vendor1(Vendor):

    class Vendor1DeviceA(DeviceA):
        def __init__(self, index):
            self.x = index

        def op1(self, param):
            self.x = param

        def op2(self, param):
            self.x += 1
            return self.x

    class Vendor1DeviceB(DeviceB):
        def __init__(self, index):
            self.x = index

        def op1(self, param):
            self.x *= param

        def op2(self, x, y):
            return self.x * x + y

    def createDeviceA(self, index):
        return self.Vendor1DeviceA(index)

    def createDeviceB(self, index):
        return self.Vendor1DeviceB(index)
