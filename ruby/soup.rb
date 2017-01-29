#!/usr/bin/env ruby -I .
require 'controllers'
require 'vendor1'


def run_devices(init1, init2, param)
  vendor1 = Vendor1

  devA = vendor1.createDeviceA(1)
  devB = vendor1.createDeviceB(2)

  ctlA = ControllerA.new(devA)
  ctlB = ControllerB.new(devB)

  ctlA.foo(init1)
  ctlB.foo(init2)
  ctlB.run( ctlA.run(param) )
end


if __FILE__ == $0
  x = run_devices(13, 15, 42)
  puts x
end
