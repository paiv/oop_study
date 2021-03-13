
use soup;


pub struct Controller<'a, T> where T: 'a + soup::Device {
    dev: &'a mut T,
}

impl<'a, T> Controller<'a, T> where T: soup::Device {
    fn foo(&mut self, param: i32) {
        self.dev.op1(param * param)
    }
}


pub struct ControllerA<'a> {
    base: Controller<'a, soup::DeviceA>,
}


impl<'a> ControllerA<'a> {
    pub fn new(dev: &mut soup::DeviceA) -> ControllerA {
        ControllerA { dev: dev }
    }

    // pub fn foo(&mut self, param: i32) {
    //     self.dev.op1(param * param)
    // }

    pub fn run(&mut self, param: i32) -> i32 {
        self.dev.op2(param)
    }
}


pub struct ControllerB<'a> {
    dev: &'a mut soup::DeviceB,
}

impl<'a> ControllerB<'a> {
    pub fn new(dev: &mut soup::DeviceB) -> ControllerB {
        ControllerB { dev: dev }
    }

    pub fn foo(&mut self, param: i32) {
        self.dev.op1(param * param)
    }

    pub fn run(&mut self, param: i32) -> i32 {
        self.dev.op2(param, param)
    }
}
