// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Leer un archivo binario e imprimir una lista de alumnos.
Este programa solo puede funcionar habiendo ejecutado el programa anterior que generaba a "Datos.bin".
Se declara una estructura llamada Alum. Se abre un archivo fp. Leugo se lee Datos.bin con fopen_s(&fp, "Datos.bin", "r+b");
r+b lee binarios.
Luego con fread se lee a varible n. Se crea el espacio para x con malloc y luego se lee x del archivo con fread(x, sizeof(Alum), n, fp);
Al final se imprimen los datos de los alumnos. Se libera la memoria.
*/
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
