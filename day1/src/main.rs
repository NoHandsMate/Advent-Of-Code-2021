use std::fs::File;
use std::io::{BufRead, BufReader};


fn part1(vec: &Vec<usize>) {
    let mut count = 0;
    for index in 0..vec.len() - 1 {
        let last = vec[index];

        let next = vec[index + 1];
        if last < next {
            count += 1;
        }
    }

    println!("COUNT: {}", count);
}

fn part2(vec: &Vec<usize>) {
    let mut count = 0;
    let mut prev  = 0;
    let mut i : usize = 0;

    while i + 2 < vec.len() {
        let sum = vec[i] + vec[i + 1] + vec[i + 2];

        if sum > prev && i != 0 {
            count += 1;
        }

        prev = sum;
        i += 1;
    }

    println!("COUNT (PART 2): {}", count);
}

fn main() {
    let filename = "input.txt";

    let file = File::open(filename).unwrap();
    let reader = BufReader::new(file);
    let mut inputs: Vec<usize> = Vec::new();
    
    for line in reader.lines() {
        let line = line.unwrap(); 
        let new_int = line.parse::<usize>().unwrap();
        inputs.push(new_int);
    }

    
    part1(&inputs);
    part2(&inputs);
    

    
}