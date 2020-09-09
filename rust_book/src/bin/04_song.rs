const VERSES: usize = 5;

fn main() {
    println!("{}", get_lyrics());
}

fn get_lyrics() -> String {
    (0..VERSES)
        .map(|i| get_verse(i))
        .collect::<Vec<String>>()
        .join("\n\n")
}

fn get_verse(number: usize) -> String {
    const DAYS: [&str; VERSES] = [
        "first",
        "second",
        "third",
        "fourth",
        "fifth"
    ];
    const LINES: [&str; VERSES] = [
        "Five gold rings,",
        "Four calling birds,",
        "Three French hens,",
        "Two turtle doves,",
        "And a partridge in a pear tree."
    ];
    let first_part = format!("On the {} day of Christmas my true love sent to me\n", DAYS[number]);
    let last_part = if number == 0 {
        "A partridge in a pear tree.".to_owned()
    } else {
        LINES[VERSES - number - 1..].join("\n")
    };
    first_part + last_part.as_str()
}