## 1. Cite as vantagens e desvantagens das comunicação serial:

#### (a) Assíncrona (UART).
>Vantagem: simplicidade do protocolo, full-duplex.

>Desvantagem: O envio dos dados é mais complicado e susceptível a erros.

>Funcionamento: o pino de transmissão (Tx) do protocolo envia um pacote de bits que será interpretado bit a bit pelo pino receptor. Cada pacote enviado contém 1 start bit que indica o início da mensagem, 1 ou 2 stop bits para indicar o final da mensagem, 5 a 9 bits de informação e 1 bit de paridade para evitar a recepção de erros.

>Ligação: por ser uma comunicação assíncrona a comunicação é feita por dois pinos Rx/Tx que dependem do baud rate como referência.

![Legenda](https://www.robocore.net/upload/tutoriais/50_img_9_H.png?939)



#### (b) SPI.
>Vantagem: não há limite para o número de escravos, a comunicação é full-duplex e possui boa velocidade de comunicação.

>Funcionamento: primeiramente o mestre gera um clock e seleciona através do pino SS com qual dispositivo será efetuada a comunicação. Em seguida os dados são enviados para o dispositivo de destino pelo pino MOSI e então o dispositivo escravo envia uma resposta (se necessário) ao mestre pelo pino MISO.

>Ligação: existem dois tipos de ligação para o protocolo SPI, ligação paralela e ligação em cascata.

> Ligação paralela :  a ligação mais comum deste protocolo que utiliza 1 pino de MOSI, MISO e clock para todos dispositivos e 1 pino SS para cada escravo ligado a comunicação.
![Legenda](https://www.robocore.net/upload/tutoriais/50_img_1_H.png?576)

> Ligação em cascata: Este tipo de ligação demanda menos pinos de comunicação, pois é utilizado 1 pino SS para todos os dispositivos ligados na comunicação, porém causa perda de velocidade na comunicação.
![Legenda](https://www.robocore.net/upload/tutoriais/50_img_2_H.png?576)

## 2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
 >A Raspberry Pi nao precisa fazer um pedido. A comunicação UART é assincrona. 

 > Portanto a informação sera enviada mesmo que seja perdida.
## 3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

 >O protocolo permite que um mestre se conecte com múltiplos escravos, para isso cada escravo deve possuir um pino Slave Select definido no mestre. Desta maneira, para selecionar o módulo escravo que irá receber a informação, basta colocar o pino seletor do dispositivo desejado em nível lógico alto.

 > Ou seja a Raspberry Pi deve fazer o pedido.

## 4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?
> Habilitar o bit de endereçamento dos dispositivos receptores com: UCMODEx = 10, então é possível indicar qual dispositivo deve 'ouvir' aquela determinada informação.

## 5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?
> Em _Ligação paralela_ ou  _Ligação em cascata_.
