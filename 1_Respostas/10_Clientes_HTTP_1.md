## 1. Especifique algumas portas importantes pré-definidas para o protocolo TCP/IP.
Porta : Protocolo

21	FTP

23	Telnet

25	SMTP

53	Domain Name (Nome do domínio do Sistema)

63	Whois

70	Gopher

79	Finger

80	HTTP

110	POP3

119	NNTP


## 2. Com relação a endereços IP, responda:

#### (a) Qual é a diferença entre endereços IP externos e locais?

> O Provedor de Serviços de Internet (ISP) atribui um endereço IP externo quando você se conecta à Internet. Quando o seu navegador solicita uma página da Web, ele envia esse endereço IP juntamente com ele. Seu ISP usa isso para saber quais dos seus clientes estão solicitando qual página da web. Além disso, qualquer site que você visitar terá acesso a este endereço IP.

> Cada site também tem um endereço IP próprio, embora você nunca precise conhecê-los. Quando você digita o nome de domínio, como "www.google.com", um servidor de nomes de domínio (DNS) procura o endereço IP para você, que é a localização real do site. Desta forma, os nomes de domínio são como nomes fantasia apontando para endereços IP fantasia.

> Se o computador estiver conectado a um roteador com configurações padrão, esse roteador atribuirá automaticamente um endereço IP local ao computador. Seu endereço IP local está oculto do mundo externo e usado somente dentro de sua rede privada. Você geralmente não precisa saber muito sobre isso, a menos que você está tentando configurar um jogo ou servidor web.


#### (b) Como endereços IP externos são definidos? Quem os define?

> Os provedores de internet.

#### (c) Como endereços IP locais são definidos? Quem os define?

> O endereço IP local muda dependendo dos outros dispositivos que estão conectados à mesma rede (e.g. roteador) e na ordem eles foram conectados. A maioria dos roteadores de rede atribui endereços IP a partir de 192.168.1.2 e incrementa o último dígito com cada novo dispositivo que se conecta.


#### (d) O que é o DNS? Para que ele serve?
> O servidor de nomes de domínio (DNS) transforma o nome atribuído do site ao IP do site.


## 3. Com relação à pilha de protocolos TCP/IP, responda:

#### (a) O que são suas camadas? Para que servem?
> O conjunto de protocolos pode ser visto como um modelo de camadas (Modelo OSI), onde cada camada é responsável por um grupo de tarefas, fornecendo um conjunto de serviços bem definidos para o protocolo da camada superior.
	

#### (b) Quais são as camadas existentes? Para que servem?
> São 4 camadas: Aplicação (contem todos os protocolos para um serviço específico de comunicação de dados em um nível de processo-a-processo), Transporte (Essa parte controla a comunicação host-a-host.), Internet (Essa parte é responsável pelas conexões entre as redes locais), Rede (Essa é a parte conhecida como física).
	
#### (c) Quais camadas são utilizadas pela biblioteca de sockets?
> A camada Aplicação.
	

#### (d) As portas usadas por servidores na função bind() se referem a qual camada?
> A camada Aplicação.
	

#### (e) Os endereços usados por clientes na função connect() se referem a qual camada?

## 4. Qual é a diferença entre os métodos `GET` e `POST` no protocolo HTTP?
> O Get busca algo na rede e post colocar algo na rede.

