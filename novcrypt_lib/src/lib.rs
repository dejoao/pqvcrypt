use std::io::{self, Write};

#[unsafe(no_mangle)]
pub extern "C" fn input() {
    let mut input = String::new();

    print!("Digite algo: ");
    io::stdout().flush().unwrap(); // Garante que a mensagem seja impressa antes de ler

    io::stdin().read_line(&mut input).unwrap();

    println!("Você digitou: {}", input.trim());
}
