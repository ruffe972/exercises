use crate::solve;
use std::iter;
use nalgebra as na;
use na::{DMatrix, DVector};

// Row-major order.
fn compare<I, J>(n: usize, system: I, solution: J)
where
    I: IntoIterator<Item = f64>,
    J: IntoIterator<Item = f64>
{
    let system = DMatrix::from_iterator(n + 1, n, system).transpose();
    let solution = DVector::from_iterator(n, solution);
    assert_eq!(solve(&system), solution);
}

#[test]
fn dim_1_a() {
    compare(
        1,
        vec!(-3.0, 0.0),
        vec!(0.0)
    );
}

#[test]
fn dim_1_b() {
    compare(
        1,
        vec!(-3.0, 6.0),
        vec!(-2.0)
    );
}

#[test]
fn dim_2() {
    compare(
        2,
        vec!(
            0.0, -0.6, -1.2,
            0.3, 0.0, 1.2
        ),
        vec!(4.0, 2.0)
    );
}

#[test]
fn dim_3_a() {
    compare(
        3,
        vec!(
            1.0, 1.0, 1.0, 6.0,
            1.0, -1.0, 2.0, 5.0,
            2.0, -1.0, -1.0, -3.0
        ),
        vec!(1.0, 2.0, 3.0)
    );
}

#[test]
fn dim_3_b() {
    compare(
        3,
        vec!(
            2.0, 1.0, -1.0, 8.0,
            -3.0, -1.0, 2.0, -11.0,
            -2.0, 1.0, 2.0, -3.0
        ),
        vec!(2.0, 3.0, -1.0)
    );
}

#[test]
fn dim_100() {
    const N: usize = 100;
    let mut system: DMatrix<f64> = DMatrix::zeros(N + 1, N);
    for i in 0 .. N {
        system[(N - i - 1, i)] = 1.0;
    }
    compare(
        N,
        system.iter().cloned(),
        iter::repeat(0.0).take(N)
    )
}