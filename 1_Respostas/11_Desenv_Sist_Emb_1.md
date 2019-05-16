## 1. Apresente 5 sistemas operacionais suportados pelo Raspberry Pi, e algumas de suas características.
>Linux: Três tipos diferentes do Linux estão disponíveis oficialmente: 
>* Pidora (baseado no Fedora);
>* Archlinux (um DIY OS);(_Largado_)
>* Raspian (Debian). SO oficial e recomendado para os novatos para o Raspberry Pi.
>* NOOBS. permite escolher entre uma seleção de ISOS durante o boot- Up.


>OpenElec & XBMC: OpenElec é um SO otimizado especificamente feito para executar a XBox Media Center. Ao 
contrário do Raspbmc, o OpenElec não contém nada além do mínimo necessário, por isso é mais difícil instalar outros pacotes, 
por exemplo. Consequentemente, a seleção de add-ons disponíveis é muito menor (sem emuladores) - mas oferece melhor 
desempenho.

>RetroPie: RetroPie é um emulador universal, o que significa que ele pode jogar muito bem qualquer ROM, 
embora jogos da Playstation não funcionam tão bem (pois demanda muito desempenho). Tecnicamente construído em 
Raspian, mas isso vem como uma ISO pré-construída do sistema operacional disponível para download.

>firefox OS: É uma combinação de Firefox e Linux construído por PTXdist. Está em fase de testes, e realmente não suporta
qualquer dispositivo de entrada ainda - tão puramente usado como um terminal de informação pública. 


## 2. Apresente as formas de instalação de sistemas operacionais para o Raspberry Pi.

A forma mais utilizada e mais eficaz é baixar a ISO do SO (normalmente disponível para download gratuitamente) e queimar
a ISO num cartão SD (utilizando qualquer software de prefrência) suportado pelo Raspberry Pi.

## 3. Apresente 3 formas de desenvolvimento de software para o Raspberry Pi.

>Eclipse: Eclipse começa, para a maioria das pessoas, com um IDE otimizado para programação Java, embora existam IDEs similares disponíveis para C / C ++ e PHP. Se a pessoa estiver em uma plataforma que não encoraja ou não permite a instalação de um IDE personalizado, existem IDEs baseados na Web que permitem criar software e armazenar elementos na nuvem.

>Biicode: Quando você está trabalhando em C ou C ++, um dos aspectos desafiadores é manter o controle de dependências - esses bits de código tanto dentro como fora do programa principal que fazem tantas das coisas úteis necessárias.

>Adafruit Web IDE: Adafruit é um grande negócio no mundo criador de Raspberry Pi, Arduino, BeagleBone e outros controladores incorporados. O Adafruit Web IDE é projetado para permitir que o usuário trabalhe diretamente no Raspberry Pi, escrevendo e editando código em uma interface da Web e, em seguida, baixando o código resultante diretamente para o Raspberry.

## 4. Apresente 3 formas de acesso remoto ao Raspberry Pi.

>SSH: Acesse a linha de comando do Pi de outro computador.

>VNC: Acesso remoto à interface gráfica do Pi, visto em uma janela em outro computador.

>FTP: Copiar arquivos entre o Raspberry e outro computador usando FTP (File Transfer Protocol).

## 5. Apresente as formas possíveis de compilação de código em C para o Raspberry Pi.

>O recomendado é utilizar o compilador gcc. 
```bash
gcc mycode.c -o mycode
```

## 6. Apresente as formas possíveis de compilação de código em Python para o Raspberry Pi.

> Simplesmente digitar $python no shell.
