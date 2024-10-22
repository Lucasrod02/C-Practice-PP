#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char titulo[50];
    char autor[50];
    float precio;
    int cantidad;
}libro;

struct nodo{
    libro dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void cargarLibros(puntero &cabeza){
    int cod;
    puntero nuevo;
    printf("Ingrese codigo del libro, 0 para finalizar: ");
    scanf("%d", &cod);
    while(cod != 0){
        nuevo = (puntero)malloc(sizeof(struct nodo));
        nuevo->dato.codigo = cod;
        printf("Ingrese titulo: ");
        scanf("%s", nuevo->dato.titulo);
        while(getchar() != '\n');
        printf("Ingrese autor: ");
        scanf("%s", nuevo->dato.autor);
        while(getchar() != '\n');
        printf("Ingrese precio: ");
        scanf("%f", &nuevo->dato.precio);
        printf("Ingrese cantidad: ");
        scanf("%d", &nuevo->dato.cantidad);

        nuevo->sig = cabeza;
        cabeza = nuevo;

        printf("Ingrese codigo del libro, 0 para finalizar: ");
        scanf("%d", &cod);
    }
}

float buscarLibro(puntero cabeza, int cod, char *titulo, char *autor){
    if(cabeza != NULL){
        if(cabeza->dato.codigo == cod){
            strcpy(titulo, cabeza->dato.titulo);
            strcpy(autor, cabeza->dato.autor);
            return cabeza->dato.precio;
        }
        return buscarLibro(cabeza->sig, cod, titulo, autor);
    }
    return 0;
}

void imprimirInverso(puntero cabeza){
    if(cabeza != NULL){
        imprimirInverso(cabeza->sig);
        printf("Codigo: %d\n", cabeza->dato.codigo);
        printf("Titulo: %s\n", cabeza->dato.titulo);
        printf("Autor: %s\n", cabeza->dato.autor);
        printf("Precio: %.2f\n", cabeza->dato.precio);
        printf("Cantidad: %d\n", cabeza->dato.cantidad);
    }
}

void eliminarLibro(puntero &cabeza, int cod){
    puntero anterior, p;
    if(cabeza->dato.codigo == cod){
        p = cabeza;
        cabeza = cabeza->sig;
        free(p);
        printf("Libro con codigo %d eliminado\n", cod);
    }else{
        p = cabeza;
        anterior = cabeza;
        while((p != NULL) && (p->dato.codigo != cod)){
            anterior = p;
            p = p->sig;
        }
        if(p != NULL){
            anterior->sig = p->sig;
            free(p);
            printf("Libro con codigo %d eliminado\n", cod);
        }else{
            printf("Libro no encontrado\n");
        }
    }
}

float calcularImporteTotal(puntero cabeza){
    if(cabeza == NULL){
        return 0;
    }else{
        return (cabeza->dato.precio * cabeza->dato.cantidad) + calcularImporteTotal(cabeza->sig);
    }
}

int main(){
    puntero cabeza;
    int cod;
    float total, precio;
    char titulo[50], autor[50];
    cabeza = NULL;

    cargarLibros(cabeza);
    
    printf("Ingrese codigo de libro a buscar: ");
    scanf("%d", &cod);
    precio = buscarLibro(cabeza, cod, titulo, autor);
    if(precio > 0){
        printf("Autor: %s\n", autor);
        printf("Titulo: %s\n", titulo);
        printf("Precio: %.2f\n", precio);
    }else{
        printf("Libro no encontrado\n");
    }
    
    printf("----- Lista de libros en orden inverso -----\n");
    imprimirInverso(cabeza);
    
    printf("Ingrese codigo de libro a eliminar: ");
    scanf("%d", &cod);
    eliminarLibro(cabeza, cod);
    
    printf("Lista actualizada de libros en orden inverso:\n");
    imprimirInverso(cabeza);
    
    total = calcularImporteTotal(cabeza);
    printf("Importe total en libros: %.2f\n", total);
}
