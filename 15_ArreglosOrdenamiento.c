// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

float media(float X[], int n)
{
	int i;
	float med;
	for (i = 0, med = 0; i < n; med+=X[i++]);
	return med/n;
}

float media2(float x[], int n)
{
	static int i = 0;
	float c;
	if (i < n)
	{
		c = x[i++] / n;
		return media2(x, n) + c;
	}
	else
		return 0;
}

// Algoritmo burbuja
int burbuja(float X[], int n)
{
	int i, j;
	for (i = 0; i < (n - 1); i++)
		for (j = i + 1; j < n; j++)
			if (X[i] > X[j])
			{
				X[i] = X[i] + X[j];
				X[j] = X[i] - X[j];
				X[i] = X[i] - X[j];
			}
	return 0;
}

int intercambio(float X[], int n)
{
	int i, j;
	float aux;
	for (i = 1; i < n; i++)
	{
		j = i-1;
		aux = X[i];
		while (aux<X[j])
		{
			X[j + 1] = X[j];
			j--;
			if (j == -1)
				break;
		}
		X[j+1] = aux;
	}
	return 0;
}

int main()
{
	float X[N], med, med2, max, min, aux;
	int n, i;
	srand(time(NULL));
	do {
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	} while ((n<1)||(n>N));
	printf("Ingrese el valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if (min > max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
		/*
		aux = min;
		min = max;
		max = aux;
		*/
	}
	printf("Maximo: %f\nMinimo: %f\n", max, min);
	printf("El valor del vector generado es:\n");
	for (i = 0; i < n; i++)
	{
		X[i] = (max - min)*rand() / RAND_MAX + min;
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	med = media(X, n);
	med2 = media2(X, n);
	intercambio(X, n);
	printf("El valor del vector ordenado es:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	printf("La media es %f\n", med);
	printf("La media es %f\n", med2);
	getchar();
	getchar();
    return 0;
}
