// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Ordenar un arreglo y calcular su media.
El programa tiene dos funciones de ordenamiento de tipo burbuja. La diferencia está en que una toma como argumentos un puntero y la otra un doble puntero.
Lo que significa que uno funciona trabajando con la dirección de la posición del valor y el otro con la dirección de esa dirección.
En la función main() se pide el número de elementos y el máximo y el mínimo. 
Se inicializan ambos punteros con malloc. Para el puntero simple es pX = (float*)malloc(n * sizeof(float)); y para el doble es ppX = (float**)malloc(n * sizeof(float*));
Se hace un ciclo for donde se llena cada espacio de pX con valores aleatorios.
Luego se le indica al doble puntero que debe de ser igual a la posición del puntero con *(ppX + i) = pX + i;
Se suman los valores de pX en la variable media y se imprimen los valores de pX.
Luego se divide la media entre el número de elementos.
Se ordena el vector copia (el de doble puntero) con la función burbuja2().
Se imprimen el vector ordenado y el desordenado con ciclos for. El ordenado es el que está en pX a ese no lo hemos modificado.
El vector ppX como habíamos dicho anteriormente fue sobre el que se hizo el ordenamiento.
*/

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
