// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/


#include <stdio.h>
#include <stdlib.h>

typedef struct lt {
	float e, p;
	struct lt *s;
}lt;

int num_elem(lt *plt)
{
	if (plt == NULL)
		return 0;
	else
		return 1 + num_elem(plt->s);
}

int liberar(lt *plt)
{
	lt *plt2;
	if (plt == NULL)
		return 0;
	plt2 = plt;
	plt = plt->s;
	free(plt2);
	return liberar(plt);
}

float prom(lt *plt, int b, int n)
{
	if (plt == NULL)
		return 0;
	else
		return (b?plt->p:plt->e)/n+prom(plt->s, b, n);
}

int imprimir(lt *plt)
{
	int i = 1;
	while (plt!=NULL)
	{
		printf("%d. Estatura: %f\t Peso: %f\n", i++, plt->e, plt->p);
		plt = plt->s;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	lt *plt1, *plt2, *nv;
	int op, n;
	float pe, pp;
	plt1 = NULL;
	plt2 = NULL;
	do {
		nv = (lt*)malloc(sizeof(lt));
		printf("Ingrese la estatura: ");
		scanf("%f", &(nv->e));
		printf("Ingrese el peso: ");
		scanf("%f", &(nv->p));
		if (plt1 == NULL)
		{
			plt1 = nv;
			plt2 = plt1;
		}
		else
		{
			plt2->s = nv;
			plt2 = nv;
		}
		nv->s = NULL;
		printf("Desear ingresar otro elemento: ");
		scanf("%d", &op);
	} while (op);
	n = num_elem(plt1);
	printf("El numero de datos es %d.\n", n);
	pe = prom(plt1, 0, n);
	pp = prom(plt1, 1, n);
	printf("El promedio de la estatura es %f\n", pe);
	printf("El promedio del peso es %f\n", pp);
	imprimir(plt1);
	getchar();
	getchar();
	liberar(plt1);
	return 0;
}
