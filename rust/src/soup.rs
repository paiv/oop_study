
pub trait Device {
    fn op1(&mut self, param: i32);
}


pub trait DeviceA : Device {
    fn op2(&mut self, param: i32) -> i32;
}


pub trait DeviceB : Device {
    fn op2(&mut self, x: i32, y: i32) -> i32;
}


pub trait Vendor {
    fn create_devicea(&self, index: i32) -> Box<DeviceA + 'static>;
    fn create_deviceb(&self, index: i32) -> Box<DeviceB + 'static>;
}
