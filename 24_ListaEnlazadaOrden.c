// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
Programaci�n en Ingenier�a*/

/*
Hacer una base de datos de un paciente y ordenarlos.
Esta es una lista enlazada simple de paceinte. Primero se declara la estructura paciente. Tiene el puntero siguiente y tambien ordenar.
Se toma la función num_elem del ejercicio anterior y la función imprimir es muy similar solo que en esta imprime el peso, la edad, la estatura y la temperatura.
La función burbuja tiene como argumento un puntero de tipo paciente. Se crea un doble puntero tipo paciente. Se inicializa este con malloc. Se copia lt1 en lt2.
Se hace el algorimo burbuja que ordena segun la edad comparando con lt2.
Dentro de un ciclo for se establece la lista simple formada por los elementos de lt2 con lt2[i]->s = lt2[i+1];
Se hace que el siguiente del último elemento sea igual a NULL.
Dentro del main() se pide el nombre con un do while y getchar lo cual hace que no tenga problemas con los saltos de líneas ni espacios. Se piden los demás datos.
Luego se ordena el nuevo elemento con la funcion burbuja porque es el metodo elegido en la estructura.
Se hacen las conexiones de lista enlazada simple como en el ejercicio 22.
Luego se imprimen los pacientes.
*/
#include <stdio.h>
#include <stdlib.h>

#define NC 50

typedef struct paciente {
	char nom[NC];
	int edad;
	float peso;
	float est;
	float temp;
	struct paciente* (*ordenar)(struct paciente* lt1);
	struct paciente *s;
}paciente;

int num_elem(paciente *lt1)
{
	if (lt1 == NULL)
		return 0;
	else
		return num_elem(lt1->s) + 1;
}

paciente* burbuja(paciente *lt1)
{
	paciente **lt2;
	int n, i, j;
	n = num_elem(lt1);
	lt2 = (paciente**)malloc(n*sizeof(paciente*));
	for (i = 0; i < n; i++)
	{
		lt2[i] = lt1;
		lt1 = lt1->s;
	}
	for(i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (lt2[i]->edad > lt2[j]->edad)
			{
				lt1 = lt2[j];
				lt2[j] = lt2[i];
				lt2[i] = lt1;
			}
	lt1 = lt2[0];
	for (i = 0; i < n - 1; i++)
		lt2[i]->s = lt2[i+1];
	lt2[n-1]->s = NULL;
	return lt1;
}

int imprimir(paciente *lt1)
{
	printf("%s\n", lt1->nom);
	printf("Edad: %d\n", lt1->edad);
	printf("Peso: %f\n", lt1->peso);
	printf("Estatura: %f\n", lt1->est);
	printf("Temperatura: %f\n\n", lt1->temp);
	if (lt1->s == NULL)
		return 1;
	else
		return imprimir(lt1->s) + 1;
}

int main(int argc, char *argv[])
{
	paciente *lt1, *lt2, *nv;
	int op, i, n;
	char c;
	lt1 = NULL;
	lt2 = lt1;
	nv = NULL;
	do {
		nv = (paciente*)malloc(sizeof(paciente));
		printf("Ingrese el nombre: ");
		i = 0;
		do {
			c = getchar();
			nv->nom[i++] = c;
		} while ((c!=10)&&(c!='\0')&&(i<NC));
		nv->nom[i - 1] = '\0';
		printf("Ingrese la edad: ");
		scanf("%d", &nv->edad);
		printf("Ingrese el peso: ");
		scanf("%f", &nv->peso);
		printf("Ingrese la estatura: ");
		scanf("%f", &nv->est);
		printf("Ingrese la temperatura: ");
		scanf("%f", &nv->temp);
		nv->ordenar = burbuja;
		nv->s = NULL;
		if (lt1 == NULL)
		{
			lt1 = nv;
			lt2 = lt1;
		}
		else
		{
			lt2->s = nv;
			lt2 = nv;
		}
		printf("Desea ingresar un nuevo paciente: ");
		scanf("%d", &op);
		getchar();
	} while (op);
	n = imprimir(lt1);
	lt1 = lt1->ordenar(lt1);
	n = imprimir(lt1);
	getchar();
	getchar();
	return 0;
}
