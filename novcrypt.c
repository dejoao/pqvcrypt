#include <stdio.h>
#include <stdlib.h> //usado na funcao chave
#include <time.h> //usado na funcao chave
#include <string.h>
#include <ctype.h>

#define TAMANHO_ALFABETO 26

char *chave(void)
{
    srand(time(NULL)); //usado para gerar um numero aleatorio com base no horario
    //variavel com todas letras do alfabeto
    const char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    //cria uma nova variavel
    char *chave = malloc(27 * sizeof(char));
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        //cria um indice aleatorio
        int indice_aleatorio = rand() % TAMANHO_ALFABETO;
        //pega uma letra do alfabeto e adiciona na nova variavel atraves do indice aleatorio
        chave[i] = alfabeto[indice_aleatorio];
    }
    //cria um caractere nulo no fim da string
    chave[TAMANHO_ALFABETO + 1] = '\0';
    return chave;
}

char *criptografia_substituicao (char *key, char *texto)
{
    int n = strlen(texto);
    char *textoCriptografado = texto;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(texto[i]))
        {
            char base = isupper(texto[i]) ? 'A' : 'a';
            int indice = tolower(texto[i]) - 'a';
            
            // Verifica se o caractere é maiúsculo ou minúsculo e realiza a substituição
            textoCriptografado[i] = isupper(texto[i]) ? toupper(key[indice]) : tolower(key[indice]);
        }
        
    }
    return textoCriptografado;
}
char* descriptografar_substituicao (char *key, char *texto_criptografado)
{
   
}

int main(int argc, char *argv[])
{
    //verificacao uso correto
    if(argc != 2)
    {
        printf("\nUse: \"novcrypt encrypt\" para criptografar ou \"novcrypt descrypt\" para descriptografar.\n\n");
        return 2;
    }
    //se criptografar ou descriptografar
    int caracteres_encrypt = 7;
    if(strlen(argv[1]) == caracteres_encrypt)
    { 
        char *key = chave();
        printf("Sua chave é %s\n", key);

        //Pegar chave do usuario
        /*size_t tamanho_key = 10, indice_key = 0;
        char *key = malloc(TAMANHO_ALFABETO * sizeof(char));
        if (key == NULL)
        {
            printf("alocação de memoria falhou \n");
            return 1;
        }
        int caractere_key;
        int count_caractere_key = 0;
        printf("Digite uma chave: ");
        while((caractere_key = getchar()) != '\n' && caractere_key != EOF)
        {
            if (indice_key + 1 >= tamanho_key)
            {
                tamanho_key *= 2;
                char *buffer_novo_key = realloc(key, tamanho_key);
                if (buffer_novo_key == NULL)
                {
                    printf("alocação de memoria falhou \n");
                    return 1;
                }
                key = buffer_novo_key;
            }
            key[indice_key++] = caractere_key;
            count_caractere_key++;
        }
        key[indice_key] = '\0';

        if(count_caractere_key != TAMANHO_ALFABETO)
        {
            printf("A chave deve conter 26 caracteres\n");
            return 4;
        }
        for (int i = 0; i < count_caractere_key; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Use apenas letras\n");
                return 4;
            }
            // Mensagem de chave for inválida, contem letra repetidas
            for (int j = i + 1; j < count_caractere_key; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Não repita letras\n");
                    return 4;
                }
            }
        }*/

        //pegar texto que vai ser criptografado
        size_t tamanho = 10, indice = 0;
        char *texto = malloc(tamanho * sizeof(char));
        //verificacao
        if(texto == NULL)
        {
            printf("alocação de memoria falhou \n");
            return 1;
        }
        int caractere;
        printf("Digite o texto: ");
        while((caractere = getchar()) != '\n' && caractere != EOF)
        {
            if (indice + 1 >= tamanho)
            {
                tamanho *= 2;
                char *buffer_novo = realloc(texto, tamanho);
                //verificacao
                if(buffer_novo == NULL)
                {
                    printf("alocação de memoria falhou \n");
                    return 1;
                }
                texto = buffer_novo;
            }
            texto[indice++] = caractere;
        }
        texto[indice] = '\0';

        //printf("seu texto é: %s \n", texto);
        printf("seu texto criptografado é: %s\n", criptografia_substituicao (key, texto));

        free(texto);
        free(key);
        return 0;
    }else
    {
        //pedir chave
        printf("Qual sua chave: ");
        char key[26];
        scanf("%s", key);
        int tamanho_key = strlen(key);
        if(tamanho_key != TAMANHO_ALFABETO)
        {
            printf("A chave deve ter 26 digitos\n");
            return 3;
        }
        for (int i = 0; i < tamanho_key; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("A chave deve ter apenas letras\n");
                return 3;
            }
            // Mensagem de chave for inválida, contem letra repetidas
            for (int j = i + 1; j < tamanho_key; j++)
            {
                if (key[i] == key[j])
                {
                    printf("A chave não pode ter letras repetidas\n");
                    return 3;
                }
            }
        }
        //pedir texto criptografado
        size_t tamanho_descypt = 10, indice_descrypt = 0;
        char *texto_descrypt = malloc(tamanho_descypt * sizeof(char));
        //verificacao
        if(texto_descrypt == NULL)
        {
            printf("alocação de memoria falhou \n");
            return 1;
        }
        printf("Digite o texto: ");
        int caractere_descrypt;
        //while ((caractere_descrypt = getchar()) != '\n' && caractere_descrypt != EOF); //limpa o buffer
        while((caractere_descrypt = getchar()) != '\n' && caractere_descrypt != EOF)
        {
            if (indice_descrypt + 1 >= tamanho_descypt)
            {
                tamanho_descypt *= 2;
                char *buffer_novo_descrypt = realloc(texto_descrypt, tamanho_descypt);
                //verificacao
                if(buffer_novo_descrypt == NULL)
                {
                    printf("alocação de memoria falhou \n");
                    return 1;
                }
                texto_descrypt = buffer_novo_descrypt;
            }
            texto_descrypt[indice_descrypt++] = caractere_descrypt;
        }
        texto_descrypt[indice_descrypt] = '\0';
        //funcao para descriptografar
        printf("seu texto descriptografado é: %s", descriptografar_substituicao(key, texto_descrypt));
        //retorna texto 
        free(texto_descrypt);
        return 0;
    }
}