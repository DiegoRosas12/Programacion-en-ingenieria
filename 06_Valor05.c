// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

int main()
{
	float d05;
	int i, n;
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	i = 0;
	d05 = 0;
	while (i < n)
	{
		d05 += (1.0 / ((2 * i + 1)*(2 * i + 3)));
		i++;
	}
	printf("0.5 = %f\n", d05);
	getchar();
	getchar();
    return 0;
}

