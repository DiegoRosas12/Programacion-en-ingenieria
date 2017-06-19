// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Calcula el valor proximado de pi
Se pide el número de repeticiones del ciclo.
El valor se calcula mediante un ciclo for el cual en cada iteración suma a la variable pi 1/2*i haciendo este término positivo o negativo en cada iteración.
El final del ciclo está dado por 2*n porque se incrementa i de dos en dos.
Si no pusieramos 2*n el ciclo se ejecutaría solo la mitad de las iteraciones
Al final este valor se multiplica por 4 y se imprime. 
*/

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

