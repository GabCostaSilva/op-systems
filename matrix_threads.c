#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 4

int Y[N][N];
int X[N][N];

int main() {

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Y[i][j] = srand(time(NULL));
		}
	}

	return 0;
}
