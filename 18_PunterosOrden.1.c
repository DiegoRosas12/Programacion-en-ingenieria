// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int burbuja(float *pX, int n)
{
	int i, j;
	float aux;
	for (i = 0; i<n - 1; i++)
		for (j = i + 1; j<n; j++)
			if (pX[j] < pX[i])
			{
				aux = *(pX + i);
				*(pX + i) = *(pX + j);
				*(pX + j) = aux;
			}
	return 0;
}
int burbuja2(float **ppX, int n)
{
	int i, j;
	float *aux;
	for (i = 0; i<n; i++)
		for (j = i + 1; j<n; j++)
			if (*ppX[j] < *ppX[i])
			{
				aux = *(ppX + i);
				*(ppX + i) = *(ppX + j);
				*(ppX + j) = aux;
			}
	return 0;
}

int main()
{
	int n, i;
	float *pX, **ppX, max, min, media;
	do {
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	} while (n<1);
	printf("Ingrese el valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if (min > max)
	{
		max = max + min;
		min = max - min;
		max = max - min;
	}
	srand(time(NULL));
	pX = (float*)malloc(n * sizeof(float));
	ppX = (float**)malloc(n * sizeof(float*));
	printf("El vector X es:\n");
	for (i = 0, media = 0; i < n; i++)
	{
		pX[i] = ((max - min)*rand()) / RAND_MAX + min;
		*(ppX + i) = pX + i;
		media += pX[i];
		printf("X[%d] = %f\n", i + 1, *(pX + i));
	}
	media /= n;
	printf("La media es %f\n", media);
	burbuja2(ppX, n);
	printf("Vector deordenado:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i + 1, pX[i]);
		
	printf("Vector ordenado:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i + 1, *ppX[i]);
	burbuja(pX, n);
	printf("Vector ordenado:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i + 1, pX[i]);
	free(pX);
	getchar();
	getchar();
	return 0;
}
