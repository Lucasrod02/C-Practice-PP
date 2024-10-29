#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char titulo[50];
	char director[50];
	int cantPersonas;
}pelicula;

void listarPeliculas(FILE *archivo){
	pelicula p;
	rewind(archivo);
	
	printf("\n--- Listado de Películas ---\n");
	while (fread(&p, sizeof(pelicula), 1, archivo)) {
        printf("Título: %s, Personas: %d\n", p.titulo, p.cantidadPersonas);
    }
}

int main(){
	FILE *archivo;

	if ((archivo = fopen("TITULOS.DAT", "w+")) == NULL) {
	    printf("Error al abrir TITULOS.DAT\n");
	    return 1;
	}
	
	listarPeliculas(archivo);
	
	
}