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
	int i, n;
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	for (i = 0, pi = 0; i < n; i++)
		pi += ((1-2*(i%2))*(1.0/(2*i+1)));
	pi *= 4;
	printf("PI = %f\n", pi);
	getchar();
	getchar();
    return 0;
}

