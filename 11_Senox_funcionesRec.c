// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

float seno(float x, int n);
float pot(float x, int n);
int fact(int n);
int fact2(int n);

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
		den = fact2(2 * i + 1);
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

int fact2(int n)
{
	if (n != 0)
		return fact2(n - 1)*n;
	else
		return 1;
}