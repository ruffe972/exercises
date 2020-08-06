#![allow(non_snake_case)]

mod debug;
use debug::*;
use std::collections::HashSet;

fn main() {
    let mut all_statements = vec!();
    let mut all_operands = vec!();
    let string = std::fs::read_to_string("operands_and_statements.txt").unwrap();
    let lines = string.split('\n');
    for line in lines {
        let sep_pos = line.find('`').unwrap();
        let mut statements: Vec<_> = line[0 .. sep_pos]
            .split_whitespace()
            .collect();
        let mut operands: Vec<_> = line[sep_pos + 1 .. line.len()]
            .split_whitespace()
            .collect();
        all_statements.append(&mut statements);
        all_operands.append(&mut operands);
    }
    let unique_statements: HashSet<_> = all_statements
        .iter()
        .collect();
    let unique_operands: HashSet<_> = all_operands
        .iter()
        .collect();
    let n1 = unique_statements.len() as f64;
    println!("n1 = {}", n1);
    let n2 = unique_operands.len() as f64;
    println!("n2 = {}", n2);
    let N1 = all_statements.len() as f64;
    println!("N1 = {}", N1);
    let N2 = all_operands.len() as f64;
    println!("N2 = {}", N2);
    let n = n1 + n2;
    println!("n = {}", n);
    let N = N1 + N2;
    println!("N = {}", N);
    let V = (N * n.log2()).ceil();
    println!("V = {}", V);
    let N_cap = (n1 * n1.log2() + n2 * n2.log2()).ceil();
    println!("N^ = {}", N_cap);
    let L = 8.0 / V;
    println!("L = {}", L);
    let L_cap = 2.0 * n2 / (n1 * N2);
    println!("L^ = {}", L_cap);
    let I = L_cap * V;
    println!("I = {}", I);
    let E = (N_cap * (n / L).log2()).ceil();
    println!("E = {}", E);
}