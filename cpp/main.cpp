#include <iostream>
#include <memory>
#include "vendor.h"
#include "controllers.cpp"
#include "vendor1.cpp"
using namespace std;
using namespace soup;


int RunDevices(int init1, int init2, int param) {
  auto vendor1 = unique_ptr<Vendor>(Vendor1::GetVendor());

  auto devA = shared_ptr<DeviceA>( vendor1->createDeviceA(1) );
  auto devB = shared_ptr<DeviceB>( vendor1->createDeviceB(2) );

  auto ctlA = ControllerA(devA);
  auto ctlB = ControllerB(devB);

  ctlA.foo(init1);
  ctlB.foo(init2);
  return ctlB.run( ctlA.run(param) );
}


int main (int argc, char* argv[]) {

  int x = RunDevices(13, 15, 42);
  cout << x << endl;

  return 0;
}
