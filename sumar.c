#include <stdio.h>

extern void sumar_matrices(int* A, int* B, int* C, int n);
extern int sumatoria_matriz(int* C, int n);

int main() {
    int n = 3; // Tamaño de la matriz (puedes cambiarlo a 4, 5, etc.)
    
    // Matrices en formato unidimensional
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int C[9] = {0}; // Inicializada en ceros
    
    printf("Calculando suma de matrices %dx%d...\n", n, n);
    
    // Llamada a la primera subrutina 
    sumar_matrices(A, B, C, n);
    
    // Imprimimos el resultado
    printf("Matriz Resultante C:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", C[i * n + j]);
        }
        printf("\n");
    }
    
    // Llamada a la segunda subrutina 
    int suma_total = sumatoria_matriz(C, n);
    
    printf("\nSumatoria total de los elementos de C: %d\n", suma_total);
    
    return 0;
}