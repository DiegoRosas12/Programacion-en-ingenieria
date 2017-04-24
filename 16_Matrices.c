// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>

#define N 100
#define M 100

int main()
{
	int n1, m1, n2, m2, i, j, k;
	float A[N][M], B[N][M], C[N][M], D[N][M], E[N][M];
	do {
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &n1);
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &m1);
	} while ((n1<1) || (n1>N) || (m1<1) || (m1>M));
	printf("Ingrese la matriz A.\n");
	for(i=0; i<n1; i++)
		for (j = 0; j < m1; j++)
		{
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%f", &A[i][j]);
		}
	do {
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &n2);
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &m2);
	} while ((n2<1) || (n2>N) || (m2<1) || (m2>M));
	printf("Ingrese la matriz B.\n");
	for (i = 0; i<(n2*m2); i++)
	{
			printf("B[%d][%d] = ", (i / m2) + 1, (i % m2) + 1);
			scanf("%f", &B[i/m2][i%m2]);
	}
	if ((n1 == n2) && (m1 == m2))
	{
		for (i = 0; i < n1; i++)
			for (j = 0; j < m1; j++)
			{
				C[i][j] = A[i][j] + B[i][j];
				D[i][j] = A[i][j] - B[i][j];
			}
	}
	else
		printf("Error en las dimensiones de las matrices.\n");

	if (m1 == n2)
		for (i = 0; i < n1; i++)
			for (j = 0; j < m2; j++)
				for (k = 0, E[i][j] = 0; k < m1; k++)
					E[i][j] += (A[i][k] * B[k][j]);
	else
		printf("Error en las dimensiones de las matrices.\n");
	printf("A+B=\n");
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
			printf("%f\t", C[i][j]);
		printf("\n");
	}
	printf("A-B=\n");
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
			printf("%f\t", D[i][j]);
		printf("\n");
	}
	printf("A*B=\n");
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
			printf("%f\t", E[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
    return 0;
}
