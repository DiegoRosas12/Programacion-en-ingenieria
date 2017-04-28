//Proyecto 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000
#define CZ 48


int main(int argc, char *argv[]) {
    float max, min, P[N];
    int opc, n, i = 0, *p;
    /*FILE *fp;
    fp = fopen("Analisis_estadistico.txt", "wb");
    */
    srand(time(NULL));
    switch (argc) {
        case 1:
            printf("1: Entrada de datos manual\n2: Datos aleatorios\n");
            scanf("%i",&opc);
            // Manuales
            if (opc == 1) {
            do {
                printf("Ingrese el número de elementos: ");
                scanf("%i", &n);
                }while(n<1 || n>N);
            for(i = 0;i < n;i++) {
                printf("P[%i] :",i+1);
                scanf("%f",&P[i]);
            }
            // Aleatorios
            }else{
            do {
                printf("Ingrese el número de elementos: ");
                scanf("%i", &n);
                }while(n<1 || n>N);
            printf("Ingrese el valor minimo: ");
            scanf("%f", &min);
            printf("Ingrese el valor maximo: ");
            scanf("%f", &max);
            if (max < min) {
            max = max + min;
            min = max - min;
            max = max - min;
            } 
            p = (int*)malloc(n*sizeof(int));
	        for (i = 0; i < n; i++)
		    p[i] = (max - min)*rand() / RAND_MAX + min;
            for(i=0;i<n;i++)
            printf("p[%i]: %.3f\n", i, P[i]);
            break;
        case 2:
            do {
                printf("Ingrese el número de elementos: ");
                scanf("%i", &n);
                }while(n<1 || n>N);
            printf("Ingrese el valor minimo: ");
            scanf("%f", &min);
            printf("Ingrese el valor maximo: ");
            scanf("%f", &max);
            break;
        case 3:
            do {
                printf("Ingrese el número de elementos: ");
                scanf("%i", &n);
                }while(n<1 || n>N);
            printf("Ingrese el valor minimo: ");
            scanf("%f", &min);
            printf("Ingrese el valor maximo: ");
            scanf("%f", &max);
          break;
//
        default:
            break;
    }
    
    //fclose(fp);
    
    }
    for(i=0;i<n;i++)
        printf("P[%i]: %.3f\n", i, P[i]);
    free(p);
return 0;
}