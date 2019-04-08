## 1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?
```bash
ps -e
ps -ef
ps -all
ps ax
ps -eF
ps -ely
ps axu
ps -A
```

(b) Mostrar os processos de um usuário?
```bash
ps -u "user"
```

(c) Ordenar todos os processos de acordo com o uso da CPU?
```bash
ps --sort=-pcpu
```
(d) Mostrar a quanto tempo cada processo está rodando?
```bash
ps -e -o etime
```
## 2. De onde vem o nome `fork()`?
Originário do inglês "Bifurcação".
## 3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?
* Vantagem: Executar uma linha de comando pelo código em c;
* Desvantagem: Brechas à falhas de execução, pois depende muito do sistema.

(b) `fork()` e `exec()`?
* Vantagens: a função fork() cria uma cópia do processo atual e em seguida a função exec() que substitui o conteúdo do novo processo por um novo programa.		
* Desvantagens: ter cautela dos dois processos gerados não alterarem na mesma variável ou arquivo .


## 4. É possível utilizar o `exec()` sem executar o `fork()` antes?
É possível, porém o processo pai será perdido.
## 5. Quais são as características básicas das seguintes funções:

(a) `execp()`?
> Permite a execucao de um programa no lugar atual (current path)
(b) `execv()`?
> Permite que a lista de argumentos do novo processo seja nula
(c\) `exece(s)`?
> Permite argumento adicional no novo processo
(d) `execvp()`?
> Permite lista de argumentos nula e procura do programa no current path
(e) `execve()`?
> Permite argumento adicional e procura do programa no current path
(f) `execle()`?
> Permite utilização de var agrs e argumento adicional
