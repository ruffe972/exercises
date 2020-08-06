use itertools::Itertools;
use rand::thread_rng;
use rand::seq::SliceRandom;

enum Orientation {
    Horizontal,
    Vertical,
}

#[derive(Copy, Clone)]
struct CellPos {
    row: i32,
    col: i32,
}

type Row = [bool; U_FIELD_SIZE];
type Field = [Row; U_FIELD_SIZE];

const U_FIELD_SIZE: usize = 10;
const FIELD_SIZE: i32 = U_FIELD_SIZE as i32;
const SHIP_SIZES: [i32; 10] = [
    4,
    3, 3,
    2, 2, 2,
    1, 1, 1, 1,
];

trait FieldExt {
    fn get_cell(&self, pos: &CellPos) -> bool;
}

impl CellPos {
    fn from_tuple(tuple: (i32, i32)) -> CellPos {
        CellPos { row: tuple.0, col: tuple.1 }
    }
}

impl FieldExt for Field {
    fn get_cell(&self, pos: &CellPos) -> bool {
        match self.get(pos.row as usize) {
            Some(row) => {
                let col = row.get(pos.col as usize);
                *col.unwrap_or(&false)
            },
            None => false,
        }
    }
}

fn add_placements(
    placements: &mut Vec<(Orientation, CellPos)>,
    start: &CellPos,
    ship_size: i32,
    field: &Field,
) {
    let cell_vacant = |pair| {
        !field.get_cell(&CellPos::from_tuple(pair))
    };
    if start.col <= FIELD_SIZE - ship_size {
        let mut surroundings = (start.row - 1 ..= start.row + 1)
            .cartesian_product(start.col - 1 ..= start.col + ship_size);
        if surroundings.all(cell_vacant) {
            placements.push((Orientation::Horizontal, *start));
        }
    }
    if start.row <= FIELD_SIZE - ship_size {
        let mut surroundings = (start.row - 1 ..= start.row + ship_size)
            .cartesian_product(start.col - 1 ..= start.col + 1);
        if surroundings.all(cell_vacant) {
            placements.push((Orientation::Vertical, *start));
        }
    }
}

fn apply_placement(
    field: &mut Field,
    placement: (Orientation, CellPos),
    ship_size: i32,
) {
    let start = placement.1;
    match placement.0 {
        Orientation::Horizontal => {
            for col in start.col .. start.col + ship_size {
                field[start.row as usize][col as usize] = true;
            };
        },
        Orientation::Vertical => {
            for row in start.row .. start.row + ship_size {
                field[row as usize][start.col as usize] = true;
            };
        },
    };
}

fn place_ships(field: &Field, remaining_ships: &[i32]) -> Option<Field> {
    if remaining_ships.is_empty() {
        return Some(*field);
    }
    let ship_size = remaining_ships[0];
    let mut placements = Vec::new();
    for row in 0..FIELD_SIZE {
        for col in 0..FIELD_SIZE {
            add_placements(
                &mut placements,
                &CellPos { row, col },
                ship_size,
                &field);
        }
    }
    let mut rng = thread_rng();
    placements.shuffle(&mut rng);
    for placement in placements {
        let mut new_field = field.clone();
        apply_placement(&mut new_field, placement, ship_size);
        let filled_field = place_ships(&new_field, &remaining_ships[1..]);
        if filled_field.is_some() {
            return filled_field;
        }
    }
    None
}

fn gen_field() -> Field {
    let field = [[false; U_FIELD_SIZE]; U_FIELD_SIZE];
    let field = place_ships(&field, &SHIP_SIZES);
    field.expect("Not enough space for ships")
}

fn formatted_row(row: &Row) -> String {
    row.iter()
        .map(|&x| if x { '*' } else { '.' })
        .collect()
}

fn print_field(field: &Field) {
    for row in field {
        println!("{}", formatted_row(row));
    }
}

fn main() {
    let field = gen_field();
    print_field(&field);
}
