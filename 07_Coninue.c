// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

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

