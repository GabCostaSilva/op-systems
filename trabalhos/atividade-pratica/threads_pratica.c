#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define N 4

int i;
int j;

int Y[N][N];
int X[N][N];


int xFirstLine(void* args) {
	return (rand() % 100) + 1
}

int xColumn(void* args) {
	return X[i - 1][j] + Y[i][j];
}

void xMiddle(void* args) {
	return max(X[i - 1][j - 1], X[i - 1][j], X[i - 1][j + 1]) + Y[i][j];
}


int main() {
	pthread_t threads[4];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{

		}
	}
	return 0;
}