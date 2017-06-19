// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/


/*
Función: Calcular la media de un arreglo de elementos.
Este programa calcula la media mediante dos formas distintas.
La primera función suma los valores del arreglo x en un ciclo for.
El valor de la media, que se guarda en med, es dividida entre el número de elementos. Regresa ese valor.
La segunda función llamada media2() es recursiva. Para que el contador no borre su valor se hace de tipo estático.
Si el contador es menor que el número de elementos entonces hace a c = al valor x entre el numero de elementos n.
Dentro de el arreglo x se incrementa i en 1.
Se manda a llamar la función dentro de la función y se le suma el valor c.
El límite del calculo de la función estña cuando i es igual que n, ahí se van sumando todos los valores de c.
Dentro de la función main() se pide el número de datos y se comprueba que no sea mayor al espacio asignado al inicio del programa con #define.
También se comprueba de que no sea menor a uno.
Con un ciclo for se van pidiendo todos los valores del arreglo x de tamaño n.
Se mandan llamar a ambas funciones y se imprimen ambos resultados.
*/

#include <stdio.h>
#include <math.h>

#define N 20



float media(float X[], int n)
{
	int i;
	float med;
	for (i = 0, med = 0; i < n; med+=X[i++]);
	return med/n;
}

float media2(float x[], int n)
{
	static int i = 0;
	float c;
	if (i < n)
	{
		c = x[i++] / n;
		return media2(x, n) + c;
	}
	else
		return 0;
}

int main()
{
	float X[N], med, med2;
	int n, i;
	do {
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	} while ((n<1)||(n>N));
	printf("Ingrese el valor de los elementos:\n");
	for (i = 0; i < n; i++)
	{
		printf("X[%d] = ", i+1);
		scanf("%f", &X[i]);
	}
	med = media(X, n);
	med2 = media2(X, n);
	printf("El valor del vector capturado es:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	printf("La media es %f\n", med);
	printf("La media es %f\n", med2);
	getchar();
	getchar();
    return 0;
}
