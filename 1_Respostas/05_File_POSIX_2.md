## Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

## 1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```c
#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <string.h>

int main (int argc, char *argv[])
{
    int fd1;
    char buf[]="Ola mundo";

    fd1 = open(argv[1], O_RDWR | O_CREAT);
    if (fd1 == -1) {
        printf("File cannot be opened");
        return 0;
    }

    write(fd1, buf, strlen(buf));
    close(fd1);
    return 0;
}
```


## 2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```c
#include <stdio.h>
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <string.h>

int main (int argc, char *argv[])
{
    int fd1;
    char nome[255];
    int idade;

    printf("Digite o seu nome: \n");
    scanf("%255[^\n]s",nome);
    printf("Digite a sua idade: \n");
    scanf("%d",&idade);
    printf("%d\n",idade);

    fd1 = open(nome, O_RDWR | O_CREAT);
    if (fd1 == -1) {
        printf("File cannot be opened");
        return 0;
    }


    write(fd1, "Nome: ", strlen("Nome: "));
    write(fd1, &nome, strlen(nome));
    write(fd1, "\nIdade: ", strlen("\nIdade: "));
    write(fd1, &idade, sizeof(int));

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
#include <unistd.h>  //Used for UART
#include <fcntl.h>   //Used for UART
#include <termios.h> //Used for UART
#include <string.h>

int main (int argc, char *argv[])
{
    int fd1;

    fd1 = open(argv[1], O_RDWR | O_CREAT);
    if (fd1 == -1) {
        printf("File cannot be opened");
        return 0;
    }

    write(fd1, "Nome: ", strlen("Nome: "));
    write(fd1, argv[1], strlen(argv[1]));
    write(fd1, "\nIdade: ", strlen("\nIdade: "));
    write(fd1, argv[2], strlen(argv[2]));

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
## 5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo); Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
   read(open (nome_arquivo, O_RDONLY), conteudo, tam_arq_texto(nome_arquivo));
}
```
## 6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':
```c
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
   char *String = (char*) malloc(tam_arq_texto(argv[1])+1);
   le_arq_texto(argv[1], String);
   printf("%s", String);
   return 0;
}
```
```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

## 7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
   char *String = (char*) malloc(tam_arq_texto(argv[2])+1);
   char *T = (char*) malloc(tam_arq_texto(argv[2])+1);
   le_arq_texto(argv[2], String);

   int i, j=0, q=0;
   for(i = 0; i <= strlen(String)-strlen(argv[1]) ; i++)
      if(String[i] == argv[1][0])
      {
         while(String[i+j] == argv[1][j])
         {
            j++;
            if(j == strlen(argv[1])-1)
            {
               q++;
               break;
            }
         }
         j = 0;
      }

   printf("'%s' ocorre %d vezes no arquivo '%s'\n", argv[1], q, argv[2] );
   return 0;
}
```
```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
