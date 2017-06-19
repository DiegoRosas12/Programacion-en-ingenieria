// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Hacer una lista de alumnos y guardarlo en un archivo binario.
Se crea una estructura llamada Alum. Se abre un archivo fp y se pregunta por el número de estudiantes.
Luego se inicia un puntero x tipo alumno con calloc. Ahora utilizamos calloc para iniciar los espacios en 0 en lugar de en blanco.
Con un ciclo for se pide el NUA y dentro del for hay otro ciclo que guarda la calificación de las materias y suma las calificaiones en prom.
Esta es la razón de que se use calloc, porque se generarían problemas al hacer operaciones con espacios vacíos en lugar de ceros.
Al final se divide el promedio entre el número de materias.
Se abre un archivo llamado 'Datos.bin'. En este se guardan los valores n y x.
Se cierra el archivo fp y se libera x.
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
	do {
		printf("Ingrese el numero de estudiantes: ");
		scanf("%d", &n);
	} while (n<1);
	x = (Alum*)calloc(n, sizeof(Alum));
	for (i = 0; i < n; i++)
	{
		printf("Ingrese el NUA: ");
		scanf("%d", &((x+i)->NUA));  // x[i].NUA == (x+i)->NUA == *(x+i).NUA
		for (j = 0; j < NM; j++)
		{
			printf("Calificacion %d: ", j + 1);
			scanf("%f", &aux);
			(x + i)->Mat[j] = (int)(aux * 10);
			(x + i)->prom += aux;
		}
		x[i].prom /= NM;
	}
	fopen(&fp, "Datos.bin", "w+b");
	fwrite(&n, sizeof(int), 1, fp);
	fwrite(x, sizeof(Alum), n, fp);
	fclose(fp);
	free(x);
	getchar();
	getchar();
	return 0;
}
