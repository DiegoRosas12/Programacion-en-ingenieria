// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>
/*
Función: Calcula el valor de x por medio de la fórmula general.
De forma silimar al programa 2. Se separan los casos en la que la raíz cuadrada es negativa y cuando es positiva.
La diferencia con el program aanterior es que en este ocupamos un "if else" en lugar de la forma simple de cond? true: false;
Se piden los valores de los tres coeficientes. Luego se compueba si (b^2 < 4*a*c). Con el if else se separan los cálculos si es verdadera o falsa la condición.
Al final se imprimen ambos valores de X1 y X2 para los dos casos.
*/
int main()
{
	float a, b, c, r2, xr1, xi1, xr2, xi2, cond;
	printf("Ingrese el coeficiente cuadratico: ");
	scanf("%f", &a);
	printf("Ingrese el coeficiente lineal: ");
	scanf("%f", &b);
	printf("Ingrese el coeficiente independiente: ");
	scanf("%f", &c);
	cond = (pow(b, 2) < (4 * a*c));
	if(cond)
	{
		r2 = sqrt(4 * a * c - pow(b, 2));
		xr1 = -b / (2 * a);
		xr2 = xr1;
		xi1 = r2 / (2 * a);
	}
	else
	{
		r2 = sqrt(pow(b, 2) - 4 * a * c);
		xr1 = (-b + r2) / (2 * a);
		xr2 = (-b - r2) / (2 * a);
		xi1 = 0;
	}
	xi2 = -xi1;
	printf("f(x)=%.2fx^2%+.2fx%+.2f=0\n", a, b, c);
	printf("x1=%.2f%+.2fi\nx2=%.2f%+.2fi\n", xr1, xi1, xr2, xi2);
	getchar();
	getchar();
    return 0;
}

