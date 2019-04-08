## 1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
> Sera criado apenas um pipe, pois a linha de codigo pipe(fd) foi executada por apenas um processo.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
> Serão criados 2 pipes, pois a linha de codigo pipe(fd) foi executada por dois processos diferentes depois do
fork() ser executado.


## 2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

> SIGHUP - Sinal emitido aos processos associados a um terminal quanto este se desconecta. Este sinal também  emitido a cada processo
quando o chefe termina sua execução.

> SIGQUIT - Sinal emitido aos processos do terminal quando com a tecla de abandono (quit ou ctrl+d) do teclado são acionadas.

> SIGILL - Quando uma instrução ilegal é detectada.

> SIGTRAP - Sinal emitido após cada instrulção em caso de geração de traces dos processos.

> SIGIOT - Sinal emitido em caso de problemas de hardware.

## 3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?


> O código funciona normalmente, retorna a data de 1 em 1 segundo. O problema ocorre quando o sinal é acionado durante
uma operação de I/O proveniente de outra parte do código, o que causa sua interrupção e não é executada até o final.
