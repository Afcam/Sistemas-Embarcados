## 1. Crie dois processos, e faça com que o processo-filho gere uma onda quadrada, enquanto o processo-pai faz polling de um botão no GPIO, aumentando a frequência da onda sempre que o botão for pressionado. A frequência da onda quadrada deve começar em 1 Hz, e dobrar cada vez que o botão for pressionado. A frequência máxima é de 64 Hz, devendo retornar a 1 Hz se o botão for pressionado novamente.



```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#include "gpio_dev_mem.h"


volatile int varCompartilhada=0;
float period=1;

int pwm ()
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;
  for (;;)
  {
    digitalWrite (0, HIGH) ; delay (period/2) ;
    digitalWrite (0,  LOW) ; delay (period/2) ;
  }
  return 0 ;
}
// Função que incrementa o Contador
void* push_button (void *arg)
{
	setup_io();
	INP_GPIO(4);
	while(1)
	{
            puts("Pressione o botao");
            while(GET_GPIO(4));
            puts("Botao pressionado");

            period = period/2;
            if(period < 0.15)
                period = 1;
            while(GET_GPIO(4)==0);
            puts("Botao solto");
	}
}

int main (int argc, char** argv) {

	pthread_t t0;
	pthread_t t1;

	int res0, res1;

	res0 = pthread_create(&t0, NULL, &pwm, NULL);
	res1 = pthread_create(&t1, NULL, &push_button, NULL);

	res0 = pthread_join(t0, NULL);
	res0 = pthread_join(t1, NULL);
	return 0;
}
```









