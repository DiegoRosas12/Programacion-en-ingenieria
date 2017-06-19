// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Crear un arreglo y sacar la media con punteros.
Se pide el número de elementos y después el número máximo y mínimo. Si estos están invertidos entonces se intercambian.
Se utilizará memoria dinámica en este programa. El puntero previamente declarado llamado pX se inicializa con pX = (float*)malloc(n*sizeof(float)).
Malloc crea n espacios vacíos.
Después se crea un ciclo for donde para cada espacio se le asigna un número aleatorio con ((max-min)*rand())/RAND_MAX+min.
En el mismo ciclo se suma a la variable media el elemento. Después imprime el elemento con su posición en el arreglo.
La media se divide entre los números de elementos y se imprime.
*/

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
		// *(pX+i)
		printf("X[%d] = %f\n", i+1, pX[i]);
	}
	media /= n;
	printf("La media es %f\n", media);
	free(pX);
	getchar();
	getchar();
    return 0;
}
