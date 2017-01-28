from abc import ABCMeta, abstractmethod

class Device(metaclass=ABCMeta):
    @abstractmethod
    def op1(self, param):
        pass


class DeviceA(Device, metaclass=ABCMeta):
    @abstractmethod
    def op2(self, param):
        pass


class DeviceB(Device, metaclass=ABCMeta):
    @abstractmethod
    def op2(self, x, y):
        pass


class Vendor(metaclass=ABCMeta):
    @abstractmethod
    def createDeviceA(self, index):
        pass

    @abstractmethod
    def createDeviceB(self, index):
        pass
