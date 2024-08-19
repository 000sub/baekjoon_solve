use std::io::stdin;

fn main() {
    let mut buf = String::new();
    
    stdin().read_line(&mut buf).unwrap();
    let a = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    
    stdin().read_line(&mut buf).unwrap();
    let b = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    
    stdin().read_line(&mut buf).unwrap();
    let c = buf.trim().parse::<i32>().unwrap();

    let ab = format!("{}{}", a, b).parse::<i32>().unwrap();

    println!("{}", a + b - c);
    println!("{}", ab - c);
}
