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

        printf("seu texto é: %s \n", texto);
        printf("seu texto criptografado é: %s\n", criptografia_substituicao (key, texto));

        free(texto);
        free(key);
        return 0;
    }else
    {
        //pedir chave
        //pedir texto criptografado
        //funcao para descriptografar
        //retorna texto 
    }
}