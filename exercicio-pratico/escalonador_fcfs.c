#include <stdio.h>

#define QUANTIDADE_DE_PROCESSOS 6
#define TEMPO_TOTAL 200

void swap(int A[], int x, int y)
{
	int aux = A[x];
	A[x] = A[y];
	A[y] = aux;
}

void sort(int A[], int n)
{
	int i = 1;
	while (i < n)
	{
		int j = i;
		while (j > 0 && A[j - 1] > A[j])
		{
			swap(A, j, j - 1);
			j--;
		}
		i++;
	}
}

int main()
{
	int tempo_de_chegada[QUANTIDADE_DE_PROCESSOS] = {5, 4, 3, 2, 1, 0};

	int tempo_necessario[QUANTIDADE_DE_PROCESSOS] = {1, 10, 20, 30, 40, 50};

	int tempo_restante[QUANTIDADE_DE_PROCESSOS] = {1, 10, 20, 30, 40, 50};

	int linha_do_tempo[TEMPO_TOTAL];

	int turnaround[QUANTIDADE_DE_PROCESSOS];

	int tempo_de_espera[QUANTIDADE_DE_PROCESSOS];

	sort(tempo_de_chegada, QUANTIDADE_DE_PROCESSOS);
	sort(tempo_necessario, QUANTIDADE_DE_PROCESSOS);

	sort(tempo_restante, QUANTIDADE_DE_PROCESSOS);

	for (int i = 0; i < QUANTIDADE_DE_PROCESSOS; i++)
	{
		printf("%d\n", tempo_necessario[i]);
	}
	
	for (int i = 0; i < TEMPO_TOTAL; i++)
	{
		linha_do_tempo[i] = -1;
	}

	int processo_atual;

	int clock = 0;

	/** FCFS **/
	for (int i = 0; i < QUANTIDADE_DE_PROCESSOS; i++)
	{
		processo_atual = i;
		tempo_de_espera[processo_atual] = clock;
		
		printf("Tempo restante processo %d = %d\n", processo_atual, tempo_restante[processo_atual]);
	
		while (tempo_restante[processo_atual] > 0)
		{
			linha_do_tempo[clock] = processo_atual;
			clock++;
			tempo_restante[processo_atual]--;
		}
		turnaround[processo_atual] = clock;
	}

	printf("Linha do Tempo\n");
	for (int i = 0; i < TEMPO_TOTAL; i++)
	{
		printf("%d ", linha_do_tempo[i]);
	}

	printf("\nTempo de espera\n");

	for (int i = 0; i < QUANTIDADE_DE_PROCESSOS; i++)
	{
		printf("Tempo de espera processo[%d] = %d\n", i, tempo_de_espera[i]);
	}

	for (int i = 0; i < QUANTIDADE_DE_PROCESSOS; i++)
	{
		printf("turnaround processo[%d] = %d\n", i, turnaround[i]);
	}

	return 0;
}