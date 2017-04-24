//
//  main.c
//  Kardex1
//
//  Created by Diego Eduardo Rosas González on 03/04/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CZ 48
#define NMaxX 288
#define NCP 32

typedef struct nom {
    char AP[20];
    char AM[20];
    char noms[40];
}nom;

typedef struct UDA {
    char nom[20];
    char clave[10];
    int op;
    float calif;
    int cred;
    int bn;
}UDA;

typedef struct kt {
    nom nom1;
    UDA *UDA1;
    int CC;
    int CA;
    int NUA;
    int NP;
    float NPE;
    float prom;
    int Anio_ing;
    int sem_ing;
    int Anio_egr;
    
}kt;


int main(int argc, char *argv[]) {
    
    FILE *fp;
    kt kt1;
    char fn[20];
    int i, n, j;
    UDA * UDA1;
    i = 0;
    printf("ingrese el nombre del archivo: ");
    // fn = %(fn+0)
    scanf("%s", fn);
    fp = fopen(fn, "rb");
    if (fp != NULL){
        
    }
    if (i == 0) {
        printf("Ingrese Apellido paterno: ");
        scanf("%s",kt1.nom1.AM);
        printf("Ingrese Apellido materno: ");
        scanf("%s",kt1.nom1.AM);
        printf("Ingrese su(s) nombre(s)");
        scanf("%s",kt1.nom1.noms);
        printf("Ingrese su NUA: ");
        scanf("%d", &kt1.NUA);
        printf("Ingrese su anio de ingreso");
        scanf("%d", &kt1.Anio_ing);
        printf("Ingrese su semestre de ingreso");
        scanf("%d",&kt1.sem_ing);
    }
    
    printf("Ingrese su numero de inscripciones");
    scanf("%d", &kt1.NP);
    printf("Numero de UDAs a capturar");
    scanf("%d",&n);
    UDA1 = (UDA*)malloc(n*sizeof(UDA));
    
    for (j=0;j<n;j++) {
        printf("UDA %d\n", j+1);
        printf("Ingrese el nombre de la UDA");
        scanf("%s",(UDA1 + j)->nom);
        printf("Ingrese la clave");
        scanf("%s",UDA1[j].clave);
        printf("Ingrese la calificacion");
        scanf("%f", &(UDA1[j].calif));
              UDA1->cred = 10*UDA1->clave[4]+UDA1->clave[5]-11*CZ;
              if (i == 0){
              UDA1[j].op = 1;
            //bn = bandera
              UDA1[j].bn = 1;
              }
        }
              if (i == 0)
              kt1.UDA1 = UDA1;
              
              i += n;
              for (j=0; j<i; j++) {
              kt1.prom += (kt1.UDA1[j].bn*kt1.UDA1[j].calif);
              n += kt1.UDA1[j].bn;
                  kt1.CC += (kt1.UDA1[j].bn*kt1.UDA1[j].cred);
              }
              kt1.prom /= n;
              kt1.NPE = (int)((kt1.NP*NMaxX) / NCP + 0.99);
              kt1.Anio_egr = (int)(kt1.Anio_ing + kt1.NPE/2.0);
              printf("%s %s, %s\n",kt1.nom1.AP, kt1.nom1.AM, kt1.nom1.noms);
              printf("NUA = %d\n", kt1.NUA);
              printf("Promedio: %f\n", kt1.prom);
              printf("Creditos cursados: %d\n", kt1.CC);
              printf("Creditos aprobados: %d\n", kt1.CA);
              printf("Anio de egreso: %d", kt1.Anio_egr);
              
              free(UDA1);
              fclose(fp);
              getchar();
    return 0;
}
