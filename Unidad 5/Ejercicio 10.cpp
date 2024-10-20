#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[20];
    float promedio;
    int anoEnCurso;
}alumno;

struct nodo{
    alumno dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct{
    char nombre[20];
    puntero cabeza;
}facultad;

void insertarOrdenado(puntero cabeza, int num){
    if(cabeza == NULL || cabeza->dato.promedio > num){
        puntero nuevo;
        nuevo->dato.promedio=num;
        nuevo->sig=cabeza;
        cabeza=nuevo;
    }else{
        insertarOrdenado(cabeza->sig, num);
    }
}

void insertar(puntero cabeza){
    char alu[20];
    int num;
    puntero nuevo;
    printf("Ingrese nombre del del alumno, FIN para finalizar");
    scanf("%s", &alu);
    while(strcmp(alu,"FIN")==0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        strcpy(nuevo->dato.nombre,alu);
        printf("Ingrese promedio del alumno: ");
        scanf("%d", &num);
        insertarOrdenado(cabeza, num);
        printf("Ingrese año que cursa: ");
        scanf("%d", &nuevo->dato.anoEnCurso);

        
    }
}

void menosInscriptos(puntero cabeza, int fac){
    puntero nuevo
    while(cabeza != NULL){
        if()
    }
}

int main(){
    int fac, i;
    printf("Ingrese el numero de facultades participantes: ");
    scanf("%d", &fac);
    facultad facultades[fac];

    for(i=0;i<fac;i++){
        printf("----- Facultad NRO %d -----\n", i+1);
        printf("Ingrese nombre de la facultad: ");
        scanf(facultades[i].nombre);
        
        facultades[i].cabeza=NULL;
        
        insertar(facultades[i].cabeza);
    }

    for(i=0; i<fac; i++){
        printf("----- Facultad NRO %d -----\n", i+1);
        menosInscriptos(facultades[i].cabeza, fac);
    }
    
}