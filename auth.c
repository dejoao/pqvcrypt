#include "config.h"

char* new_senha(void){
    
    //iniciar biblioteca
    if (sodium_init() < 0) {
        printf("Erro ao inicializar a biblioteca libsodium.\n");
        return NULL;
    }

    //pedir senha do usuario
    char *senha = get_string(); 

    // Alocar memoria para guardar hash criada
    char *hash = malloc(HASH_SIZE);
    if (hash == NULL) {
        printf("Falha ao alocar memória para o hash.\n");
        free(senha);
        return NULL;
    }

    // Gera o hash da senha
    if (crypto_pwhash_str(hash, senha, strlen(senha),
            crypto_pwhash_OPSLIMIT_INTERACTIVE, // Limite de operações
            crypto_pwhash_MEMLIMIT_INTERACTIVE  // Limite de memória
        ) != 0) {
        printf("Falha ao gerar o hash.\n");
        free(senha);  
        free(hash);  
        return NULL;
    }

    free(senha); // Libera a memória da senha original
    return hash; // Retorna o hash gerado
}

void login(void){

    // Pegar email
    printf("Faça login\n\nEmail: ");
    char *email = get_string();
    //fazer verificacao email valido

    // Pegar senha usar hash
    printf("Senha: ");
    char *hash = new_senha();
    printf("%s", hash);

    // Fazer consulta no banco de dados
    
    // retorna 0 se estiver dados certos e existe no banco de dados
    // senao fazer cadastro
    //Logado com sucesso mandar para tela inicial
}

void cadastro(void){

    //Pegar email 
    printf("\nCrie sua conta\n\nEmail: ");
    char *email = get_string();
    //fazer verificacao email valido

    //guardar no banco de dados

    //Pegar senha //Fazer Hash
    printf("Senha: ");
    char *senha_hash = new_senha();
    
    //Guardar no banco de dados
    //Criado com sucesso
    //Mandar para o login

}

int menu(void){
    int opcao;

    printf("* ##   ##   #####   ##   ##    ####   ######   ###  ### ######    # ##### *\n");
    printf("* ###  ##  ### ###  ##   ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##  *\n");
    printf("* #### ##  ##   ##  ##   ##  ##        ##  ##    ####    ##  ##     ## *\n");
    printf("* #######  ##   ##   ## ##   ##        #####      ##     #####      ## *\n");
    printf("* ## ####  ##   ##   ## ##   ##        ## ##      ##     ##         ## *\n");
    printf("* ##  ###  ### ###    ###     ##  ##   ## ##      ##     ##         ## *\n");
    printf("* ##   ##   #####     ###      ####   #### ##    ####   ####       #### *\n");
    printf("\n1. Login\n2. Cadastro\n3. Sair\n\n");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
            //funcao login
            login();
            break;
        case 2:
            //funcao cadasstro
            cadastro();
            break;
        case 3:
            return 1;
            break;
        default:
            printf("Opção invalida.\n");
    }

    return 0;
}