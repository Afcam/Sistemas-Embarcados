## 1. Crie um código em C para gerar três processos-filho usando o `fork()`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	system("ps");
	printf("\n");

	for (int i = 0; i < 3; ++i)
	{
	    int pid = fork();
	    if(pid < 0)
	        exit(EXIT_FAILURE);
	    else if (pid > 0)
	        printf("Este é o processo pai com ID = %d\n", (int) getpid());
	    else
	        exit(EXIT_SUCCESS);

	    system("ps");
		printf("\n");
	}

	for (int i = 0; i < 3; ++i)
	{
	    int status;
	    pid_t pid = wait(&status);
	    printf("Este é o processo filho %d com ID = %d\n", i+1, pid);
	}

	return 0;
}
```
## 2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int n;
    char entrada[20];
	for(n = 1; n < argc; n ++) {
		strcpy (entrada, argv[n]);
		system(entrada);
	}
}
```
```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```

## 3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	char **p = (char **) malloc(argc*sizeof(char));

	for(int i = 0; i < argc ; i++)
		p[i] = argv[i+1];
	p[argc] = NULL;

	int pid = fork();
	if(pid < 0)
	    exit(EXIT_FAILURE);
	else if (pid == 0)
		execvp(p[0], p);

	return 0;
}
```
## 4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```C
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável?
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main ()
{
	for (int i = 0; i < 3; ++i)
	{
	    int pid = fork();
	    if(pid < 0)
	        exit(EXIT_FAILURE);
	    else if(pid == 0)   	
	        exit(EXIT_SUCCESS);
	}

	for (int i = 0; i < 3; ++i)
	{
	    int status;
	    pid_t pid = wait(&status);
	    Incrementa_Variavel_Global(pid);
	}

	return 0;
}
```
## 5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável?

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main ()
{
	int pid_pai = getpid(), pid;
	for (int i = 0; i < 3; ++i)
	{
	    pid = fork();
	    if(pid < 0)
	        exit(EXIT_FAILURE);
	    else if(pid == 0)
	        exit(EXIT_SUCCESS);
	}

	printf("Processo pai: \n");
	Incrementa_Variavel_Global(pid_pai);
	printf("\n");

	for (int i = 0; i < 3; ++i)
	{
	    int status;
	    pid_t pid = wait(&status);
	    printf("Processo filho %d: \n", i+1);
	    Incrementa_Variavel_Global(pid);
	    printf("\n");
	}

	return 0;
}
```
