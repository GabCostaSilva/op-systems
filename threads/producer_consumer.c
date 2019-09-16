#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int counter;
int buffer[BUFFER_SIZE];

void* produce() {
	int in = 0;
	unsigned int nextProduced;

	do {
		nextProduced = rand();
		while(counter == BUFFER_SIZE);
		buffer[in] = nextProduced;
		in = (in + 1) % BUFFER_SIZE;
		/* Seção Critica */
		counter++;
		printf("Produced: counter = %d\n", counter);
	} while(1);

}

void* consume() {
	int out = 0;
	unsigned int nextConsumed;

	do {
		while(counter == 0);
		/* Consome um item */
		nextConsumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		/*Seção crítica*/
		counter--;
		printf("Consumed: counter = %d\n", counter);
	}while(1);

}

int main() {

	printf("Started main thread.\n");
	pthread_t producerThread;
	pthread_t consumerThread;

	pthread_create(&producerThread, NULL, produce, NULL);
	printf("asdfad\n");
	pthread_create(&consumerThread, NULL, consume, NULL);

	printf("Final counter = %d\n", counter);
	return 0;
}