// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*
Función: Calcular el valor aproximado de la función seno.
A diferencia del ejercicio anterior en este se utilizan funciones en lugar de hacer los cálculos dentro del main().
La primera función es la sustitución a la función pow(). En esta multiplicamos una variable x un número n de veces mediante el ciclo for.
La segunda función devuelve el factorial de un número dado. Se multiplican los números 1, 2, 3 ,... entre ellos mismos y devuelve ese valor.
Sólo toma como entrada un número n.
La tercera función es la que calcula el seno. Al igual que la función anterior lo calcula con una sumatoria de los términos (sig*num / den).
En la función main se piden el valor de x y el numero de iteraciones.
Luego se imprimen los valores.
*/

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

