// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

int main()
{
	float ca, co, h;
	printf("Ingrese el cateto opuesto: ");
	scanf_s("%f", &co);
	printf("Ingrese el cateto adyacente: ");
	scanf_s("%f", &ca);
	h = sqrt(ca*ca+pow(co, 2));
	printf("La hipotenusa es %f.\n", h);
	getchar();
	getchar();
    return 0;
}

