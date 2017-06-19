// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Imprimir en un archivo de texto un vector con números aleatorios y luego ordenados.
La función str2num toma como argumento de entrada un caracter. Lo qque hace es transformarlo en un número. 
Se necesita ya que nuestro programa ocupa argumentos de entrada, estos se guardan en char *argv[] el cual es tipo char y por lo tanto no podemos trabajar con este.
Se hizo primero la impresión del caracter que obtenía la computadora sin la función y luego se ajustó para que cada número en letra fuera su correspondiente en dígito.
En la función main se abre un docuemnto de texto con FILE *fp y fp = fopen("Prueba.txt", "wt") wt significa 'write text' es un archivo de escritura. Escribe sobre el mismo archivo ya abierto.
Dependiendo de la cantidad de argumentos se toman como valores de numero de elementos (n), máximo y mínimo.
Para eso se hace un switch que toma por argumento a argc que es el número de argumentos de entrada. Si no ingresa ninguno se piden con main los 3 elementos. Si se da 1 entonces se guarda n con str2num() y así sucesivamente.
Si los valores máximo y mínimo están invertidos entonces se intercambian. Se inicializa el puntero pA con malloc para crear n espacios vacíos.
Luego con un ciclo for se asignan valores aleatorios. Se imprime en el documento de texto con fprintf() los valores de pA desordenados.
Se hace un ordenamiento burbuja en el puntero. Posteriormente se imprime el vector ordenado en el docuemnto de texto. 
Se debe de cerrar el docuento de texto al igual que el puntero pA debido a que usamos memoria dinámica.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CZ 48

int str2num(char *str)
{
	int num, j;
	num = 0;
	j = str[0]==45? 1 : 0;
	while (str[j] != '\0')
	{
		num *= 10;
		num += (int)(str[j] - CZ);
		j++;
	}
	num = str[0] == 45 ? -num : num;
	return num;
}

int main(int argc, char *argv[])
{
	int i, j, n, min, max, *pA, aux;
	FILE *fp;
	srand(time(NULL));
	fp = fopen("Prueba.txt", "wt");
	switch (argc)
	{
	case 1:
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
		printf("Ingrese el valor minimo: ");
		scanf("%d", &min);
		printf("Ingrese el valor maximo: ");
		scanf("%d", &max);
		break;
	case 2:
		n = str2num(argv[1]);
		printf("Ingrese el valor minimo: ");
		scanf("%d", &min);
		printf("Ingrese el valor maximo: ");
		scanf("%d", &max);
		break;
	case 3:
		n = str2num(argv[1]);
		min = str2num(argv[2]);
		printf("Ingrese el valor maximo: ");
		scanf("%d", &max);
		break;
	default:
		n = str2num(argv[1]);
		min = str2num(argv[2]);
		max = str2num(argv[3]);
	}
	while (n < 1)
	{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}
	if (min > max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
	}
	printf("%d\t%d\t%d\n", n, min, max);
	pA = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		pA[i] = (max - min)*rand() / RAND_MAX + min;
	fprintf(fp, "Aleatorios\n");
	for (i = 0; i < n; i++)
		fprintf(fp, "A[%d] = %d\n", i+1, pA[i]);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if (pA[i] > pA[j])
			{
				aux = pA[i];
				pA[i] = pA[j];
				pA[j] = aux;
			}
	fprintf(fp, "Ordenado.\n");
	for (i = 0; i < n; i++)
		fprintf(fp, "A[%d] = %d\n", i + 1, pA[i]);
	fclose(fp);
	free(pA);
	getchar();
	return 0;
}
