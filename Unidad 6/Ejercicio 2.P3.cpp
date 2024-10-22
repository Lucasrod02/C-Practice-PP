#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int nroReg;
    char resultadoParci;
}alumno;

void mostrarAprobados(FILE *pp, FILE *al){
    alumno alumPP, alumAL;
    rewind(pp);
    rewind(al);
    fread(&alumPP, sizeof(alumno), 1, pp);
    fread(&alumAL, sizeof(alumno), 1, al);

    printf("Alumnos que aprobaron ambas materias:\n");
    
    while(!feof(pp) && !feof(al)){
        if(alumPP.nroReg == alumAL.nroReg){
            if (alumPP.resultadoParci == 'A' && alumAL.resultadoParci == 'A') {
                printf("NRO de Registro: %d, Nombre: %s\n", alumPP.nroReg, alumPP.nombre);
            }
            fread(&alumPP, sizeof(alumno), 1, pp);
            fread(&alumAL, sizeof(alumno), 1, al);
        } else if (alumPP.nroReg < alumAL.nroReg) {
            // Avanzar archivo de Programación Procedural
            fread(&alumPP, sizeof(alumno), 1, pp);
        } else {
            // Avanzar archivo de Álgebra Lineal
            fread(&alumAL, sizeof(alumno), 1, al);
        }
    }
}

int main(){
    FILE *pp, *al;
    if ((pp = fopen("alumnosPP.dat", "rb")) == NULL) {
        printf("Error al abrir alumnosPP.dat\n");
        return 1;
    }
    if ((al = fopen("alumnosAL.dat", "rb")) == NULL) {
        printf("Error al abrir alumnosAL.dat\n");
        return 1;
    }

    mostrarAprobados(pp, al);
}