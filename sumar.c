#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sumar_matrices(int* A, int* B, int* C, int n);
extern int sumatoria_matriz(int* C, int n);

// Función imprimir matrices
void imprimir_matriz(const char* nombre, int* matriz, int n) {
    printf("--- Matriz %s ---\n", nombre);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Usamos %4d para que quede alineado.
            printf("%4d ", matriz[i * n + j]); 
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;

    // Inicializamos la "semilla" del generador de números aleatorios
    srand(time(NULL));

    // 1. Pedir el tamaño de las matrices
    printf("Ingrese el tamaño de las matrices cuadradas (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Por favor ingrese un número entero positivo.\n");
        return 1;
    }

    int total_elementos = n * n;

    // 2. Reservar memoria
    int* A = (int*)malloc(total_elementos * sizeof(int));
    int* B = (int*)malloc(total_elementos * sizeof(int));
    int* C = (int*)malloc(total_elementos * sizeof(int));

    // 3. Llenar con números aleatorios
    for(int i = 0; i < total_elementos; i++) {
        A[i] = rand() % 1000; // rand() genera un número de 0 a 999
        B[i] = rand() % 1000; 
        C[i] = 0;
    }

    printf("\n=== ANTES DE LA SUMA ===\n");
    imprimir_matriz("A", A, n);
    imprimir_matriz("B", B, n);

    // 4. Llamar a las subrutinas
    sumar_matrices(A, B, C, n);
    int suma_total = sumatoria_matriz(C, n);

    // 5. Mostrar el resultado
    printf("=== DESPUÉS DE LA SUMA ===\n");
    imprimir_matriz("Resultante C (A + B)", C, n);
    printf("Sumatoria total de todos los elementos de C: %d\n\n", suma_total);

    // 6. Limpieza
    free(A);
    free(B);
    free(C);

    return 0;
}
