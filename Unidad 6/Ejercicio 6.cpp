#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char titulo[50];
	char director[50];
	int cantPersonas;
}pelicula;


void carga(FILE *archivo){
	pelicula p;

    fpos_t x;

    fseek(archivo, 0, SEEK_END);
    fgetpos(archivo, &x);

    int cod = (int)((x / sizeof(pelicula)) + 1);
    p.codigo = cod;

    printf("El  codigo de la pelicula es: %d \n", p.codigo);
    printf("Ingrese el titulo de la pelicula: ");
    getchar();
    gets(p.titulo);
    printf("Ingrese el nombre del director: ");
    fflush(stdin);
    gets(p.director);

    printf("\n Ingrese la cantidad de personas: ");
    scanf("%d", &p.cantPersonas);
    fwrite(&p, sizeof(p), 1, archivo);
}
    


void listarPeliculas(FILE *archivo){
	pelicula p;
	rewind(archivo);
	
	printf("\n--- Listado de Peliculas ---\n");
	while (fread(&p, sizeof(p), 1, archivo)) {
        printf("Titulo: %s, Personas: %d\n", p.titulo, p.cantPersonas);
    }
}

void dadoCodigo(FILE *archivo, int codigo){
	pelicula p;
	rewind(archivo);

	while (fread(&p, sizeof(p), 1, archivo)){
		if(p.codigo==codigo){
			printf("Titulo: %s, Director: %d\n", p.titulo, p.director);
		}
	}


}

void dadoCodigo(FILE *archivo, int codigo){
	pelicula p;
	int b=0;
	rewind(archivo);
	fread(&p, sizeof(p), 1, archivo);
	while((!feof(archivo)) && (b==0)){
		
	}
}

int main(){
	int codigo;

	FILE *archivo;


	if ((archivo = fopen("TITULOS.DAT", "w+")) == NULL) {
	    printf("Error al abrir TITULOS.DAT\n");
	    return 1;
	}
	carga(archivo);
	listarPeliculas(archivo);

	printf("Ingresar codigo de la pelicula.");
	scanf("%f", &codigo);
	dadoCodigo(archivo, codigo);
	

	
}