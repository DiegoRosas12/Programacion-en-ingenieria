// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*
Función: Imprimir números de dos en dos dos veces excepto los multiplos de 10.
Se hace un ciclo for donde se imprime un número i que incrementa de dos en dos.
Dentro del ciclo hay una condición que comprueba cuando son multiplos de 10 y tiene un continue que hace que se salga del ciclo.

*/

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

