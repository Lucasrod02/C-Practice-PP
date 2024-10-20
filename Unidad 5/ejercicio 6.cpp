#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nro;
}entero;

struct nodo{
    entero dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;


void insertarOrdenado(puntero &cabeza, int num){
    if(cabeza == NULL || cabeza->dato.nro > num){
        puntero nuevo;
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->dato.nro=num;
        nuevo->sig=cabeza;
        cabeza=nuevo;
    }else{
        insertarOrdenado(cabeza->sig, num);
    }
}

int ultimoEsPar(puntero cabeza){
    if (cabeza->sig == NULL){
        return cabeza->dato.nro % 2 == 0;
    }
    return ultimoEsPar(cabeza->sig);
}

void mostrarInverso(puntero cabeza){
    if (cabeza != NULL){
        mostrarInverso(cabeza->sig);
        printf("%d ", cabeza->dato.nro);
    }
}

int ingresarNum(puntero cabeza, int num, int i){
    if(cabeza != NULL){
        if(cabeza->dato.nro == num){
            return i;
        }else{
            return ingresarNum(cabeza->sig, num, i+1);
        }
    }
    return -1;
}

int main(){
    int num, i=0, posicion;
    puntero cabeza;
    cabeza=NULL;
    printf("Ingrese un Nro, 0 para finalizar: ");
    scanf("%d", &num);
    while(num != 0){
        insertarOrdenado(cabeza, num);
        printf("Ingrese un Nro, 0 para finalizar: ");
        scanf("%d", &num);
    }
    
    if(cabeza != NULL){
        if(ultimoEsPar(cabeza)){
            printf("El ultimo numero es par.\n");
        }else{
            printf("El ultimo numero no es par.\n");
        }
    }

    printf("Lista en orden inverso: ");
    mostrarInverso(cabeza);
    printf("\n");

    printf("Ingresa numero a buscar: ");
    scanf("%d", &num);
    
    posicion=ingresarNum(cabeza, num, i);
    if(posicion != -1){
        printf("El numero se encuentra en la posicion: %d\n", posicion);
    } else {
        printf("El numero no se encuentra en la lista.\n");
    }
}