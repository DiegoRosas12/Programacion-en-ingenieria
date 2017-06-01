// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
División de Ingenierías del Campus Irapuato-Salamanca
Programación en Ingeniería*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lt {
	float e, p;
	struct lt *a, *s;
}lt;

lt* inicio(lt *lt1)
{
	if (lt1->a == NULL)
		return lt1;
	else
		return inicio(lt1->a);
}

int liberar(lt * lt1)
{
	lt1 = inicio(lt1);
	while (lt1->s != NULL)
	{
		lt1 = lt1->s;
		free(lt1->a);
	}
	free(lt1);
	return 0;
}

int imprimir(lt * lt1) 
{
	int i=1;
	lt1 = inicio(lt1);
	while (lt1!=NULL)
	{
		printf("%d. Peso: %f, Estatura: %f\n", i++, lt1->p, lt1->e);
		lt1 = lt1->s;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	lt *lt1, *nv;
	int op;
	lt1 = NULL;
	nv = NULL;
	do {
		nv = (lt*)malloc(sizeof(lt));
		printf("Ingrese la estatura: ");
		scanf("%f", &(nv->e));
		printf("Ingrese el peso: ");
		scanf("%f", &(nv->p));
		if (lt1 == NULL)
		{
			lt1 = nv;
			lt1->s = NULL;
			lt1->a = NULL;
		}
		else
		{
			while (lt1->a != NULL)
				lt1 = lt1->a;
			while ((lt1->e < nv->e) && (lt1->s != NULL))
				lt1 = lt1->s;
			if ((lt1->s == NULL) && (lt1->e < nv->e))
			{
				nv->s = NULL;
				nv->a = lt1;
				lt1->s = nv;
			}
			else
			{
				nv->s = lt1;
				nv->a = lt1->a;
				if (lt1->a != NULL)
					lt1->a->s = nv;
				lt1->a = nv;
			}
		}
		printf("Desea ingresar un nuevo elemento: ");
		scanf("%d", &op);
	} while (op);
	imprimir(lt1);
	getchar();
	getchar();
	liberar(lt1);
	return 0;
}
