#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numOperacion;
    float importe;
    int tipoOperacion;  // 1: cobro, 2: pago
} operacion;

struct nodo {
    operacion dato;
    struct nodo *sig;
};

typedef struct nodo *puntero;


void cargarOperaciones(puntero &cabeza) {
    int numOp;
    puntero nuevo;
    
    printf("Ingrese num de operacion, 0 para finalizar: ");
    scanf("%d", &numOp);
    
    while (numOp != 0) {
        nuevo = (puntero)malloc(sizeof(struct nodo));
        
        nuevo->dato.numOperacion = numOp;
        printf("Ingrese importe: ");
        scanf("%f", &nuevo->dato.importe);
        printf("Ingrese tipo de operacion (1: cobro, 2: pago): ");
        scanf("%d", &nuevo->dato.tipoOperacion);
        
        nuevo->sig = cabeza;
        cabeza = nuevo;
        
        printf("Ingrese num de operacion, 0 para finalizar: ");
        scanf("%d", &numOp);
    }
}

// b)
float mayorCobro(puntero &cabeza, int &numMayorCobro) {
    if (cabeza == NULL) {
        return 0;
    }
    
    if (cabeza->dato.tipoOperacion == 1) {
        float maxResto = mayorCobro(cabeza->sig, numMayorCobro);
        if (cabeza->dato.importe > maxResto) {
            numMayorCobro = cabeza->dato.numOperacion;
            return cabeza->dato.importe;
        }
        return maxResto;
    }
    
    return mayorCobro(cabeza->sig, numMayorCobro);
}

//c)
void generarArchivoPagos(puntero cabeza) {
    FILE *archi = fopen("pagos.dat", "wb");
    
    if (archi == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    while (cabeza != NULL) {
        if (cabeza->dato.tipoOperacion == 2) {
            fwrite(&cabeza->dato, sizeof(operacion), 1, archi);
        }
        cabeza = cabeza->sig;
    }
    
    fclose(archi);
    printf("Archivo 'pagos.dat' generado con exito\n");
}

//d)
void eliminarLista(puntero &cabeza) {
    puntero aux;
    
    while (cabeza != NULL) {
        aux = cabeza;
        cabeza = (cabeza)->sig;
        free(aux);
    }
}

// e)
float calcularPromedioPagos(FILE *archi) {
    operacion c;
    int cant = 0;
    float suma = 0;
    
    rewind(archi);
    
    while (fread(&c, sizeof(operacion), 1, archi)) {
        if (c.tipoOperacion == 2) {
            suma += c.importe;
            cant++;
        }
    }
    
    if (cant == 0) {
        return 0;
    }
    
    return suma / cant;
}

//f)
void eliminarPagosMenoresA500() {
    FILE *archi = fopen("pagos.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    operacion c;
    
    if (archi == NULL || temp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    while (fread(&c, sizeof(operacion), 1, archi)) {
        if (c.importe >= 500) {
            fwrite(&c, sizeof(operacion), 1, temp);
        }
    }
    
    fclose(archi);
    fclose(temp);
    
    // Remplasar el archivo original
    remove("pagos.dat");
    rename("temp.dat", "pagos.dat");
    
    printf("Pagos menores a $500 eliminados con éxito.\n");
}

int main() {
    puntero cabeza;
    cabeza = NULL;
    int numMayorCobro = 0;
    float maxCobro = 0;
    
    cargarOperaciones(cabeza);
    
    maxCobro = mayorCobro(cabeza, numMayorCobro);
    if (maxCobro > 0) {
        printf("Mayor cobro: Operacion %d con importe %.2f\n", numMayorCobro, maxCobro);
    } else {
        printf("No se encontraron cobros.\n");
    }
    
    generarArchivoPagos(cabeza);
    
    FILE *archi = fopen("pagos.dat", "rb");
    if (archi == NULL) {
        printf("Error al abrir el archivo de pagos.\n");
        return 1;
    }
    
    float promedio = calcularPromedioPagos(archi);
    if (promedio > 0) {
        printf("Promedio de los pagos realizados: %.2f\n", promedio);
    } else {
        printf("No se encontraron pagos.\n");
    }
    
    fclose(archi);
    
    eliminarPagosMenoresA500();
    
    eliminarLista(cabeza);
    
    return 0;
}
