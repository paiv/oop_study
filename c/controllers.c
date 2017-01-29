
void Controller_foo(Device* dev, int param) {
  dev->Op1(dev, param * param);
}

int ControllerA_run(DeviceA* devA, int param) {
  return devA->A_Op2(devA, param);
}

int ControllerB_run(DeviceB* devB, int param) {
  return devB->B_Op2(devB, param, param);
}
