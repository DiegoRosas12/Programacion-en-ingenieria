//
//  main.c
//  arreglos
//
//  Created by Diego Eduardo Rosas González on 23/02/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define N 20

float media(float X[], int n){
    int i;
    float med;
    for (i=0, med = 0; i < n; med+=X[i++]);
      
        
        return med/n;
}


int main() {
    float X[N];
    float med;
    int n=0, i=0;
    do {
        printf("Ingrese el numero de datos ");
        scanf("%d",&n);
    }while ((n<1)||(n>N));
    for (i=0; i<n; i++){
        printf("X[%d] = ", i+1);
        scanf("%f",&X[i]);
    }
    for (i=0; i < n; i++)
        printf("X[%d] = %f\n", i+1, X[i]);
    printf("La media es %f\n", med);
    getchar();
    getchar();
    return 0;
}
