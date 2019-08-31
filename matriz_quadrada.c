#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 4

int X[N][N];
int Y[N][N];

void preencheY(){
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			Y[i][j] = (rand() % 10) + 1;
		}
	}
}

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

void preenchePrimeiraLinhaDeX(int i) {
	if(i == 0) {
		for (int j = 0; j < N; ++j)
		{
			X[0][j] = (rand() % 100) + 1; 
		}
	}
}

void preencheRegiaoCentralDeX(int i, int j) {
	if((i > 0) && (j > 0) && (j < N - 1)) {
		X[i][j] = max(posicaoDiagonalEsquerda(i, j), posicaoSuperior(i, j), posicaoDiagonalDireita(i, j)) + Y[i][j];
	}
}

void preencheRegiaoLateralDeX(int i, int j) {
	if((i > 0) && (j == 0 || j == N - 1)) {
		X[i][j] = posicaoSuperior(i, j) + Y[i][j];
	}
}


int main() {

	preencheY();

	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j)
		{	
			preenchePrimeiraLinhaDeX(i);
			preencheRegiaoCentralDeX(i, j);
			preencheRegiaoLateralDeX(i, j);
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