#pragma once


typedef struct Device {
  void (*Op1)(struct Device*, int);
} Device;


typedef struct DeviceA {
  Device base;
  int (*A_Op2)(struct DeviceA*, int);
} DeviceA;


typedef struct DeviceB {
  Device base;
  int (*B_Op2)(struct DeviceB*, int, int);
} DeviceB;


typedef struct Vendor {
  DeviceA* (*createDeviceA)(struct Vendor*, int);
  DeviceB* (*createDeviceB)(struct Vendor*, int);
  void (*deleteDeviceA)(struct Vendor*, DeviceA*);
  void (*deleteDeviceB)(struct Vendor*, DeviceB*);
} Vendor;
