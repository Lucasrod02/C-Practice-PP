#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int DNI;
    int edad;
    char tipo[2];
    char estado[10];
}socio;

void carga(socio *socios, int soc, int i){
    if(i<soc){
        printf("----- Socio Nro %d -----\n", i+1);
        printf("Ingrese el DNI: ");
        scanf("%d", &socios[i].DNI);
        printf("Ingrese la edad: ");
        scanf("%d", &socios[i].edad);
        printf("Ingrese el tipo\n");
        printf("Desde 'A' a la 'J': ");
        scanf("%s", socios[i].tipo);
        printf("Ingrese el estado\n");
        printf("'A' para Activo e 'I' para Inactivo: ");
        scanf("%s", socios[i].estado);

        carga(socios, soc, i+1);
    }
}

void cantSocio(socio *socios, int soc, int &cuantMay40){
    int i;
    for(i=0; i<soc; i++){
        if(socios[i].edad > 40){
            cuantMay40++;
        }
    }
}

void tipoSocio(socio *socios, int soc, int cuantMay40){
    int i, *may40, j=0;
    may40=(int*)malloc(sizeof(int)*cuantMay40);

    for(i=0; i<soc; i++){
        if(socios[i].edad > 40){
            may40[j]=socios[i].edad;
            j++;
        }
    }
    free(may40);
}

// Faltaria hacer el ejercicio C)

int main(){
    int soc, i=0, cuantMay40=0, cuantActivas=0;
    printf("Ingrese la cantidad de socios: ");
    scanf("%d", &soc);
    socio *socios=(socio*)malloc(sizeof(socio)*soc);
    carga(socios, soc, i);

    cantSocio(socios, soc, cuantMay40);
    tipoSocio(socios, soc, cuantMay40);

    free(socios);
}