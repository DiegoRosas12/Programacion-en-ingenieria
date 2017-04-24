//
//  main.c
//  pi
//
//  Created by Diego Eduardo Rosas González on 02/02/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>

int main() {
    float pi;
    int i, sgn, n;
    printf("Ingrese el número de iteraciones\n");
    scanf("%d",&n);
    // i < 2*n porque se incrementa el doble así que se necesita poner el doble de iteraciones
    for (i=1, sgn=1, pi=0; i<(2*n); i+=2, sgn *= (-1))
        // Si se pone 1/i en lugar de 1.0/i entonces el resultado siempre será entero
        pi += sgn*(1.0 / i);
    pi *=4;
    printf("Pi = %f", pi);
    getchar();
    getchar();
    return 0;
}
