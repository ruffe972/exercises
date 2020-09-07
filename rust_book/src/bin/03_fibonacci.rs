fn generate_fibonacci(n: u32) -> u128 {
    if n == 0 {
        0
    } else {
        let mut previous = generate_fibonacci(0);
        let mut current = 1;
        for _ in 2..=n {
            let next = previous + current;
            previous = current;
            current = next;
        }
        current
    }
}

fn main() {
    for i in (0..100).rev() {
        println!("F_{} = {}", i, generate_fibonacci(i));
    }
}