//Proyecto 2

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float n, max, min;
    FILE *fp;
    fp = fopen("Analisis_estadistico.txt", "wb");
    switch (argc) {
        case 1:
            printf("Ingrese el número de elementos");
            scanf("%f",n);
            break;
        case 2:
            printf()
              
        default:
            break;
    }
    printf("Introduce el número de datos");
    fclose(fp);
    return 0;
}