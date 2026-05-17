#include <stdio.h>
#include <string.h>

#define MAX 5

char nombres[MAX][50];
int cantidades[MAX];
float tiempos[MAX];
int recursos[MAX];

int totalProductos = 0;

void ingresarProductos() {
    int i;

    printf("\n--- INGRESO DE PRODUCTOS ---\n");

    for(i = 0; i < MAX; i++) {

        printf("\nNombre del producto: ");
        scanf("%s", nombres[i]);

        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);

        printf("Tiempo por unidad: ");
        scanf("%f", &tiempos[i]);

        printf("Recursos por unidad: ");
        scanf("%d", &recursos[i]);

        totalProductos++;
    }
}

void mostrarProductos() {

    int i;

    printf("\n--- PRODUCTOS REGISTRADOS ---\n");

    for(i = 0; i < totalProductos; i++) {

        printf("\nProducto: %s", nombres[i]);
        printf("\nCantidad: %d", cantidades[i]);
        printf("\nTiempo unidad: %.2f", tiempos[i]);
        printf("\nRecursos unidad: %d\n", recursos[i]);
    }
}

void calcularProduccion() {

    int i;
    float totalTiempo = 0;
    int totalRecursos = 0;

    for(i = 0; i < totalProductos; i++) {

        totalTiempo += cantidades[i] * tiempos[i];
        totalRecursos += cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f", totalTiempo);
    printf("\nRecursos totales necesarios: %d\n", totalRecursos);

    if(totalTiempo <= 500 && totalRecursos <= 1000) {
        printf("\nLa fabrica SI puede cumplir la demanda\n");
    }
    else {
        printf("\nLa fabrica NO puede cumplir la demanda\n");
    }
}

void editarProducto() {

    char buscar[50];
    int i;

    printf("\nIngrese el producto a editar: ");
    scanf("%s", buscar);

    for(i = 0; i < totalProductos; i++) {

        if(strcmp(buscar, nombres[i]) == 0) {

            printf("\nNuevo nombre: ");
            scanf("%s", nombres[i]);

            printf("Nueva cantidad: ");
            scanf("%d", &cantidades[i]);

            printf("Nuevo tiempo: ");
            scanf("%f", &tiempos[i]);

            printf("Nuevos recursos: ");
            scanf("%d", &recursos[i]);

            printf("\nProducto editado correctamente\n");
            return;
        }
    }

    printf("\nProducto no encontrado\n");
}

void eliminarProducto() {

    char buscar[50];
    int i, j;

    printf("\nIngrese el producto a eliminar: ");
    scanf("%s", buscar);

    for(i = 0; i < totalProductos; i++) {

        if(strcmp(buscar, nombres[i]) == 0) {

            for(j = i; j < totalProductos - 1; j++) {

                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
            }

            totalProductos--;

            printf("\nProducto eliminado correctamente\n");
            return;
        }
    }

    printf("\nProducto no encontrado\n");
}

int main() {

    int opcion;

    do {

        printf("\n===== MENU =====");
        printf("\n1. Ingresar productos");
        printf("\n2. Mostrar productos");
        printf("\n3. Calcular produccion");
        printf("\n4. Editar producto");
        printf("\n5. Eliminar producto");
        printf("\n6. Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                ingresarProductos();
                break;

            case 2:
                mostrarProductos();
                break;

            case 3:
                calcularProduccion();
                break;

            case 4:
                editarProducto();
                break;

            case 5:
                eliminarProducto();
                break;

            case 6:
                printf("\nPrograma finalizado\n");
                break;

            default:
                printf("\nOpcion invalida\n");
        }

    } while(opcion != 6);

    return 0;
}