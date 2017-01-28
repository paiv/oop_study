
void ControllerA_foo(DeviceA* devA, int param) {
  Device* dev = (Device*)devA;
  dev->Op1(dev, param * param);
}

int ControllerA_run(DeviceA* devA, int param) {
  return devA->A_Op2(devA, param);
}

void ControllerB_foo(DeviceB* devB, int param) {
  Device* dev = (Device*)devB;
  dev->Op1(dev, param * param);
}

int ControllerB_run(DeviceB* devB, int param) {
  return devB->B_Op2(devB, param, param);
}
