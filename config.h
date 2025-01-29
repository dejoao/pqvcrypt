#ifndef CONFIG_H
#define CONFIG_H

#define TAMANHO_ALFABETO 26

//PROTOTIPOS
char *criptografia_substituicao (char *key, char *texto);
char* descriptografar_substituicao (char *key, char *texto_criptografado);
int menu(void);

#endif