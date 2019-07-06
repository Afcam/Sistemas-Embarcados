# testando: testando.c
# 	gcc $(CFLAGS) testando.c -o Ok -lpthread
Test: main.o UDP.o
	gcc $(CFLAGS) -o Test main.o UDP.o -lpthread 
main.o: main.c UDP.h
	gcc $(CFLAGS) -c main.c -lpthread
UDP.o: UDP.c UDP.h
	gcc $(CFLAGS) -c UDP.c -lpthread
clean:
	rm -f *.o Test 