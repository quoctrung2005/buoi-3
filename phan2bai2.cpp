#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 // Kích thước ma trận vuông


// 1. Tạo/xuất ma trận vuông a chứa số nguyên ngẫu nhiên có cấp n>=5.
void taoMaTran(int a[N][N], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100; // Số nguyên ngẫu nhiên từ 0 đến 99
        }
    }
}

void xuatMaTran(int a[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// 2. Xuất các phần tử trên đường chéo chính.
void xuatDuongCheoChinh(int a[N][N], int n) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

// 3. Xuất các phần tử thuộc đường chéo song song với đường chéo chính.
void xuatDuongCheoPhu(int a[N][N], int n) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][n - i - 1]);
    }
    printf("\n");
}

// 4. Tìm phần tử max thuộc tam giác trên của đường chéo chính.
int maxTamGiacTren(int a[N][N], int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// 5. Sắp xếp ma trận tăng dần theo kiểu zic-zắc
void sapXepZigZag(int a[N][N], int n) {
    int temp[100], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[k++] = a[i][j];
        }
    }
    // Sắp xếp mảng temp
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    // Điền lại ma trận theo kiểu zic-zắc
    k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[k++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[k++];
            }
        }
    }
}

// 6. Sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(int a[N][N], int n) {
    int temp[100];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }
    // Sắp xếp mảng temp
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    // Điền lại đường chéo chính
    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}


int main() {
    int a[N][N];
    taoMaTran(a, N);
    printf("Ma tran ban dau:\n");
    xuatMaTran(a, N);

    printf("\n");
    xuatDuongCheoChinh(a, N);
    xuatDuongCheoPhu(a, N);

    int max = maxTamGiacTren(a, N);
    printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);

    sapXepZigZag(a, N);
    printf("\nMa tran sau khi sap xep zig-zag:\n");
    xuatMaTran(a, N);

    sapXepDuongCheoChinh(a, N);
    printf("\nMa tran sau khi sap xep duong cheo chinh tang dan:\n");
    xuatMaTran(a, N);

    return 0;
}