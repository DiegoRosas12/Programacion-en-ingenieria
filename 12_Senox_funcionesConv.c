// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Calcular el valor aproximado de la función seno.
En este programa sólo se ocupa una función en formma declarativa.
No se utilizan otras funciones para calcular la potencia o el factorial.
La función tiene dos parámetros de entrada los cuales son el valor x y el número de iteraciones n.
Para el signo se utiliza la variable sg la cual es multiplicada por -1 en cada iteracion para ir alternando los signos.
sx es el valor de los términos independientes los cuales se suman entre ellos y son multiplicados por el signo.
fc se calcula dividiendo el valor de x entre (2 * i + 2))*(x / (2 * i + 3))
En la función main se piden el valor de x y el número de iteraciones. Luego se imprime el resultado.
*/
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
