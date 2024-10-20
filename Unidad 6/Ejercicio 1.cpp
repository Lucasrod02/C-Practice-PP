#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nom[30];
    int edad;
} asistente;

void carga(FILE *archi) {
    asistente c;
    printf("Ingrese el nombre del asistente, FIN para terminar: ");
    gets(c.nom);
    while (strcmp(c.nom, "FIN") != 0) {
        printf("Ingrese la edad: ");
        scanf("%d", &c.edad);
        fflush(stdin);
        fwrite(&c, sizeof(c), 1, archi);
        printf("Ingrese el nombre del asistente, FIN para terminar: ");
        gets(c.nom);
    }
}

void mostrarMayoresDe40(FILE *archi) {
    asistente c;
    
    rewind(archi); // vuelve al inicio del archivo
    
    fread(&c, sizeof(c), 1, archi);
    printf("Asistentes mayores de 40 años:\n");
    while (!feof(archi)) {
        if (c.edad > 40) {
            printf("Nombre: %s\n", c.nom);
        }
        fread(&c, sizeof(c), 1, archi);
    }
}

void calcularPromedioEdad(FILE *archi, float *promedio) {
    asistente c;
    int suma = 0, cant = 0;
    
    rewind(archi);
    
    fread(&c, sizeof(c), 1, archi);
    while (!feof(archi)) { // feofasdad sirve para comprobar el fin del archivo
        suma += c.edad;
        cant++;
        fread(&c, sizeof(c), 1, archi);
    }
    
    if (cant > 0) {
        *promedio = (float)suma / cant;
    } else {
        *promedio = 0;
    }
}

int main() {
    FILE *archi;
    float promedio;

    if ((archi = fopen("jornada.dat", "w+")) == NULL) {
        printf("Error al abrir el archivi.\n");
        return 1;
    }

    carga(archi);
    
    mostrarMayoresDe40(archi);
    
    calcularPromedioEdad(archi, &promedio);
    printf("Edad promedio de los asistentes: %.2f\n", promedio);
    
    fclose(archi);

    return 0;
}