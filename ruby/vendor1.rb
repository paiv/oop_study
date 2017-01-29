

module Vendor1

  def Vendor1.createDeviceA(index)
    Vendor1DeviceA.new(index)
  end

  def Vendor1.createDeviceB(index)
    Vendor1DeviceB.new(index)
  end


  class Vendor1Device
    def initialize(index)
      @x = index
    end
  end

  class Vendor1DeviceA < Vendor1Device
    def op1(param)
      @x += param
    end

    def op2(param)
      @x
    end
  end

  class Vendor1DeviceB < Vendor1Device
    def op1(param)
      @x *= param
    end

    def op2(x, y)
      @x * x + y
    end
  end

end
