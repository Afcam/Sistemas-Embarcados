##  Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

## 1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>
#include <stdlib.h>

int int main(int argc, char const *argv[])
{
  FILE *fp = fopen("ola_mundo.txt","wb");
  if(!fp)
    printf("Erro ao abrir o arquivo");
  elsed
    fprintf(fp, "%s\n", "Ola Mundo!" );

  return 0;
}
```

## 2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char nome[255];
  int idade;

  printf("Digite seu nome: ");
  scanf("%255[^\n]s",nome);
  printf("DIgite sua idade: ");
  scanf("%d",&idade);

  FILE *fp = fopen(strcat(nome,".txt"),"wb");

  if(!fp)
    printf("Erro ao abrir o arquivo");
  else
    fprintf(fp, "Nome: %s\nIdade: %d anos",nome,idade  );

  return 0;
}
```


```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

## 3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char nome[255];
  int idade;

  printf("Digite seu nome: ");
  scanf("%255[^\n]s",nome);
  printf("DIgite sua idade: ");
  scanf("%d",&idade);

  FILE *fp = fopen(strcat(nome,".txt"),"wb");

  if(!fp)
    printf("Erro ao abrir o arquivo");
  else
    fprintf(fp, "Nome: %s\nIdade: %d anos",nome,idade  );

  return 0;
}
```

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

## 4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```c
// bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
```
```c
// bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
   FILE *fp = fopen(nome_arquivo,"a");
   if(!fp)
     printf("Erro ao abrir o arquivo");
   else
      return ftell(fp);
}
```

## 5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.
```c
// bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
char* le_arq_texto(char *nome_arquivo);
```
```c
// bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
   FILE *fp = fopen(nome_arquivo,"a");
   if(!fp)
     printf("Erro ao abrir o arquivo");
   else
      return ftell(fp);
}

char* le_arq_texto(char *nome_arquivo)
{
     FILE *fp = fopen(nome_arquivo, "a");
     if(!fp)
      printf("Erro ao abrir o arquivo");
     else
     {
        long fsize = ftell(fp);
        rewind(fp);

        char *string = (*char)malloc(fsize + 1);
        fread(string, fsize, 1, fp);
     }

     fclose(fp);
     free(string);
     return string;
}

```
## 6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':
```c
// bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
char* le_arq_texto(char *nome_arquivo);
char* cat_falsificado(char *nome_arquivo);
```
```c
// bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
   FILE *fp = fopen(nome_arquivo,"a");
   if(!fp)
     printf("Erro ao abrir o arquivo");
   else
      return ftell(fp);
}

char* le_arq_texto(char *nome_arquivo)
{
     FILE *fp = fopen(nome_arquivo, "a");
     if(!fp)
      printf("Erro ao abrir o arquivo");
     else
     {
        long fsize = ftell(fp);
        rewind(fp);

        char *string = (*char)malloc(fsize + 1);
        fread(string, fsize, 1, fp);
     }

     fclose(fp);
     free(string);
     return string;
}

char* cat_falsificado(char *nome_arquivo)
{
   char *string = le_arq_texto(nome_arquivo);
   print("%s",string);

}
```
```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

## 7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':
```c
// bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
char* le_arq_texto(char *nome_arquivo);
char* cat_falsificado(char *nome_arquivo);
```
```c
// bib_arqs.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
   FILE *fp = fopen(nome_arquivo,"a");
   if(!fp)
     printf("Erro ao abrir o arquivo");
   else
      return ftell(fp);
}

char* le_arq_texto(char *nome_arquivo)
{
     FILE *fp = fopen(nome_arquivo, "a");
     if(!fp)
      printf("Erro ao abrir o arquivo");
     else
     {
        long fsize = ftell(fp);
        rewind(fp);

        char *string = (*char)malloc(fsize + 1);
        fread(string, fsize, 1, fp);
     }

     fclose(fp);
     free(string);
     return string;
}

char* cat_falsificado(char *nome_arquivo)
{
   char *string = le_arq_texto(nome_arquivo);
   print("%s",string);

}
```
```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```