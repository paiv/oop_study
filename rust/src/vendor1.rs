
use soup;


pub struct Vendor1 {}

struct Vendor1DeviceA {
    x: i32
}

struct Vendor1DeviceB {
    x: i32
}


impl Vendor1DeviceA {
    fn new(index: i32) -> Vendor1DeviceA {
        Vendor1DeviceA { x: index }
    }
}


impl soup::Device for Vendor1DeviceA {

    fn op1(&mut self, param: i32) {
        self.x = param
    }
}


impl soup::DeviceA for Vendor1DeviceA {

    fn op2(&mut self, _: i32) -> i32 {
        self.x += 1;
        self.x
    }
}


impl Vendor1DeviceB {
    fn new(index: i32) -> Vendor1DeviceB {
        Vendor1DeviceB { x: index }
    }
}


impl soup::Device for Vendor1DeviceB {

    fn op1(&mut self, param: i32) {
        self.x *= param
    }
}


impl soup::DeviceB for Vendor1DeviceB {

    fn op2(&mut self, x: i32, y: i32) -> i32 {
        self.x * x + y
    }
}


impl soup::Vendor for Vendor1 {

    fn create_devicea(&self, index: i32) -> Box<soup::DeviceA + 'static> {
        Box::new(Vendor1DeviceA::new(index))
    }

    fn create_deviceb(&self, index: i32) -> Box<soup::DeviceB + 'static> {
        Box::new(Vendor1DeviceB::new(index))
    }
}
