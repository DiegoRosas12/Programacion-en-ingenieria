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
	fopen_s(&fp, "Datos.bin", "r+b");
	fread(&n, sizeof(int), 1, fp);
	x = (Alum*)malloc(n*sizeof(Alum));
	fread(x, sizeof(Alum), n, fp);
	printf("NUA\tMaterias\t\t\tPromedio");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", x[i].NUA);
		for (j = 0; j < NM; j++)
			printf("%f\t", ((float)x[i].Mat[j])/10);
		printf("%f", x[i].prom);
	}
	fclose(fp);
	free(x);
	getchar();
	getchar();
	return 0;
}
