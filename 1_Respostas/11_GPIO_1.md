## 1. Com relação às conexões GPIO do modelo de Raspberry Pi que você usará no projeto, responda:

#### (a) Quais pinos podem ser utilizados como entradas e saídas digitais comuns?
GPIO: 04,17,27,22,5,6,13,19,26,18,23,24,25,12,16,20,21

![Legenda](https://pythonprogramming.net/static/images/rpi/raspberry_pi_gpio-shutdown-pins.png)

#### (b) Quais pinos possuem resistores de pull-up e pull-down?

#### (c) Quais formas de comunicação serial são suportados pelos pinos GPIO?
>* SPI
>* UART
>* I2C

# 2. Apresente outras 3 bibliotecas de acesso I/O em C para o Raspberry Pi.
```python
import RPi.GPIO as GPIO
```
```c
#include "gpio_sysfs.h"
```
