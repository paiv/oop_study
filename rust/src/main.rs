
mod soup;
mod controllers;
mod vendor1;

use controllers::*;


fn run_devices(vendor: &mut soup::Vendor, init1: i32, init2: i32, param: i32) -> i32 {
    let mut deva = vendor.create_devicea(1);
    let mut devb = vendor.create_deviceb(2);

    let mut ctla = ControllerA::new(&mut *deva);
    let mut ctlb = ControllerB::new(&mut *devb);

    ctla.foo(init1);
    ctlb.foo(init2);

    ctlb.run( ctla.run(param) )
}


fn main() {
    let mut vendor1 = vendor1::Vendor1 {};
    let x = run_devices(&mut vendor1, 13, 15, 42);
    println!("{}", x);
}
