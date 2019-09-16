#define N 1000
#include <stdlib.h>

int main() {

	int Y[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Y[i][j] = (rand() % 10) + 1;
		}
	}

	return 0;
}