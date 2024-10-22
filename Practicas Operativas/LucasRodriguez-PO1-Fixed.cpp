#include <stdio.h>
#define C 4
#define N 3

void cereo(int ventas[C][N])
{
    int i, j;
    for (i = 0; i < C; i++)
    {
        for (j = 0; j < N; j++)
        {
            ventas[i][j] = 0;
        }
    }
}

void cargaVenta(int ventas[C][N])
{
    int i, cerveza, vendido;
    for (i = 0; i < N; i++)
    {
        printf("======= Negocio %d =======\n", i + 1);
        printf("Ingrese el tipo de cerveza que vendio, 0 para finalizar.\n");
        printf("(Entre 1 y 4)\n");
        scanf("%d", &cerveza);
        while (cerveza != 0)
        {
            printf("Ingrese la cantidad de unidades vendidas: ");
            scanf("%d", &vendido);
            ventas[cerveza - 1][i] += vendido;
            printf("Ingrese el tipo de cerveza que vendio, 0 para finalizar.\n");
            printf("(Entre 1 y 4)\n");
            scanf("%d", &cerveza);
        }
    }
}

void totalPorCerveza(int ventas[C][N])
{
    int i, j, total;
    for (i = 0; i < C; i++)
    {
        total = 0;
        for (j = 0; j < N; j++)
        {
            total += ventas[i][j];
        }
        printf("Total de unidades vendidas de la cerveza %d: %d\n", i + 1, total);
    }
}

int totalUniCerveza(int ventas[C][N], int tipoCerveza)
{
    int i, total = 0;
    for (i = 0; i < N; i++)
    {
        total += ventas[tipoCerveza - 1][i];
    }
    return total;
}

// Juli
void mostrar(int tabla[C][N])
{
    int i, j;

    for (i = 0; i < C; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d | ", tabla[i][j]);
        }
        printf("\n");
    }
    return;
}
//--------------

int main()
{
    printf("JTP: Silvina\n");
    printf("Alumno: Lucas Rodriguez\n");
    int ventas[C][N], tipoCerveza, total;
    cereo(ventas);
    cargaVenta(ventas);
    totalPorCerveza(ventas);

    printf("\nIngrese el codigo de la cerveza para conocer su total de ventas: ");
    scanf("%d", &tipoCerveza);

    total = totalUniCerveza(ventas, tipoCerveza);
    printf("Total de unidades vendidas de la cerveza %d: %d\n", tipoCerveza, total);
    mostrar(ventas);
    return 0;
}
