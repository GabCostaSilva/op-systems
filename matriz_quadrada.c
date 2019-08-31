#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 4

struct Arguments
{
	int i;
	int j;
};

int X[N][N];
int Y[N][N];


int max(int a, int b, int c) {
	int max = a ? (a > b) : b;

	max = c ? (c > max) : max;

	return max;
}

int posicaoDiagonalEsquerda(int i, int j) {
	return X[i - 1][j - 1];
}

int posicaoSuperior(int i, int j) {
	return X[i - 1][j];
}

int posicaoDiagonalDireita(int i, int j) {
	return X[i - 1][j + 1];
}

void *preencheY(void* args){
	struct Arguments *arguments = args;

	int i = arguments->i;
	int j = arguments->j;

	printf("Preenchendo Y...\n");
	
	Y[i][j] = (rand() % 10) + 1;
}

void *preenchePrimeiraLinhaDeX(void* args) {
	struct Arguments *arguments = args;

	int i = arguments->i;
	int j = arguments->j;

	if(i == 0) {
		printf("Preenchendo primeira linha...\n");
		X[i][j] = (rand() % 100) + 1; 
		printf("Coluna[%d] = %d\n", j, X[i][j]);
	}
}

void *preencheRegiaoCentralDeX(void* args) {
	struct Arguments *arguments = args;

	int i = arguments->i;
	int j = arguments->j;

	if((i > 0) && (j > 0) && (j < N - 1)) {
		printf("Preenchendo centro...\n");
		X[i][j] = max(posicaoDiagonalEsquerda(i, j), posicaoSuperior(i, j), posicaoDiagonalDireita(i, j)) + Y[i][j];

	}
}

void *preencheRegiaoLateralDeX(void* args) {
	struct Arguments *arguments = args;

	int i = arguments->i;
	int j = arguments->j;

	if((i > 0) && (j == 0 || j == N - 1)) {
		printf("Preenchendo laterais...\n");
		X[i][j] = posicaoSuperior(i, j) + Y[i][j];
	}
}


int main() {
	pthread_t t1, t2, t3, t4;

	struct Arguments args;
	

	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j)
		{	
			args.i = i;
			args.j = j;
			pthread_create(&t1, NULL, &preencheY, &args);
			sleep(1);
			pthread_create(&t2, NULL, &preenchePrimeiraLinhaDeX, &args);
			sleep(1);
			pthread_create(&t3, NULL, &preencheRegiaoLateralDeX, &args);
			sleep(1);
			pthread_create(&t4, NULL, &preencheRegiaoCentralDeX, &args);
			sleep(1);

			pthread_join(t1, NULL);
			pthread_join(t2, NULL);
			pthread_join(t3, NULL);
			pthread_join(t4, NULL);

		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("[%d][%d] = %d\n", i, j, X[i][j]);
		}
		printf("\n");
	}
	return 0;
}