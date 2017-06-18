// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*
Función: Calcula el valor aproximado de 0.5 mediante series.
Se pide el número de iteraciones. Probando con mas de 10000 iteraciones comienza a dar resultaados erroneos.
Se inicia el contador i en 0 al igual que nuestra variable resultado llamada d05.
Se hace un ciclo while donde se suma el valor resultado en forma de serie.
Se calcula 1.0 / ((2 * i + 1)*(2 * i + 3)))
Al final se imprime el resultado.
*/
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

