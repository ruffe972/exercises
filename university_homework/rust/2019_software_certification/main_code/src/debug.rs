use std::fmt::{Display, Debug};

#[allow(dead_code)]
pub fn d_print<T: Display>(object: &T) {
    println!("{}", object);
}

#[allow(dead_code)]
pub fn d_pretty<T: Debug>(object: &T) {
    println!("{:#?}", object);
}