// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*
Función: Calcular el valor aproximado de la función seno.
Las funciones están en forma imperativa. 
Para este programa se utilizan 4 funciones. La primera calcula el seno de manera parecida a los programas anteriores.
La función seno manda a llamar a la funcion pot() que es la que calcula el valor de una variable x a una potencia n.
También llama a fact2(). La diferencia de esta función con respecto a fact() es que es recursiva.
En fact2() se manda a llamar a sí misma con la diferencia de que disminuye en 1 al valor n dado.
Cuando el valor de n es igual a 0 entonces devuelve 1 que multiplica a todos los valores anteriores de n.
Va desde el número más chico al más grande.
En la función main() se pide el valor de x y el número de iteraciones. Luego se imprime el valor.
*/

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