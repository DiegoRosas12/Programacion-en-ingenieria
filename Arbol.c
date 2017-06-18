# include <stdio.h>
//# include <conio.h>
# include <stdlib.h>

//BST Binary Search Tree
typedef struct BST {
   int data;
   struct BST *izq, *der;
} nodo;

nodo *get_nodo() {
   nodo *temp;
   temp = (nodo *) malloc(sizeof(nodo));
   temp->izq = NULL;
   temp->der = NULL;
   return temp;
}

void insert(nodo *raiz, nodo *nuevo_nodo) {
   if (nuevo_nodo->data < raiz->data) {
      if (raiz->izq == NULL)
         raiz->izq = nuevo_nodo;
      else
         insert(raiz->izq, nuevo_nodo);
   }

   if (nuevo_nodo->data > raiz->data) {
      if (raiz->der == NULL)
         raiz->der = nuevo_nodo;
      else
         insert(raiz->der, nuevo_nodo);
   }
}

void inorden(nodo *temp) {
   if (temp != NULL) {
      inorden(temp->izq);
      printf("%d ", temp->data);
      inorden(temp->der);
   }
   printf("\n");
}

void preorden(nodo *temp) {
   if (temp != NULL) {
      printf("%d ", temp->data);
      preorden(temp->izq);
      preorden(temp->der);
   }
   printf("\n");
}


void postorden(nodo *temp) {
   if (temp != NULL) {
      postorden(temp->izq);
      postorden(temp->der);
      printf("%d ", temp->data);
   }
   printf("\n");
}

nodo *buscar(nodo *raiz, int key, nodo **parent) {
   nodo *temp;
   temp = raiz;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\nEl elemento %d esta presente\n", temp->data);
         return temp;
      }
      *parent = temp;

      if (temp->data > key)
         temp = temp->izq;
      else
         temp = temp->der;
   }
   return NULL;
}

int main(int argc, char *argv[]) {
   int opc;
   char opt = 'N';
   int key;
   nodo *nuevo_nodo, *raiz, *tmp, *parent;
   nodo *get_nodo();
   raiz = NULL;

   printf("Programa para arbol de busqueda binario\n");
   do {
      printf("1.Crear\n");
      printf("2.Buscar\n");
      printf("3.Transversas recursivas\n");
      printf("4.Salir\n");
      scanf("%d", &opc);

      switch (opc) {
      case 1:
         do {
            nuevo_nodo = get_nodo();
            printf("Introduce el elemento\n");
            scanf("%d", &nuevo_nodo->data);
            getchar();
            if (raiz == NULL) 
               raiz = nuevo_nodo;
            else
               insert(raiz, nuevo_nodo);

            printf("Quieres ingresar otro elemento?(y/n)\n");
            opt = getchar();
            getchar();
         } while (opt == 'y');
         break;

      case 2:
         printf("Elemento a ingresar: ");
         scanf("%d", &key);

         tmp = buscar(raiz, key, &parent);
         printf("El padre del nodo %d es %d\n", tmp->data, parent->data);
         break;

      case 3:
         if (raiz == NULL)
            printf("El arbol no ha sido creado\n");
         else {
            printf("inorden: \n");
            inorden(raiz);
            printf("Preorden: \n");
            preorden(raiz);
            printf("Postorden\n");
            postorden(raiz);
         }
         break;
      }
   } while (opc != 4);
   return 0;
}

*/ Referencias
    c4learn.com
    /*



