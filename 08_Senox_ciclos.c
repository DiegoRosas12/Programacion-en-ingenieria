// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Calcular el valor aproximado de la funcion seno.
Se piden el valor de x así como las iteraciones que se hacen.
Calculamos si cada termino de la iteración tendrá signo positivo o negativo con la variable sig = 1-2*(i%2)
Después se hacen dos ciclos en el primero se multiplican todos los coeficientes x de la serie hasta 2*i+1 veces.
En el segundo se multiplican los valores de nuestra variable fn que funciona como factorial.
Al final se guardan estos valores en otras variables para no afectar su valor.
El resultado final se calcula sumando todos los términos de (sig*num / den).
Se imprime el resultado.
*/

#include <stdio.h>
#include <math.h>

int main()
{
	float x, sx, num, den, px, fn;
	int i, j, n, sig;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	printf("Ingrese el numero de iteraciones: ");
	scanf("%d", &n);
	for (i = 0, sx = 0; i < n; i++)
	{
		sig = 1-2*(i%2);
		for (j = 0, px = 1; j < (2 * i + 1); j++)
			px *= x;
		for (j = 0, fn = 1; j < (2 * i + 1); j++)
			fn *= (j+1);
		den = fn;
		num = px;
		sx += (sig*num / den);
	}
	printf("sin(%f) = %f\n", x, sx);
	getchar();
	getchar();
    return 0;
}

