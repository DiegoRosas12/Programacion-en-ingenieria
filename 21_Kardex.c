// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/
/*
Función: Crear un kardex.
Se crean 3 estructuras. Una para guardar nombres, otra para guardar la materia y otra para guardar el kardex general. Con typedef se evita poner struct cada vez que se llama la estructura
La función capturar funciona para ingresar una cadena de texto de manera similar a gets(). Solamente que en gets() no hay un límite de caracteres y por lo tanto es insegura.
Dentro del main() Se abre un archivo de texto fp. Se crea un dato tipo kt llamado kt1. Luego dos punteros tipo UDA.
Se abre un rachivo binario. Si no hay archivo binario con fread se leen kt1 e i. Se usa memoria dinámica para crear los espacios de UDAs en el kardex.
Si i = 0 enotnces se piden los datos del alumno. Hay un ciclo for que llena todos los datos de las materias según el numero que se dió.
Se obtienen los créditos con el cuarto y quinto caracter de la clave de la materia. Si i no es igual a 0 entonces se crean UDA2 con memoria dinámica. Se copian los datos de los UDA1.
Se hace un ciclo for donde se suman las calificaciones y se divide entre el número de estas para obtener el periodo. Tambien el el mismo ciclo se calcula la suma de los creditos cursdos y de los aprobado.
Se calcula el año de egreso con (int)(kt1.Anio_ing + kt1.NPe/2.0);
Luego se imprimen los datos del alumno y sus materias. Se abre un archivo binario donde se guardan kt1, i y UDA1.
Luego se libera la memoria de fp, UDA1 y UDA2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CZ 48
#define NMaxC 288
#define NCP 32
#define NC1 20
#define NC2 40
#define NC3 10

typedef struct nom {
	char AP[NC1];
	char AM[NC1];
	char noms[NC2];
}nom;

typedef struct UDA {
	char nom[NC1];
	char clave[NC3];
	int op;
	float calif;
	int cred;
	int bn;
}UDA;

typedef struct kt {
	nom nom1;
	UDA *UDA1;
	int NUA;
	int NP;
	float NPe;
	float Prom;
	int CC;
	int CA;
	int Anio_ing;
	int Sem_ing;
	int Anio_egr;
}kt;

int capturar(char *str, int n)
{
	int i = 0;
	char c;
	do {
		c = getchar();
		str[i] = c;
		i++;
	} while (c!=10&&i<n);
	str[i - 1] = '\0';
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	kt kt1;
	char fn[20]="Datos.bin";
	int i, j, n, k;
	UDA *UDA1, *UDA2;
	i = 0;
	/*
	printf("Ingrese el nombre del archivo: ");
	scanf("%s", fn);
	*/
	fopen_s(&fp, fn, "rb");
	if (fp != NULL)
	{
		fread(&kt1, sizeof(kt), 1, fp);
		fread(&i, sizeof(int), 1, fp);
		kt1.UDA1 = (UDA*)malloc(i*sizeof(UDA));
		fread(kt1.UDA1, sizeof(UDA), i, fp);
		fclose(fp);
	}
	if (i == 0)
	{
		printf("Ingrese su apellido paterno: ");
		capturar(kt1.nom1.AP, 20);
		printf("Ingrese su apellido materno: ");
		capturar(kt1.nom1.AM, 20);
		printf("Ingrese su(s) nombre(s): ");
		capturar(kt1.nom1.noms, 20);
		printf("Ingrese su NUA: ");
		scanf("%d", &kt1.NUA);
		printf("Ingrese su anio de ingreso: ");
		scanf("%d", &kt1.Anio_ing);
		printf("Ingrese su semestre de ingres: ");
		scanf("%d", &kt1.Sem_ing);
	}
	printf("Ingrese su numero de inscripciones: ");
	scanf("%d", &kt1.NP);
	printf("Numero de UDAs a capturar: ");
	scanf("%d", &n);
	UDA1 = (UDA*)malloc(n*sizeof(UDA));
	for (j = 0; j < n; j++)
	{
		getchar();
		printf("UDA %d\n", j + 1);
		printf("Ingrese el nombre de la UDA: ");
		capturar((UDA1 + j)->nom, 20);
		printf("Ingrese la clave: ");
		capturar(UDA1[j].clave, 10);
		printf("Ingrese la calificacion: ");
		scanf("%f", &(UDA1[j].calif));
		UDA1[j].cred = 10 * UDA1[j].clave[4] + UDA1[j].clave[5] - 11 * CZ;
		if (i == 0)
		{
			UDA1[j].op = 1;
			UDA1[j].bn = 1;
		}
	}
	i += n;
	if (i == 0)
		kt1.UDA1 = UDA1;
	else
	{
		UDA2 = (UDA*)malloc(i*sizeof(UDA));
		for (j = 0; j < (i - n); j++)
		{
			for (k = 0; k < NC1; k++)
				UDA2[j].nom[k] = kt1.UDA1[j].nom[k];
			for (k = 0; k < NC3; k++)
				UDA2[j].clave[k] = kt1.UDA1[j].clave[k];
			UDA2[j].op = kt1.UDA1[j].op;
			UDA2[j].calif = kt1.UDA1[j].calif;
			UDA2[j].cred = kt1.UDA1[j].cred;
			UDA2[j].bn= kt1.UDA1[j].bn;
		}
		for ( ; j < i; j++)
		{
			for (k = 0; k < NC1; k++)
				UDA2[j].nom[k] = UDA1[j - i + n].nom[k];
			for (k = 0; k < NC3; k++)
				UDA2[j].clave[k] = UDA1[j - i + n].clave[k];
			UDA2[j].op = UDA1[j - i + n].op;
			UDA2[j].calif = UDA1[j - i + n].calif;
			UDA2[j].cred = UDA1[j - i + n].cred;
			UDA2[j].bn = UDA1[j - i + n].bn;
		}
	}
	kt1.Prom = 0;
	kt1.CC = 0;
	kt1.CA = 0;
	for (j = 0, n = 0; j < i; j++)
	{
		kt1.Prom += (kt1.UDA1[j].bn*kt1.UDA1[j].calif);
		n += kt1.UDA1[j].bn;
		kt1.CC += (kt1.UDA1[j].bn*kt1.UDA1[j].cred);
		kt1.CA += ((kt1.UDA1[j].calif>=7)*kt1.UDA1[j].cred);
	}
	kt1.Prom /= n;
	kt1.NPe = (int)((kt1.NP*NMaxC) / kt1.CA + 0.99);
	kt1.Anio_egr = (int)(kt1.Anio_ing + kt1.NPe/2.0);
	printf("----------------------------------------------\n");
	printf("%s %s, %s\n", kt1.nom1.AP, kt1.nom1.AM, kt1.nom1.noms);
	printf("NUA: %d\n", kt1.NUA);
	printf("Numero de inscripciones: %d\n", kt1.NP);
	printf("Promedio: %f\n", kt1.Prom);
	printf("Creditos Cursados: %d\n", kt1.CC);
	printf("Creditos Aprobados: %d\n", kt1.CA);
	printf("Anio de egreso: %d", kt1.Anio_egr);
	fopen_s(&fp, fn, "wb");
	fwrite(&kt1, sizeof(kt), 1, fp);
	fwrite(&i, sizeof(int), 1, fp);
	fwrite(kt1.UDA1, sizeof(UDA), i, fp);
	fclose(fp);
	free(UDA1);
	free(UDA2);
	getchar();
	return 0;
}
