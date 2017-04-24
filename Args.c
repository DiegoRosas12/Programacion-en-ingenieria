// Ejemplos.cpp: define el punto de entrada de la aplicación de consola.
// Mario Alberto Ibarra Manzano
/*  Universidad de Guanajuato
División de Ingenierías del Campus Irapuato-Salamanca
Programación en Ingeniería*/
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define CZ 48
 
int str2num(char *str)
{
    int num, j;
    num = 0;
    j = str[0]==45? 1 : 0;
    while (str[j] != '\0')
    {
        num *= 10;
        num += (int)(str[j] - CZ);
        j++;
    }
    num = str[0] == 45 ? -num : num;
    return num;
}
 
int main(int argc, char *argv[])
{
    int i, j, n, min, max, *pA, aux;
    FILE *fp;
    srand(time(NULL));
    fp = fopen("Prueba.txt", "wt");
    switch (argc)
    {
    case 1:
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
        printf("Ingrese el valor minimo: ");
        scanf("%d", &min);
        printf("Ingrese el valor maximo: ");
        scanf("%d", &max);
        break;
    case 2:
        n = str2num(argv[1]);
        printf("Ingrese el valor minimo: ");
        scanf("%d", &min);
        printf("Ingrese el valor maximo: ");
        scanf("%d", &max);
        break;
    case 3:
        n = str2num(argv[1]);
        min = str2num(argv[2]);
        printf("Ingrese el valor maximo: ");
        scanf("%d", &max);
        break;
    default:
        n = str2num(argv[1]);
        min = str2num(argv[2]);
        max = str2num(argv[3]);
    }
    while (n < 1)
    {
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    }
    if (min > max)
    {
        min = min + max;
        max = min - max;
        min = min - max;
    }
    printf("%d\t%d\t%d\n", n, min, max);
    pA = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        pA[i] = (max - min)*rand() / RAND_MAX + min;
    fprintf(fp, "Aleatorios\n");
    for (i = 0; i < n; i++)
        fprintf(fp, "A[%d] = %d\n", i+1, pA[i]);
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if (pA[i] > pA[j])
            {
                aux = pA[i];
                pA[i] = pA[j];
                pA[j] = aux;
            }
    fprintf(fp, "Ordenado.\n");
    for (i = 0; i < n; i++)
        fprintf(fp, "A[%d] = %d\n", i + 1, pA[i]);
    fclose(fp);
    free(pA);
    getchar();
    return 0;
}