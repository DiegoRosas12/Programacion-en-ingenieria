// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

int main()
{
	int i, n;
	printf("Ingrese el numero de maximo: ");
	scanf("%d", &n);
	for (i = 2; i <= n; i += 2)
	{
		printf("%d\t", i);
		if (!(i % 10))
			continue;
		printf("%d\n", i);
	}
	getchar();
	getchar();
    return 0;
}

