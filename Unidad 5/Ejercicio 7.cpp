#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 4

typedef struct{
    char NyA[40];
    char PaisResidenc[20];
    int cantGoles;
}jugador;

struct nodo{
    jugador datos;
    struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct{
    char NomPais[20];
    int cantEstadios;
    puntero cabeza;
}mundial;

void insertar(puntero &cabeza){
    char pais[20];
    puntero nuevo;
    printf("--- Carga de Jugador ---\n");
    printf("Ingrese pais de residencia, FIN para finalizar: ");
    scanf("%s", &pais);
    while(strcmp(pais,"FIN")!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        strcpy(nuevo->datos.PaisResidenc, pais);
        printf("Ingrese el NyA: ");
        scanf("%s", nuevo->datos.NyA);
        while(getchar() != '\n');
        printf("Ingrese la cantidad de goles: ");
        scanf("%d", &nuevo->datos.cantGoles);

        nuevo->sig=cabeza;
        cabeza=nuevo;

        printf("--- Carga de Jugador ---\n");
        printf("Ingrese pais de residencia, FIN para finalizar: ");
        scanf("%s", &pais);
    }
}

void cargaArre(mundial mundiales[M]){
    int i;
    for(i=0; i<M; i++){
        printf("1: 2010, 2: 2014, 3: 2018, 4: 2022.\n");
        printf("----- Pais Nro %d -----\n", i+1);
        printf("Ingrese el nombre: ");
        scanf("%s", &mundiales[i].NomPais);
        printf("Ingrese la cantidad de estadios: ");
        scanf("%d", &mundiales[i].cantEstadios);
        
        mundiales[i].cabeza=NULL;
        insertar(mundiales[i].cabeza);
    }
}

int mundialIngresado(puntero cabeza, int &cantJugArg, int mas5Goles){
    if(cabeza == NULL){
		return mas5Goles;
    }
    if(strcmp(cabeza->datos.PaisResidenc, "Argentina")==0){
            cantJugArg++;
        }
        if(cabeza->datos.cantGoles > 5){
            mas5Goles++;
        }
        return mundialIngresado(cabeza->sig, cantJugArg, mas5Goles);
}

void nYAIngresado(puntero &cabeza, char teclado2[]) {
    puntero actual = cabeza;
    puntero anterior = NULL;
    
    while (actual != NULL) {
        if (strcmp(actual->datos.NyA, teclado2) == 0) {
            if (anterior == NULL) {
                cabeza = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            free(actual);
            printf("Jugador %s eliminado.\n", teclado2);
            return;
        }
        anterior = actual;
        actual = actual->sig;
    }
    printf("Jugador %s no encontrado.\n", teclado2);
}

void jug3oMasGoles(puntero listaOG, puntero &listaNueva){
    puntero nuevo;
    while(listaOG != NULL){
        if(listaOG->datos.cantGoles >= 3){
            nuevo=(puntero)malloc(sizeof(struct nodo));
            nuevo->datos=listaOG->datos;
            nuevo->sig=listaNueva;
            listaNueva=nuevo;
        }
    }
}

int main(){
    mundial mundiales[M];
    int teclado, cantJugArg=0, mas5Goles=0, mas5, i;
    char teclado2[40];
    puntero cabeza2;
    cargaArre(mundiales);

    printf("Ingrese un numero de mundial: ");
    scanf("%d", &teclado);
    mas5=mundialIngresado(mundiales[teclado].cabeza, cantJugArg, mas5Goles);
    printf("Cantidad de jugadores de ARG: %d\n", cantJugArg);
    printf("Cantidad de jugadores con mas de 5 goles: %d", mas5);

    printf("Ingresar nombre y apellido del jugador: ");
    scanf("%s", &teclado2);

    for(i=0; i<M; i++){
        printf("----- Mundial %d -----", i+1);
        nYAIngresado(mundiales[i].cabeza, teclado2);
    }
    
    for(i=0; i<M; i++){
        jug3oMasGoles(mundiales[i].cabeza, cabeza2);
    }

    while(cabeza2 != NULL){
        printf("Nombre: %s, Pais: %s, Goles: %d\n", cabeza2->datos.NyA, cabeza2->datos.PaisResidenc, cabeza2->datos.cantGoles);
        cabeza2 = cabeza2->sig;
    }
    
    
}