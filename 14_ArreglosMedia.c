// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

#define N 20

float media(float X[], int n)
{
	int i;
	float med;
	for (i = 0, med = 0; i < n; med+=X[i++]);
	return med/n;
}

float media2(float x[], int n)
{
	static int i = 0;
	float c;
	if (i < n)
	{
		c = x[i++] / n;
		return media2(x, n) + c;
	}
	else
		return 0;
}

int main()
{
	float X[N], med, med2;
	int n, i;
	do {
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	} while ((n<1)||(n>N));
	printf("Ingrese el valor de los elementos:\n");
	for (i = 0; i < n; i++)
	{
		printf("X[%d] = ", i+1);
		scanf("%f", &X[i]);
	}
	med = media(X, n);
	med2 = media2(X, n);
	printf("El valor del vector capturado es:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	printf("La media es %f\n", med);
	printf("La media es %f\n", med2);
	getchar();
	getchar();
    return 0;
}
