//Ordenamiento burbuja (propio)
//Diego Eduardo Rosas González

#include <stdio.h>
#define N 20

int burbuja(float X[], int n)
{
	int i, j;
	for (i = 0; i < (n - 1); i++)
		for (j = i + 1; j < n; j++)
			if (X[i] > X[j])
			{
				X[i] = X[i] + X[j];
				X[j] = X[i] - X[j];
				X[i] = X[i] - X[j];
			}
	return 0;
}

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
     for(i=0; i < (n-1); i++){
          for(j=(i + 1); j < n; j++){
               if(P[i] > P[j]){
                    P[i] = P[i] + P[j];
                    P[j] = P[i] - P[j];
                    P[i] = P[i] - P[j];
               }
          }
     }
     
     //burbuja(P,n);
     for(i=0; i < n; i++)
          printf("P[%i] = %.3f\n",i+1, P[i]);
     return 0;
}
