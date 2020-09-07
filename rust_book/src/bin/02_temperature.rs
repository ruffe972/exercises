const CELSIUS_TO_FAHRENHEIT_OFFSET: i32 = 32;
const CELSIUS_TO_FAHRENHEIT_MULTIPLIER: f64 = 1.8;

fn from_celsius_to_fahrenheit(celsius: f64) -> f64 {
    celsius * CELSIUS_TO_FAHRENHEIT_MULTIPLIER + CELSIUS_TO_FAHRENHEIT_OFFSET as f64
}

fn from_fahrenheit_to_celsius(fahrenheit: f64) -> f64 {
    (fahrenheit - CELSIUS_TO_FAHRENHEIT_OFFSET as f64) / CELSIUS_TO_FAHRENHEIT_MULTIPLIER
}

fn main() {
    let some_celsius_values = [-273.15, -40.0, 0.0, 37.0, 100.0];
    for &celsius in some_celsius_values.iter() {
        println!("{} °C = {} °F", celsius, from_celsius_to_fahrenheit(celsius));
    }
    let some_fahrenheit_values = [-459.67, -40.0, 32.0, 98.6, 212.0];
    for &fahrenheit in some_fahrenheit_values.iter() {
        println!("{} °F = {} °C", fahrenheit, from_fahrenheit_to_celsius(fahrenheit));
    }
}
