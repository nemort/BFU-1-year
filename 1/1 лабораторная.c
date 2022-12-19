#include <stdio.h>
#define N 5
int main() {
	int mat[N][N] = { 0 };
	int count = 1;
	int i = 0, j = 0;
	mat[i][j] = count;
	while (count != (N * N)) {
		count++;
		if (i == N - 1)
			j++;
		else
			i++;
		mat[i][j] = count;
		while ((i != 0) && (j != N - 1)) { //право-верх
			count++;
			i--; //вверх
			j++; //вправо
			mat[i][j] = count;
			}
		if (j == N - 1)
			i++;	
		else
			j++;
		count++;
		mat[i][j] = count;
		while ((j != 0) && (i != N - 1)){ //лево-низ
			count++;
			i++; //вниз
			j--; //влево
			mat[i][j] = count;
		}
	}
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < N; l++) {
			printf("%3d ", mat[k][l]);
		}
		printf("\n");
	}
	return 0;
}