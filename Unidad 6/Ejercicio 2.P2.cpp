#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int nroReg;
    char resultadoParci;
}alumno;

void insertarOrdenado(alumno arr[], int *n, alumno nuevo) {
    int i = *n - 1;

    // Desplazar elementos hacia la derecha para hacer espacio
    while (i >= 0 && arr[i].nroReg > nuevo.nroReg) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = nuevo;  // Insertar en la posicion correta
    (*n)++;  // Aumentar el tamaño del arreglo
}

void carga(FILE *archi) {
    alumno c;
    alumno arr[100];  // Suponemos un maximo de 100 alumnos
    int n = 0;  // Contador de alumnos en el arreglo
    printf("Ingrese NRO de registro, 0 para finalizar: ");
    scanf("%d", &c.nroReg);
    while (c.nroReg != 0) {
        printf("Ingrese nombre del alumno: ");
        fflush(stdin);
        gets(c.nombre);
        printf("Ingrese resultado del parcial (A: Aprobado, R: Reprobado): ");
        c.resultadoParci = getch();
        fflush(stdin);

        // Insertar en el arreglo de manera ordenada
        insertarOrdenado(arr, &n, c);

        printf("Ingrese NRO de registro, 0 para finalizar: ");
        scanf("%d", &c.nroReg);
    }

    // Escribir el arreglo ordenado en el archivo
    for (int i = 0; i < n; i++) {
        fwrite(&arr[i], sizeof(alumno), 1, archi);
    }
}
}

int main() {
    FILE *archi;

    if ((archi = fopen("alumnosAL.dat", "w+")) == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    carga(archi);
    fclose(archi);
    return 0;
}