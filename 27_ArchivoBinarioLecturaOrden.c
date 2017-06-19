// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Leer un archivo binario con datos de alumno.
El programa tiene dos estructuras una llamada Alum y otra oAlum la cual tiene el puntero anterior y siguiente.
Se abre el archivo Datos.bin con fp = fopen("Datos.bin", "r+b");.
Se lee del archivo la variable n, se crea el espacio tipo Alum x y se lee del archivo. Se imprime NUA MAterias y promedio de x.
Hay variables tipo oAlum llamadas ox y nx. Estas funcionarán de un modo parecido a lt1 y nv. Se hace un enlace doble para formar las listas.
La diferencia es que al agregar un nuevo elemento se acomoda con (x[ox->i].prom > x[nx->i].prom)&&(ox->s!=NULL) ox = ox->s;
Esto permite ordenar la lista. Al final se imprime la lista ordenada.
Se liberan ox y x.
*/
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
	fp = fopen("Datos.bin", "r+b");
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
