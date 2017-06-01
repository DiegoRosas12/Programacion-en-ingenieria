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

typedef struct oAlum {
	int i;
	struct oAlum *a, *s;
}oAlum;

int main(int argc, char *argv[])
{
	Alum *x;
	oAlum *ox, *nx;
	int n, i, j;
	float aux;
	FILE *fp;
	fopen_s(&fp, "Datos.bin", "r+b");
	fread(&n, sizeof(int), 1, fp);
	x = (Alum*)malloc(n * sizeof(Alum));
	fread(x, sizeof(Alum), n, fp);
	printf("NUA\tMaterias\t\t\t\tPromedio\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", x[i].NUA);
		for (j = 0; j < NM; j++)
			printf("%.2f\t", ((float)x[i].Mat[j]) / 10);
		printf("%.2f\n", x[i].prom);
	}
	printf("\n\n");
	fclose(fp);
	ox = NULL;
	for (i = 0; i < n; i++)
	{
		nx = (oAlum*)malloc(sizeof(oAlum));
		nx -> i = i;
		if (ox == NULL)
		{
			ox = nx;
			ox->a = NULL;
			ox->s = NULL;
		}
		else
		{
			while (ox->a != NULL)
				ox = ox->a;
			while ((x[ox->i].prom > x[nx->i].prom)&&(ox->s!=NULL))
				ox = ox->s;
			if (x[ox->i].prom < x[nx->i].prom)
			{
				nx->a = ox->a;
				nx->s = ox;
				ox->a = nx;
			}
			else
			{
				nx->s = NULL;
				nx->a = ox;
				ox->s = nx;
			}
		}
	}
	while (ox->a != NULL)
		ox = ox->a;
	printf("Ordenada\nNUA\tMaterias\t\t\t\tPromedio\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", x[ox->i].NUA);
		for (j = 0; j < NM; j++)
			printf("%.2f\t", ((float)x[ox->i].Mat[j]) / 10);
		printf("%.2f\n", x[ox->i].prom);
		if (ox->s != NULL)
			ox = ox->s;
	}
	while (ox->a != NULL)
		ox = ox->a;
	while (ox->s != NULL)
	{
		ox = ox->s;
		free(ox->a);
	}
	free(ox);
	free(x);
	getchar();
	getchar();
	return 0;
}
