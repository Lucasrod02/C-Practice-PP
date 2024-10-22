#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int nroReg;
    char resultadoParci;
}alumno;

void carga(FILE *archi){
    int reg;
    alumno c;
    printf("Ingrese NRO de registro, 0 para finalizar: ");
    scanf("%d", &reg);
    while(reg != 0){
        c.nroReg=reg;
        printf("Ingrese nombre del alumno: ");
        fflush(stdin);
        gets(c.nombre);
        
        printf("Ingrese resulado del parcial (A: Aprobado, R: Reprobado): ");
        c.resultadoParci=getch();
        fflush(stdin);
        fwrite(&c, sizeof(c), 1, archi);

        printf("Ingrese NRO de registro, 0 para finalizar: ");
        scanf("%d", &reg);
    }
}

void mostrar(FILE *archi) {
    alumno c;
    rewind(archi);
    printf("\nInformacion de alumnos:\n");
    while (fread(&c, sizeof(c), 1, archi) == 1) {
        printf("Nombre del Alumno: %s\n", c.nombre);
        printf("NRO de registro: %d\n", c.nroReg);
        printf("Resultado del parcial: %c\n", c.resultadoParci);
        printf("-----------------------------\n");
    }
}

int main(){
    FILE *archi;

    if ((archi = fopen("alumnosPP.dat", "w+")) == NULL) {
        printf("Error al abrir el archivi.\n");
        return 1;
    }
    carga(archi);
    mostrar(archi);
    fclose(archi);
}