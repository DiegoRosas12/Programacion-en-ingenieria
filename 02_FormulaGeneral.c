// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

#include <stdio.h>
#include <math.h>

/*Función: este programa obtiene el valor de x en una ecuacion de tipo ax^2+bx+c. Los valores de estos tres coeficientes son pedidos.
Debido a que dentro de la raiz cuadrada se pueden obtener números negativos y eso haría un número imaginario se establecen condiciones que,
en el caso de que se forme un número negatvo se invierten los restandos. Las demás condiciones hacen los calculos correspondientes si hay valor imaginario o no.
Esto se hace con la condición simple cond? true: false.
También se encuentra x1 y x2 de los casos reales e imaginarios.
Al final se imprimen sus componentes reales y también imaginarios */
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

