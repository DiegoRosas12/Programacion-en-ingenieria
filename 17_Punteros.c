// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, i;
	float *pX, max, min, media;
	do{
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
	pX = (float*)malloc(n*sizeof(float));
	printf("El vector X es:\n");
	for (i = 0, media = 0; i < n; i++)
	{
		pX[i] = ((max-min)*rand())/RAND_MAX+min;
		media += pX[i];
		printf("X[%d] = %f\n", i+1, *(pX+i));
	}
	media /= n;
	printf("La media es %f\n", media);
	free(pX);
	getchar();
	getchar();
    return 0;
}
