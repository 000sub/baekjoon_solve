use std::io::{self, BufRead, BufReader, BufWriter, Write};

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut reader = BufReader::new(stdin.lock());
    let mut writer = BufWriter::new(stdout.lock());

    let mut buf = String::new();
    reader.read_line(&mut buf).unwrap();

    let cast_to_i32 = |x: &str| x.parse::<i32>().unwrap();
    let mut input = buf.trim().split_whitespace().map(cast_to_i32);
    let n = input.next().unwrap() as usize;
    let mut l = input.next().unwrap();
    
    buf.clear();
    reader.read_line(&mut buf).unwrap();
    let mut arr: Vec<i32> = buf.split_whitespace().map(cast_to_i32).collect();
    arr.sort_unstable();

    for &cur in &arr[0..n] {
        if cur > l {
            break;
        }
        l += 1;
    }

    writeln!(writer, "{}", l).unwrap();
}