#include <stdlib.h>


typedef struct {
  char type;
  int x;
} Vendor1Device;


typedef struct {
  DeviceA base;
  Vendor1Device vendor;
} Vendor1DeviceA;

typedef struct {
  DeviceB base;
  Vendor1Device vendor;
} Vendor1DeviceB;


void Vendor1_DeviceA_Op1 (Vendor1DeviceA* hd, int param) {
  Vendor1Device* dev = &hd->vendor;
  dev->x = param;
}

int Vendor1_DeviceA_Op2 (Vendor1DeviceA* hd, int x) {
  Vendor1Device* dev = &hd->vendor;
  return ++dev->x;
}


void Vendor1_DeviceB_Op1 (Vendor1DeviceB* hd, int param) {
  Vendor1Device* dev = &hd->vendor;
  dev->x *= param;
}

int Vendor1_DeviceB_Op2 (Vendor1DeviceB* hd, int x, int y) {
  Vendor1Device* dev = &hd->vendor;
  return dev->x * x + y;
}


DeviceA*
Vendor1_GetDeviceADriver(Vendor* vendor, int index) {
  DeviceA base = {
    { (void (*)(Device*, int)) Vendor1_DeviceA_Op1 },
    (int (*)(DeviceA*, int)) Vendor1_DeviceA_Op2,
  };

  Vendor1Device v = {
    'A',
    index,
  };

  Vendor1DeviceA res = { base, v };

  Vendor1DeviceA* dev = calloc(1, sizeof(Vendor1DeviceA));
  *dev = res;
  return &dev->base;
}

DeviceB*
Vendor1_GetDeviceBDriver(Vendor* vendor, int index) {
  DeviceB base = {
    { (void (*)(Device*, int)) Vendor1_DeviceB_Op1 },
    (int (*)(DeviceB*, int, int)) Vendor1_DeviceB_Op2,
  };

  Vendor1Device v = {
    'B',
    index,
  };

  Vendor1DeviceB res = { base, v };

  Vendor1DeviceB* dev = calloc(1, sizeof(Vendor1DeviceB));
  *dev = res;
  return &dev->base;
}


void
Vendor1_DeleteDeviceADriver(Vendor* vendor, DeviceA* drv) {
  Vendor1DeviceA* dev = (Vendor1DeviceA*)drv;
  free(dev);
}

void
Vendor1_DeleteDeviceBDriver(Vendor* vendor, DeviceB* drv) {
  Vendor1DeviceB* dev = (Vendor1DeviceB*)drv;
  free(dev);
}


Vendor*
Vendor1_Initialize() {
  Vendor res = {
    Vendor1_GetDeviceADriver,
    Vendor1_GetDeviceBDriver,
    Vendor1_DeleteDeviceADriver,
    Vendor1_DeleteDeviceBDriver,
  };

  Vendor* v = calloc(1, sizeof(Vendor));
  *v = res;
  return v;
}

void
Vendor1_Deinitialize(Vendor* v) {
  free(v);
}
