// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

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

