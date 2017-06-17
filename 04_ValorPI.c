// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

int main()
{
	float pi;
	int i, sgn, n;
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	for (i = 1, sgn = 1, pi = 0; i <= 2*n; i += 2, sgn *= (-1))
		pi += sgn*(1.0 / i);
	pi *= 4;
	printf("PI = %f\n", pi);
	getchar();
	getchar();
    return 0;
}

