
OOP Study
=========

Task
----

Make an app that controls two devices, `Device A` and `Device B`,
via corresponding controllers, `Controller A` and `Controller B`.
There might be many vendors for `Device A`, as well as for `Device B`.

Spec
----

Device A:
- op1(int)
- op2(int): int

Device B:
- op1(int)
- op2(int, int): int

Controller A:
- foo(param): device.op1(param * param)
- run(param): device.op2(param)

Controller B:
- foo(param): device.op1(param * param)
- run(param): device.op2(param, param)

App:
- controllerA.foo(13)
- controllerB.foo(15)
- controllerB.run( controllerA.run(42) )
