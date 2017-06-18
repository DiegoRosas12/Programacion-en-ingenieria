#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NM 30

typedef struct fecha{
    int dia;
    char mes[15];
    int anio;
}fecha;

typedef struct materia{
    char clave[10];
    char nombre[100];
    int creditos;
    float calificacion;
}materia;

typedef struct alumno{
    char apaterno[15];
    char amaterno[15];
    char nombre[NM];
    materia mat[NM];
    int nua;
    char email[NM];
    char carrera[NM];
    fecha ingreso;
    struct alumno *s;
}alumno;

int tamanio(alumno *lt)
{
    if(lt==NULL)
        return 0;
    else
        return tamanio(lt->s)+1;
}

alumno *ingresar(alumno *p1)
{
    int op, nm=0;
    char clave[10], nombre[100];
    {
        int ch;
        //EOF=End Of File (fin de archivo)
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    alumno *nv, *aux;
    nv=(alumno*)malloc(sizeof(alumno));
    printf("Nombre(s): ");
    gets(nv->nombre);
    printf("Apellido paterno: ");
    scanf("%s", nv->apaterno);
    printf("Apellido materno: ");
    scanf("%s", nv->amaterno);
    printf("NUA: ");
    scanf("%d", &(nv->nua));
    printf("Email: ");
    scanf("%s", nv->email);
    printf("Carrera: ");
    {
        int ch;
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    gets(nv->carrera);
    printf("Fecha de ingreso.\nDia: ");
    scanf("%d", &(nv->ingreso.dia));
    printf("\nMes: ");
    scanf("%s", nv->ingreso.mes);
    printf("\nAnio: ");
    scanf("%d", &(nv->ingreso.anio));
    nv->s=NULL;
    if(p1==NULL)
        p1=nv;
    else
    {
        aux=p1;
        while(aux->s!=NULL)
            aux=aux->s;
        aux->s=nv;
    }
    printf("\nDesea ingresar materias?\n1. Si\n2. No\nOpcion: ");
    scanf("%d", &op);
    switch(op)
    {
        case 1:
            ;FILE *archivo;
            while(op!=2)
            {
                archivo = fopen("bd_claves.txt", "r");
                if( archivo == NULL)
                {
                    printf("Error al abrir archivo");
                    return 0;
                }
                printf("\nIngrese la clave de la materia: ");
                scanf("%s", p1->mat[nm].clave);
                while(!feof(archivo))
                {
                    fscanf(archivo, "%s", clave);
                    fgets(nombre, 100, archivo);
                    if(!strcmp(p1->mat[nm].clave, clave))
                    {
                        strcpy(p1->mat[nm].nombre, nombre);
                    }
                }
                printf("\nIngrese calificacion de la materia: ");
                scanf("%f", &(nv->mat[nm].calificacion));
                printf("\nDesea agregar otra materia?\n1. Si\n2. No\nOpcion: ");
                scanf("%d", &op);
                if(op==1)
                {
                    nm++;
                }
            }
            printf("Las materias agregadas son:\n");
            for( op=0;op<=nm;op++){
                printf("\n%s", p1->mat[op].nombre);
            }
            fclose(archivo);
            break;
        case 2 :
            break;
    }
    return p1;
}

void mostrar(alumno *p1)
{
    int i=1;
    printf("Nombre\t\t\t\tNUA\t\tCarrera\n");
    while(p1!=NULL)
    {
        printf("%d.- %s %s %s\t%d, %s\t\n", i++, p1->nombre, p1->apaterno, p1->amaterno, p1->nua, p1->carrera);
        p1=p1->s;
    }
}

void buscar(alumno *p1)
{
    int op, i=1, nua, nm=0;
    float prom=0;
    char nombre[30], aP[15],aM[15];
    printf("\nDesea buscar por nombre o NUA?\n1.Nombre\n2.NUA\nOpcion: ");
    scanf("%d", &op);
    switch(op)
    {
        case 1: 
            printf("Ingrese nombre del alumn@: ");
            {
                int ch;
                while((ch = getchar()) != EOF && ch != '\n');
            }
            gets(nombre);
            printf("\nIngrese apellido paterno del alumn@: ");
            scanf("%s", aP);
            printf("\nIngrese apellido materno del alumn@: ");
            scanf("%s", aM);
            printf("\n\nNombre\t\t\t\tNUA\t\tCarrera\n");
            while(p1!=NULL)
            {

                if(!strcmp(p1->nombre, nombre)&&!strcmp(p1->apaterno, aP)&&!strcmp(p1->amaterno, aM))
                {
                    printf("%d. %s %s %s\t%d, %s\t\n", i++, p1->nombre, p1->apaterno, p1->amaterno, p1->nua, p1->carrera);
                	printf("Desea mostrar las materias? (0=No; Otro no.=Si)\n");
                	scanf("%d",&op);
                	if(op){
                		while(p1->mat[nm].calificacion!=0)
                		{
                		printf("%sCalificacion: %f\n", p1->mat[nm].nombre, p1->mat[nm].calificacion);
                		prom+=p1->mat[nm].calificacion;
                		nm++;
                }
                printf("El promedio es: %f\n", prom/nm);
            }
				}
                p1=p1->s;
            }
            if(i==1)
            {
                printf("No se encontraron resultados.\n");
            }
            break;
        case 2: 
            printf("Ingrese NUA: ");
            scanf("%d", &nua);
            printf("\n\nNombre\t\t\t\t\t\tNUA\t\tCarrera\n");
            while(p1!=NULL)
            {

                if(nua==p1->nua)
                {
                    printf("%d. %s %s %s\t%d, %s\t\n", i++, p1->nombre, p1->apaterno, p1->amaterno, p1->nua, p1->carrera);
                }
 	              	if(op){
               		while(p1->mat[nm].calificacion!=0)
               		{
               		printf("%sCalificacion: %f\n", p1->mat[nm].nombre, p1->mat[nm].calificacion);
               		prom+=p1->mat[nm].calificacion;
	           		nm++;
                }
                
                printf("El promedio es: %f\n", prom/nm);
            }
                p1=p1->s;
            }
            if(i==1)
            {
                printf("No se encontraron resultados.\n");
            }
            break;
    }
}

int liberar(alumno *p1)
{
    alumno *aux;
    if(p1!=NULL)
    {
        aux=p1;
        p1=p1->s;
        free(aux);
        return liberar(p1);
    }
    else
        return 0;
}

alumno *eliminar(alumno *p1)
{
    int in, n;
    alumno *aux1, *aux2;
    mostrar(p1);
    printf("Selecciona el registro a eliminar: ");
    scanf("%d", &in);
    n=tamanio(p1);
    if(in>0&&in<=n)
    {
        aux2=p1;
        aux1=p1;
        for(; in>1; in--)
        {
            aux1=aux2;
            aux2=aux2->s;
        }
        if(aux1!=aux2)
            aux1->s=aux2->s;
        else
            p1=p1->s;
        free(aux2);
    }
    return p1;
}

void guardar(alumno *p1)
{
    int n, i;
    FILE *fp;
    n=tamanio(p1);
    fp=fopen("db.bin", "wb");
    fwrite(&n, sizeof(int), 1, fp);
    for(i=0; i<n; i++, p1=p1->s)
        fwrite(p1, sizeof(alumno), 1, fp);
    fclose(fp);
}

alumno *leer(alumno *p1)
{
    int m, n, i, op;
    FILE *fp;
    alumno *nv, *aux;
    m=tamanio(p1);
    fp=fopen("db.bin", "rb");
    printf("Desea editar? (0=No; Otro=Si) ");
    fread(&n, sizeof(int), 1, fp);
    scanf("%d", &op);
    if(op==0)
    {
        liberar(p1);
        for(i=0; i<n; i++)
        {
            nv=malloc(sizeof(alumno));
            if(i==0)
            {
                p1=nv;
                aux=nv;
            }
            fread(nv, sizeof(alumno), 1, fp);
            aux->s=nv;
            aux=nv;
        }
        aux->s=NULL;
    }
    else
    {
        if(p1!=NULL)
        {
            for(i=0; i<n; i++)
            {
                nv=malloc(sizeof(alumno));
                if(i==0)
                {
                    aux=p1;
                    while(aux->s!=NULL)
                        aux=aux->s;
                }
                fread(nv, sizeof(alumno), 1, fp);
                aux->s=nv;
                aux=nv;
            }
            aux->s=NULL;
        }
        else
        {
            for(i=0; i<n; i++)
            {
                nv=malloc(sizeof(alumno));
                if(i==0)
                {
                    p1=nv;
                    aux=nv;
                }
                fread(nv, sizeof(alumno), 1, fp);
                aux->s=nv;
                aux=nv;
            }
            aux->s=NULL;
        }
    }
    fclose(fp);
    free(fp);
    return p1;
}

int main(int argc, char *argv[])
{
    alumno *p1=NULL;
    int op;
    do{
        printf("MENU PRINCIPAL - Teclee una opcion:\n");
        printf("1. Ingresar un alumno.\n");
        printf("2. Mostrar alumnos.\n");
        printf("3. Eliminar registro.\n");
        printf("4. Buscar.\n");
        printf("5. Guardar registros.\n");
        printf("6. Cargar registros.\n");
        printf("7. Salir\n");
        printf(">> ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                p1=ingresar(p1);
                break;
            case 2:
                mostrar(p1);
                break;
            case 3:
                p1=eliminar(p1);
                break;
            case 4:
                buscar(p1);
                break;
            case 5:
                guardar(p1);
                break;
            case 6:
                p1=leer(p1);
                break;
            case 7:
                liberar(p1);
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }while(op!=7);
    printf("\n");
    return 0;
}
