// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
División de Ingenierías del Campus Irapuato-Salamanca
Programación en Ingeniería*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NM 5

typedef struct Alum {
	int NUA;
	int Mat[NM];
	float prom;
}Alum;

int main(int argc, char *argv[])
{
	Alum *x;
	int n, i, j;
	float aux;
	FILE *fp;
	do {
		printf("Ingrese el numero de estudiantes: ");
		scanf_s("%d", &n);
	} while (n<1);
	x = (Alum*)calloc(n, sizeof(Alum));
	for (i = 0; i < n; i++)
	{
		printf("Ingrese el NUA: ");
		scanf_s("%d", &((x+i)->NUA));  // x[i].NUA == (x+i)->NUA == *(x+i).NUA
		for (j = 0; j < NM; j++)
		{
			printf("Calificacion %d: ", j + 1);
			scanf_s("%f", &aux);
			(x + i)->Mat[j] = (int)(aux * 10);
			(x + i)->prom += aux;
		}
		x[i].prom /= NM;
	}
	fopen_s(&fp, "Datos.bin", "w+b");
	fwrite(&n, sizeof(int), 1, fp);
	fwrite(x, sizeof(Alum), n, fp);
	fclose(fp);
	free(x);
	getchar();
	getchar();
	return 0;
}
