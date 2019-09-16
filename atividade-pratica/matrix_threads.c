#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define N 10

int Y[N][N];
int X[N][N];

void* preencheLinhasDeY(void* args) {
	int *linha = (int *) args;
	
	// printf("Thread %d\n", *linha);

	for (int j = 0; j < N; ++j)
	{	
		Y[*linha][j] = (rand() % 10) + 1;
	}
}

int main() {
	pthread_t threads[N];

	printf("PID=%d\n", getpid());

	// Preenche linhas de Y
	for (int i = 0; i < N; ++i)
	{
		int *linha = malloc(sizeof(int));

		*linha = i;

		int err = pthread_create(&threads[i], NULL, preencheLinhasDeY, linha);
		
		if(err != 0) {
			printf("ERROR %d\n", err);
		}

	}

	for (int i = 0; i < N; ++i)
	{	
		pthread_join(threads[i], NULL);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", Y[i][j]);
		}
		printf("\n");
	}
	return 0;
}
