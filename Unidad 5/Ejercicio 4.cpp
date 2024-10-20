#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numPlan;
    int DNI;
    char NyA;
    int CantCuotasPaid;
}adjudicatario;

struct nodo{
    adjudicatario dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &cabeza, puntero &cabeza2){
    cabeza=NULL;
    cabeza2=NULL;
}

void insertar(puntero &cabeza){
    int plan;
    puntero nuevo;
    printf("Ingrese el numero de plan, 0 para finalizar\n");
    scanf("%d", &plan);
    while(plan != 0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        nuevo->dato.numPlan=plan;
        printf("Ingrese el DNI: ");
        scanf("%d", &nuevo->dato.DNI);
        printf("Ingrese el nombre y apellido: ");
        scanf("%s", &nuevo->dato.NyA);
        printf("Ingrese la cantidad de cuotas pagadas: ");
        scanf("%d", &nuevo->dato.CantCuotasPaid);

        nuevo->sig=cabeza;
        cabeza=nuevo;

        printf("Ingrese el numero de plan, 0 para finalizar\n");
        scanf("%d", &plan);
    }
}

void may30Cuotas(puntero lista1, puntero &lista2){
    puntero nuevo;
    while(lista1 != NULL){
        if(lista1->dato.CantCuotasPaid > 30){
            nuevo=(puntero)malloc(sizeof(struct nodo));
            nuevo->dato= lista1->dato;
            nuevo->sig= lista2;
            lista2= nuevo;
        }
        lista1=lista1->sig;
    }
}

void mostrarLista2(puntero &lista2){
    while (lista2 != NULL) {
        printf("Numero de Plan: %d, DNI: %d, Nombre: %s, Cuotas Pagadas: %d\n",lista2->dato.numPlan, lista2->dato.DNI, lista2->dato.NyA, lista2->dato.CantCuotasPaid);
        lista2 = lista2->sig;
    }
}

int main(){
    puntero cabeza;
    puntero cabeza2;
    crear(cabeza, cabeza2);
    insertar(cabeza);
    may30Cuotas(cabeza, cabeza2);
    mostrarLista2(cabeza2);
    
}