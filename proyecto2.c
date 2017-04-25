//Proyecto 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define CZ 48


int main(int argc, char *argv[]) {
    float n, max, min, P[N];
    /*FILE *fp;
    fp = fopen("Analisis_estadistico.txt", "wb");
    */
    srand(time(NULL));
    switch (argc) {
        case 1:
          printf("Ingrese el número de elementos: ");
          scanf("%f", &n);
          printf("Ingrese el valor minimo: ");
		  scanf("%f", &min);
		  printf("Ingrese el valor maximo: ");
		  scanf("%f", &max);
            break;
        case 2:
          printf("Ingrese el número de elementos: ");
          scanf("%f", &n);
          printf("Ingrese el valor minimo: ");
		  scanf("%f", &min);
		  printf("Ingrese el valor maximo: ");
		  scanf("%f", &max);
        case 3:
          printf("Ingrese el número de elementos: ");
          scanf("%f", &n);
          printf("Ingrese el valor minimo: ");
		  scanf("%f", &min);
		  printf("Ingrese el valor maximo: ");
		  scanf("%f", &max);
		break;
        default:
            break;
    }
    if (max < min) {
        max = max + min;
        min = max - min;
        max = max - min;
    } 
    printf("Max: %f.3\nMin: %f.3\n",max,min);
    //fclose(fp);
    


    return 0;
}