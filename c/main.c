#include <stdlib.h>
#include <stdio.h>
#include "vendor.h"
#include "controllers.c"
#include "vendor1.c"


int RunDevices(int init1, int init2, int param) {
  Vendor *vendor1 = Vendor1_Initialize();

  DeviceA* devA = vendor1->createDeviceA(vendor1, 1);
  DeviceB* devB = vendor1->createDeviceB(vendor1, 2);

  ControllerA_foo(devA, init1);
  ControllerB_foo(devB, init2);

  int x = ControllerA_run(devA, param);
  int res = ControllerB_run(devB, x);

  vendor1->deleteDeviceA(vendor1, devA);
  vendor1->deleteDeviceB(vendor1, devB);

  Vendor1_Deinitialize(vendor1);

  return res;
}


int main (int argc, char* argv[]) {

  int x = RunDevices(13, 15, 42);
  printf("%d\n", x);

  return 0;
}
