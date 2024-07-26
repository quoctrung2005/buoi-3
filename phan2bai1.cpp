#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Tao ma tran va xuat cac phan tu ngau nhien
void create_matrix(int m, int n, int a, int b, int matrix[100][100]) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = a + rand() % (b - a + 1);
        }
    }
}

// In ma tran
void print_matrix(int m, int n, int matrix[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 2. Tinh tong gia tri tung dong
void sum_of_rows(int m, int n, int matrix[100][100]) {
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        printf("Tong cua dong %d: %d\n", i, sum);
    }
}

// 3. Xuat phan tu lon nhat tren tung cot
void max_in_columns(int m, int n, int matrix[100][100]) {
    for (int j = 0; j < n; j++) {
        int max = matrix[0][j];
        for (int i = 1; i < m; i++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        printf("Lon nhat trong cot %d: %d\n", j, max);
    }
}

// 4. Xuat cac phan tu thuoc cac duong bien
void boundary_elements(int m, int n, int matrix[100][100]) {
    printf("Cac phan tu duong bien: ");
    for (int j = 0; j < n; j++) printf("%d ", matrix[0][j]); // Hang tren
    for (int i = 1; i < m - 1; i++) printf("%d ", matrix[i][n - 1]); // Cot phai
    for (int j = n - 1; j >= 0; j--) printf("%d ", matrix[m - 1][j]); // Hang duoi
    for (int i = m - 2; i > 0; i--) printf("%d ", matrix[i][0]); // Cot trai
    printf("\n");
}

// 5. Xuat cac phan tu cuc dai
void local_maxima(int m, int n, int matrix[100][100]) {
    printf("Cac phan tu cuc dai: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int is_maxima = 1;
            if ((i > 0 && matrix[i][j] <= matrix[i - 1][j]) ||
                (i < m - 1 && matrix[i][j] <= matrix[i + 1][j]) ||
                (j > 0 && matrix[i][j] <= matrix[i][j - 1]) ||
                (j < n - 1 && matrix[i][j] <= matrix[i][j + 1])) {
                is_maxima = 0;
            }
            if (is_maxima) printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
}

// 6. Xuat cac phan tu hoang hau
void queen_elements(int m, int n, int matrix[100][100]) {
    printf("Cac phan tu hoang hau: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int row_check = 1, col_check = 1;
            for (int k = 0; k < n; k++) {
                if (matrix[i][j] < matrix[i][k]) {
                    row_check = 0;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (matrix[i][j] < matrix[k][j]) {
                    col_check = 0;
                    break;
                }
            }
            if (row_check && col_check) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

// 7. Xuat cac phan tu la diem yen ngua
void saddle_points(int m, int n, int matrix[100][100]) {
    printf("Cac diem yen ngua: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int row_min = 1, col_max = 1;
            for (int k = 0; k < n; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    row_min = 0;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (matrix[i][j] < matrix[k][j]) {
                    col_max = 0;
                    break;
                }
            }
            if (row_min && col_max) {
                printf("(%d, %d) %d ", i, j, matrix[i][j]);
            }
        }
    }
    printf("\n");
}

// 8. Xuat dong chi chua so chan
void even_rows(int m, int n, int matrix[100][100]) {
    printf("Cac dong chi chua so chan: ");
    for (int i = 0; i < m; i++) {
        int all_even = 1;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 != 0) {
                all_even = 0;
                break;
            }
        }
        if (all_even) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int m = 4, n = 5, a = 0, b = 9;
    int matrix[100][100];

    create_matrix(m, n, a, b, matrix);
    printf("Ma tran ngau nhien:\n");
    print_matrix(m, n, matrix);

    printf("\nTong gia tri tung dong:\n");
    sum_of_rows(m, n, matrix);

    printf("\nPhan tu lon nhat tren tung cot:\n");
    max_in_columns(m, n, matrix);

    printf("\nCac phan tu duong bien:\n");
    boundary_elements(m, n, matrix);

    printf("\nCac phan tu cuc dai:\n");
    local_maxima(m, n, matrix);

    printf("\nCac phan tu hoang hau:\n");
    queen_elements(m, n, matrix);

    printf("\nCac diem yen ngua:\n");
    saddle_points(m, n, matrix);

    printf("\nCac dong chi chua so chan:\n");
    even_rows(m, n, matrix);

    return 0;
}
