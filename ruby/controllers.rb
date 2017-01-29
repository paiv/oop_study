

module ControllerOps
  def foo(param)
    @dev.op1(param * param)
  end
end


class ControllerA
  include ControllerOps

  def initialize(dev)
    @dev = dev
  end

  def run(param)
    @dev.op2(param)
  end
end


class ControllerB
  include ControllerOps

  def initialize(dev)
    @dev = dev
  end

  def run(param)
    @dev.op2(param, param)
  end
end
