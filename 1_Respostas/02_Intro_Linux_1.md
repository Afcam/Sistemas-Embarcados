## 1. Por que o Linux recebeu esse nome?
 O nome Linux surgiu da mistura de Linus + Unix. Linus é o nome do criador do Linux, Linus Torvalds.

## 2. O que são daemons?
Um daemon é um programa que executa como um processo em plano de fundo, em vez de estar sob o controle direto de um usuário interativo

## 3. O que é o shell?
Um shell é uma interface de usuário para acessar os serviços de um sistema operacional.

## 4. Por que é importante evitar executar o terminal como super-usuário?
Através dele é possível fazer qualquer coisa com o sistema operacional, por exemplo, remover ou adicionar privilégios de impressão para determinados usuários.

## 5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?
Tab

## 6. Quais botões do teclado apresentam instruções escritas anteriormente?
Seta Up

## 7. Apresente os respectivos comandos no terminal para:
  - (a) Obter mais informações sobre um comando.
  ```bash
  man <comando>
  ```

  - (b) Apresentar uma lista com os arquivos dentro de uma pasta.
  ```bash
  ls
  ```

  - (c) Apresentar o caminho completo da pasta.
  ```bash
  pwd
  ```

  - (d) Trocar de pasta.
  ```bash
  cd
  ```

  - (e) Criar uma pasta.
  ```bash
  mkdir <nome_da_pasta>
  ```
  - (f) Apagar arquivos definitivamente.
  ```bash
  rm <arquivo>
  ```

  - (g) Apagar pastas definitivamente.
  ```bash
  rm -r <pasta>
  ```

  - (h) Copiar arquivos.
  ```bash
  cp <arq1> <arq2>
  ```

  - (i) Copiar pastas.
  ```bash
    cp -r <pasta1>   <pasta2>
  ```

  - (j) Mover arquivos.
  ```bash
  mv <file1> <file2>
  ```

  - (k) Mover pastas.
  ```bash
  mv <file1> <file2>
  ```
  - (l) Renomear pastas.
  ```bash
  mv <FILE> <New-name>
  ```

  - (m) Apresentar o conteúdo de um arquivo.
  ```bash
  cat <file>
  less <file>
  ```
  - (n) Apresentar o tipo de um arquivo.
  - (o) Limpar a tela do terminal.
  ```bash
  clear
  Crtl + L
  ```
  - (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.
  ```bash
  grep <palavra> <arquivo>
  ```
  - (q) Ordenar informações em um arquivo-texto.
  ```
  sort <file>
  ```
  - (r) Substituir ocorrências de palavras-chave em um arquivo-texto.
  ```bash
  sed -e 's/Amaral/Julia/g' nomes.txt
  ```
  - (s) Conferir se dois arquivos são iguais.
  ```bash
  diff <lista1> <lista2>
  ```
  - (t) Escrever algo na tela.
  ```bash
  print <texto>
  ```
