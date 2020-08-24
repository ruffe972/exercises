mod tests;
mod debug;
use debug::*;

// Main program start

use nalgebra as na;
use na::DMatrix;
use na::DVector;

fn read_matrix() -> DMatrix<f64> {
    let input = std::fs::read_to_string("input.txt").unwrap();
    let mut number_strings = input.split_whitespace();
    let n: usize = number_strings.next()
        .unwrap()
        .parse()
        .unwrap();
    let matrix_numbers = number_strings.map(|string|
        string.parse::<f64>().unwrap());
    let matrix = DMatrix::from_iterator(n + 1, n, matrix_numbers);
    matrix.transpose()
}

fn position_in_location<P>(
    matrix: &DMatrix<f64>,
    start: (usize, usize),
    shape: (usize, usize),
    predicate: P) -> (usize, usize)
    where P: FnMut(&f64) -> bool
{
    let pos = matrix.slice(start, shape)
        .iter()
        .position(predicate)
        .unwrap();  // position in flattened slice
    (start.0 + pos % shape.0, start.1 + pos / shape.0)
}

fn make_triangular(system: &mut DMatrix<f64>) {
    let n = system.nrows();
    for k in 0 .. n {
        // Swap rows to make system[(k, k)] != 0.
        let swap_i = position_in_location(
            system,
            (k, k),
            (n - k, 1),
            |&number| number != 0.0
        ).0;
        system.swap_rows(k, swap_i);

        system.set_row(k, &system.row(k)
            .map(|number| number / system[(k, k)])
        );

        for i in k + 1 .. n {
            system.set_row(i, &system.row(i).zip_map(
                &system.row(k),
                |x_i, x_k| x_i - x_k * system[(i, k)]
            ));
        }
    }
}

pub fn solve(system: &DMatrix<f64>) -> DVector<f64> {
    let mut system = system.clone();
    make_triangular(&mut system);
    let n = system.nrows();
    let mut solution = DVector::from_element(n, 0.0);
    for k in (0 .. n).rev() {
        solution[k] = 0.0;
        for j in 0 .. n {
            solution[k] -= solution[j] * system[(k, j)];
        }
        solution[k] += system[(k, n)];
    }
    solution
}

fn main() {
    let solution = solve(&read_matrix());
    for (i, number) in solution.iter().enumerate() {
        println!("x_{} = {}", i, number);
    }
}