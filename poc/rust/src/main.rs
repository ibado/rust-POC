use std::fs::File;
use std::io::{prelude::*, BufReader};
use std::error::Error;

fn count_occurrences(line: &str, word: &str) -> usize {
    line.split_whitespace().filter(|&w| w == word).count()
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = std::env::args().collect();

    let filename: String = args[1].parse()?;
    let word: String = args[2].parse()?;

    let file = File::open(filename)?;
    let reader = BufReader::new(file);

    let mut count: usize = 0;
    for line in reader.lines() {
        count += count_occurrences(&line?, &word);
    }

    println!("Word was found {} times", count);
    Ok(())
}
