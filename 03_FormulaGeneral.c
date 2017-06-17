// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	División de Ingenierías del Campus Irapuato-Salamanca
	Programación en Ingeniería*/

#include <stdio.h>
#include <math.h>

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

