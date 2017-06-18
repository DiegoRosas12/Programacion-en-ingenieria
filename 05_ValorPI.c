// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>
/*
Función: Calcular el valor aproximado de pi 
Primero se pregunta el número de iteraciones.
Luego se ejecuta el ciclo donde se suma el valor de pi con el anterior valor.
A diferencia del ejercicio 4 en este no es necesario multiplicar n por 2 para que se ejecuten todas las iteraciones.
Se ocupa i%2 porque sólo puede dar como resultado 0 o 1 dependiendo si i es par o impar.
Al final el resultado se multilplica por 4 y se imprime.
*/
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

