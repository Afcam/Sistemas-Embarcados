# Para todas as questões, compile-as com o gcc e execute-as via terminal.

## 1. Crie um "Olá mundo!" em C.
```c
#include <stdio.h>

int main ()
{
  printf("Ola mundo");
}
```

## 2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
  char nome[255];
	printf("Qual o seu nome: ");
  scanf("%255[^\n]s",&nome);
	printf("Ola %s",nome);
	return 0;
}
```

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Arthur
$ Ola Arthur
```

## 3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Arthur Campos
$ Ola Arthur Campos
```

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Arthur Campos"
$ Ola "Arthur Campos"
```

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Arthur | ./ola_usuario_1
$ Qual o seu nome? Ola Arthur
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Arthur Faria | ./ola_usuario_1
$ Qual o seu nome? Ola Arthur Faria
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Arthur Faria" | ./ola_usuario_1
$ Qual o seu nome? "Ola Arthur Faria"
```

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
$ Qual o seu nome? Ola ola mundo cruel
```

## 4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e \*argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
  if(argc >1)
    printf("Ola %s \n",argv[1]);
  else
  	printf("Passe um nome pelo argumento\n");
	return 0;
}
```

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```

## 5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
$ Ola Eu
```

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
$ Ola Eu Mesmo
```

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
$ Passe um nome pelo arguento
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
$ Passe um nome pelo arguento
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_2
$ Passe um nome pelo arguento
```

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
$ Passe um nome pelo arguento
```

## 6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':
```c
#include<stdio.h>

int main(int argc, char *argv[])
{
   printf("Ola %s\n Numero de entradas = %d",argv[1],argc);
   return 0;
}
```

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```
## 7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```c
#include<stdio.h>

int main(int argc, char *argv[])
{
   int i;
   printf("Argumentos: ");
   for(i=1;i<argc;i++)
      printf("%s ",argv[i]);
   return 0;
}
```
```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```

## 8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

```c
#include<stdio.h>

int Num_Caracs(char *string)
{
   int i=0;
   while(string[i] != '\0')
      i++;
   return i;
}
```

## 9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```c
#include<stdio.h>

int main(int argc, char *argv[])
{
   int i;
   for(i=0;i<argc;i++)
      printf("Argumento: %s / Numero de caracteres: %d\n",argv[i], Num_Caracs(argv[i]));
   return 0;
}
```
```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```

## 10. Crie um Makefile para a questão anterior.

```bash
num_caracs:
   gcc -c num_caracs.c
   gcc ola_num_caracs_1.c num_caracs.o
   ./a.out Arthur
```

## 11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```c
#include<stdio.h>

int main(int argc, char *argv[])
{
   int i, total=0;
   for(i=0;i<argc;i++)
      total+=Num_Caracs(argv[i]);
   printf("Total de caracteres de entrada: %d", total);
   return 0;
}
```
```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```

## 12. Crie um Makefile para a questão anterior.
```bash
num_caracs:
   gcc -c num_caracs.c
   gcc num_caracs2.c num_caracs.o
   ./a.out Arthur
```
