// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Calcular el seno de un valor x.
Para este programa se ocupa solamente una funcion.
La sunción seno2() está en forma declarativa y además es recursiva.
Para guardar el valor de las variables fc e i se usa la palabra reservada 'static'. Si no se usara entonces el valor previo de las varibles se perdería.
Esta función al igual que la del programa anterior calcula fc con (x/(2*i))*(x/(2*i+1)). La función recursiva sirve como si fuera un ciclo y por eso el valor anterior de fc se multiplica por su nuevo valor.
El valor de cada término que se suma finalmente se calcula en c.
La función dice que cuando ha llegado al núemro final de iteraciones (se pone n+1 ya que hay un i++ antes) entonces devuelva el valor x.
Cuando va saliendo de cada iteración se suma el valor de c donde se hacen nuestros cálculos y luego se calcula al termino anterior.
Esto funciona como si fuera un ciclo y se pusiera +=
Dentro de la función main() se pide el valor de x y el número de iteraciones n.
Se imprime el resultado.
*/

#include <stdio.h>
#include <math.h>


float seno2(float x, int n)
{
	static float fc = x;
	static int i = 1;
	float c;
	fc *= ((x/(2*i))*(x/(2*i+1)));
	i++;
	c = (2 * (i % 2) - 1)*fc;
	if (i < (n+1))
		return seno2(x, n)+c;
	else
		return x;
}

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
	sx = seno2(x, n);
	printf("sin(%f) = %f\n", x, sx);
	getchar();
	getchar();
    return 0;
}
