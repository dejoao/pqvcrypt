use std::io;

#[unsafe(no_mangle)]
pub extern "C" fn login(){
    // Pegar email
    let mut email = String::new(); //cria a variavel

    println!("Email: ");

    io::stdin().read_line(&mut email).expect("Falha ao ler a linha"); // armazena a entrada em na variavel email

    email = email.trim().to_string(); // Remove a quebra de linha da entrada

    println!("Você digitou: {}", email);
    
    // Pegar senha usar hash

    // Fazer consulta no banco de dados
    // retorna 0 se estiver dados certos e existe no banco de dados
    // senao fazer cadastro
}

fn get_string() -> String{
    let mut email = String::new(); //cria a variavel
    io::stdin().read_line(&mut email).expect("Falha ao ler a linha");
    email = email.trim().to_string();
}