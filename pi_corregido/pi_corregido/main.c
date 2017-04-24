//
//  main.c
//  pi_corregido
//
//  Created by Diego Eduardo Rosas González on 02/02/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    float pi;
    int i, n;
    printf("Ingrese el número de iteraciones\n");
    scanf("%d",&n);
    for (i=0, pi=0; i < n; i++)
        pi += ((1-2*(i%2))*(1.0/(2*i+1)));
        pi *= 4;
    printf("Pi = %f", pi);
    getchar();
    getchar();
    return 0;
}
