#include <stdio.h>
#include <stdlib.h>

void cargaArre(int *arre, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("Ingrese el valor de la posicion nro %d: ", i+1);
        scanf("%d", &arre[i]);
    }
}

void prodEscalar(int *arreA, int *arreB, int tam){
    int i, prodesca=0;
    for(i=0; i<tam; i++){
        prodesca+=arreA[i]*arreB[i];
    }
    printf("El producto escalar de A y B es: %d\n", prodesca);
}

void numerosPares(int i, int *arreA, int tam, int &numPares){
    if(i<tam){
        if(arreA[i]%2 == 0){
            numPares++;
        }
        numerosPares(i+1, arreA, tam, numPares);
    }
}

void arregloPares(int *arreA, int numPares, int tam){
    int i, j=0, *arrePares;
    arrePares=(int*)malloc(sizeof(int)*numPares);
    for(i=0; i<tam; i++){
        if(arreA[i]%2 == 0){
            arrePares[j]=arreA[i];
            j++;
        }
    }
    printf("----- Valores pares -----\n");
    for(i=0; i<j; i++){
        printf("%d |", arrePares[i]);
    }
    printf("\n");
    free(arrePares);
}

int main(){
    int i=0, tam, *arreA, *arreB, numPares=0;
    
    printf("Ingrese la cantidad de componentes del arreglo: ");
    scanf("%d", &tam);

    arreA=(int*)malloc(sizeof(int)*tam);
    arreB=(int*)malloc(sizeof(int)*tam);

    printf("----- Carga del arreglo nro 1 -----\n");
    cargaArre(arreA, tam);

    printf("----- Carga del arreglo nro 2 -----\n");
    cargaArre(arreB, tam);

    prodEscalar(arreA, arreB, tam);

    numerosPares(i, arreA, tam, numPares);

    arregloPares(arreA, numPares, tam);
    free(arreA);
    free(arreB);
}