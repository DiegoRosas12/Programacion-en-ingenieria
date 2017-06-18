// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*
Función: Calcular el valor aproximado de la función seno.
Se ocupan las mismas funciones que en el programa 09_senox_funcionesDec.c.
La diferencia es que aquí las funciones están en forma imperativa en lugar de declarativa.
*/

float seno(float x, int n);
float pot(float x, int n);
int fact(int n);

int main()
{
	float x, sx;
	int n;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	sx = seno(x, n);
	printf("sin(%f) = %f\n", x, sx);
	getchar();
	getchar();
    return 0;
}

float seno(float x, int n)
{
	float sx, num, den;
	int i, sig;
	for (i = 0, sx = 0; i < n; i++)
	{
		sig = 1 - 2 * (i % 2);
		num = pot(x, 2 * i + 1);
		den = fact(2 * i + 1);
		sx += (sig*num / den);
	}
	return sx;
}

float pot(float x, int n)
{
	float px;
	int i;
	for (i = 0, px = 1; i < n; i++)
		px *= x;
	return px;
}

int fact(int n)
{
	int fn, i;
	for (i = 0, fn = 1; i < n; i++)
		fn *= (i + 1);
	return fn;
}