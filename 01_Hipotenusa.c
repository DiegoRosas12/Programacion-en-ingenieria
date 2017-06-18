// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/


/*Función: Este programa calcula la hipotenusa de un triángulo rectángulo dados los dos catetos.
Se ocupa la librería math.h porque para el cálculo se usa la función pow. 
La fórmula es la raíz cuadrada de la multiplicación de los catetos más el cateto opuesto al cuadrado*/

#include <stdio.h>
#include <math.h>

int main()
{
	float ca, co, h;
	printf("Ingrese el cateto opuesto: ");
	scanf("%f", &co);
	printf("Ingrese el cateto adyacente: ");
	scanf("%f", &ca);
	h = sqrt(ca*ca+pow(co, 2));
	printf("La hipotenusa es %f.\n", h);
	getchar();
	getchar();
    return 0;
}

