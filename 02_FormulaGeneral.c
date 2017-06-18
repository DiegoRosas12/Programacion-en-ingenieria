// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*Función: */
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
	r2 = cond? sqrt(4 * a * c - pow(b, 2)) : sqrt(pow(b, 2) - 4 * a * c);
	xr1 = cond? -b / (2 * a) : (-b + r2) / (2 * a);
	xr2 = cond? xr1 : (-b - r2) / (2 * a);
	xi1 = cond? r2 / (2 * a) : 0;
	xi2 = -xi1;
	printf("f(x)=%.2fx^2%+.2fx%+.2f=0\n", a, b, c);
	printf("x1=%.2f%+.2fi\nx2=%.2f%+.2fi\n", xr1, xi1, xr2, xi2);
	getchar();
	getchar();
    return 0;
}

