//
//  main.c
//  Memoria_dinamica
//
//  Created by Diego Eduardo Rosas González on 06/03/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int burbuja(float *pX, int n){
    int i, j;
    float aux;
    for (i=0; i < n-1; i++)
        for (j = i+1; j<n; j++)
        if (pX[j] < pX[i]) {
            aux = pX[i];
            pX[i] = pX[j];
            pX[j] = aux;
        }
    
    return 0;
}

/*int burbuja2(float **ppX, int n){
    int i, j;
    float *aux;
    for (i=0; i<n; i++) {
        for (j = i+1; j<n;j++)
            if (<#condition#>) {
                <#statements#>
            }
    }
     
    
}*/
int main(int argc, const char * argv[]) {
    int n, i;
    float *pX,**ppX, max, min, media;
    do{
        printf("Ingrese el número de elementos\n");
        scanf("%d",&n);
    }while (n<1);
    printf("Ingrese el valor maximo\n");
    scanf("%f",&max);
    printf("Ingrese el valor minimo\n");
    scanf("%f",&min);
    if (min > max) {
        max = max + min;
        min = max - min;
        max = max - min;
    }
    srand(time(NULL));
    pX = (float*)malloc(n*sizeof(float));
    for (i=0; i<n; i++) {
        pX[i] = ((max - min)*rand())/RAND_MAX+min;
        ppX[i] = pX + i;
        media += pX[i];
        printf("X[%d] = %f\n",i+1, *(pX+i));
    }
    media /= n;
    //burbuja2(ppX,n);
    burbuja(pX, n);
    printf("\nVector Ordenado\n");
    for (i=0; i < n; i++) {
        printf("X[%d] = %f\n", i+1, pX[i]);
    }
    printf("La media es %f\n", media);
    free(pX);
    getchar();
    getchar();
    return 0;
}
