#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sumar_matrices(int* A, int* B, int* C, int n);
extern int sumatoria_matriz(int* C, int n);

// Función imprimir matrices
void imprimir_matriz(const char* nombre, int n, int matriz[n][n]) {
    printf("--- Matriz %s ---\n", nombre);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Usamos %4d para que quede alineado.
            printf("%4d ", matriz[i][j]); 
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

    // 2. Reservar memoria
    int A[n][n];
    int B[n][n];
    int C[n][n];

    // 3. Llenar con números aleatorios
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){    
            A[i][j] = rand() % 1000; // rand() genera un número de 0 a 999
            B[i][j] = rand() % 1000; 
            C[i][j] = 0;
        }
    }

    printf("\n=== ANTES DE LA SUMA ===\n");
    imprimir_matriz("A", n, A);
    imprimir_matriz("B", n, B);

    // 4. Llamar a las subrutinas
    sumar_matrices((int*)A, (int*)B, (int*)C, n);
    int suma_total = sumatoria_matriz((int*)C, n);

    // 5. Mostrar el resultado
    printf("=== DESPUÉS DE LA SUMA ===\n");
    imprimir_matriz("Resultante C (A + B)", n, C);
    printf("Sumatoria total de todos los elementos de C: %d\n\n", suma_total);


    return 0;
}
