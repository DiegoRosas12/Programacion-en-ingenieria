// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

int main()
{
	float x, sx, num, den, px, fn;
	int i, j, n, sig;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	for (i = 0, sx = 0; i < n; i++)
	{
		sig = 1-2*(i%2);
		for (j = 0, px = 1; j < (2 * i + 1); j++)
			px *= x;
		for (j = 0, fn = 1; j < (2 * i + 1); j++)
			fn *= (j+1);
		den = fn;
		num = px;
		sx += (sig*num / den);
	}
	printf("sin(%f) = %f\n", x, sx);
	getchar();
	getchar();
    return 0;
}

