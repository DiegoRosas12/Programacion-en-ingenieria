//Intercambio

#include <stdio.h>
#define N 20

int main() {
     int i = 0, j = 0, n, aux;
     float P[N];
     /*printf("Numero de elementos:");
     scanf("%i",&n);
     */
     do {
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	} while ((n<1)||(n>N));

     for(i=0; i < n; i++) {
          printf("P[%i]:",i+1);
          scanf("%f",&P[i]);
     }
     for(i=0; i < n; i++)
          printf("P[%i] = %.3f\n",i+1, P[i]);
     
     printf("Ordenados:\n");
     for (i=1; i<n; i++) {
          j = i - 1;
          aux = P[i];
          while(aux < P[j]){
               P[j+1] = P[j];
               j--;
               if (j == -1)
                    break;
          }
          P[j+1] = aux; 
     }
     
     for(i=0; i < n; i++)
          printf("P[%i] = %.3f\n",i+1, P[i]);
     return 0;
}