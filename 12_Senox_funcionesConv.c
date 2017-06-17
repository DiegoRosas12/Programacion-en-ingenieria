// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

float seno(float x, int n)
{
	float sx, fc;
	int i, sg;
	for (i = 0, sx = 0, sg = 1, fc = x; i < n; i++, sg*=(-1))
	{
		sx += (sg*fc);
		fc *= ((x / (2 * i + 2))*(x / (2 * i + 3)));
	}
	return sx;
}

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
