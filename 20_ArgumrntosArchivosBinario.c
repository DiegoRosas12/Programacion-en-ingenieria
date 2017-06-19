// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Función: Hacer uso de un archivo binario para guardar un arreglo y luego leerlo para ordenarlo.
Al igual que en el programa anterior en este tambien utiliza la función str2num para transformar correctamente los argumentos de entrada a entero.
También mediante argumentos de entrada se piden el número de elementos, maximo y mínimo según el número de argumentos dado.
Se abre un archivo con FILE *fp y fp = fopen("Prueba.bin", "wb"); ahora como usamos wb será un archivo binario.
Se inicializa el puntero pA con malloc. El puntero se llena con números aleatorios. 
Se escribe sobre el docuento con fwrite(). El primer arguento es en dónde se guarda el elemento, el segundo el tamaño del dato, luego el número de elementos y al final el archivo donde se guarda.
Con fwrite se escriben n y pA. Con el algortimo burbuja se ordena pA. Luego se vuelve a escribir pA. Se cierra el archivo fp. Se libera pA.
Se vuelve a abrir el archivo binario con el que habíamos trabajado. Ahora se ocupa fp = fopen("Prueba.bin", "rb"); rb es 'read binary'.
Toma los mismos argumentos que fwrite. El primero es la variable dónde se guardará. Se inicializa un puntero pB.
Luego se imprimen los punteros ordenados y los desordenados
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
	int i, j, n, min, max, *pA, aux, *pB, m;
	FILE *fp;
	srand(time(NULL));
	fp = fopen("Prueba.bin", "wb");
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
		

	fwrite(&n, sizeof(int), 1, fp);
	fwrite(pA, sizeof(int), n, fp);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if (pA[i] > pA[j])
			{
				aux = pA[i];
				pA[i] = pA[j];
				pA[j] = aux;
			}
	fwrite(pA, sizeof(int), n, fp);
	fclose(fp);
	free(pA);
	fp = fopen("Prueba.bin", "rb");
	fread(&m, sizeof(int), 1, fp);
	pB = (int*)malloc(2*m*sizeof(int));
	fread(pB, sizeof(int), 2*m, fp);
	printf("Desordenados\n");
	for (i = 0; i < m; i++)
		printf("A[%d] = %d\n", i+1, pB[i]);

	printf("Ordenados\n");
	for (i = 0; i < m; i++)
		printf("A[%d] = %d\n", i+1, pB[m+i]);
	free(pB);
	fclose(fp);
	getchar();
	return 0;
}
