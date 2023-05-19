#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция для построения матрицы инцидентности
int **buildIncidenceMatrix(int edges, int vertices) {
    int **matrix = (int **) malloc(sizeof(int *) * edges);
    int i, j;
    for (i = 0; i < edges; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * vertices);
        for (j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
    printf("Введите номера вершин для каждого ребра:\n");
    for (i = 0; i < edges; i++) {
        printf("Ребро %d: ", i + 1);
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        matrix[i][v1 - 1] = 1;
        matrix[i][v2 - 1] = 1;
    }
    return matrix;
}
void printMatrix(int** matrix, int edges, int vertices) {
    int i, j;
    printf("Матрица инцидентности:\n");
    for (i = 0; i < edges; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для определения степени вершин
int *calculateDegrees(int **matrix, int edges, int vertices) {
    int *degrees = (int *) malloc(sizeof(int) * vertices);
    int i, j, degree;
    for (i = 0; i < vertices; i++) {
        degree = 0;
        for (j = 0; j < edges; j++) {
            if (matrix[j][i] == 1) {
                degree++;
            }
        }
        degrees[i] = degree;
        printf("Вершина %d: %d\n", i+1, degree);
    }
    return degrees;
}

// Функция для сортировки вершин по возрастанию степени
int sortVerticesByDegree(int* degrees, int vertices) {
    int i, j, minDegreeIndex, temp;
    for (i = 0; i < vertices - 1; i++) {
        minDegreeIndex = i;
        for (j = i + 1; j < vertices; j++) {
            if (degrees[j] < degrees[minDegreeIndex]) {
                minDegreeIndex = j;
            }
        }
        temp = degrees[i];
        degrees[i] = degrees[minDegreeIndex];
        degrees[minDegreeIndex] = temp;
    }
    return temp;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    printf("Введите количество ребер: ");
    int edges;
    scanf("%d", &edges);
    printf("Введите количество вершин: ");
    int vertices;
    scanf("%d", &vertices);
    int **matrix = buildIncidenceMatrix(edges, vertices);
    printMatrix(matrix, edges, vertices);
    printf("Степени вершин:\n");
    int *degrees = calculateDegrees(matrix, edges, vertices);
    sortVerticesByDegree(degrees, vertices);
    printf("Степени вершин по возрастанию:\n");
    int i;
    for (i = 0; i < vertices; i++) {
        printf("%d\n", degrees[i]);
    }
    return 0;
}
