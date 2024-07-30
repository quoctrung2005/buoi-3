#include <stdio.h>

#define MAX 100

// Ham hoan doi hai gia tri nguyen
void hoanDoi(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Sap xep duong cheo phu tang dan/giam dan
void sapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan) {
    int i, j, k;
    int temp[MAX];

    // Trich xuat cac phan tu tren duong cheo phu
    for (i = 0; i < n; i++) {
        temp[i] = a[i][n - 1 - i];
    }

    // Sap xep mang phu
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((tangDan && temp[i] > temp[j]) || (!tangDan && temp[i] < temp[j])) {
                hoanDoi(&temp[i], &temp[j]);
            }
        }
    }

    // Dua lai cac gia tri da sap xep vao duong cheo phu
    for (i = 0; i < n; i++) {
        a[i][n - 1 - i] = temp[i];
    }
}

// 2. Sap xep cac dong: dong le tang, dong chan giam
void sapXepDong(int a[MAX][MAX], int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    hoanDoi(&a[i][j], &a[i][k]);
                }
            }
        }
    }
}

// 3. Sap xep cac cot: cot le giam, cot chan tang
void sapXepCot(int a[MAX][MAX], int n) {
    int i, j, k;

    for (j = 0; j < n; j++) {
        for (i = 0; i < n - 1; i++) {
            for (k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    hoanDoi(&a[i][j], &a[k][j]);
                }
            }
        }
    }
}

// 4. Sap xep cac phan tu tren cac duong cheo chinh va cac duong cheo song song voi duong cheo chinh tang dan
void sapXepDuongCheo(int a[MAX][MAX], int n) {
    int i, j, k, len;
    int temp[MAX];

    // Duyet qua cac duong cheo tu tren xuong duoi
    for (i = 0; i < n; i++) {
        len = 0;
        // Trich xuat cac phan tu tren tung duong cheo
        for (j = 0; j <= i; j++) {
            temp[len++] = a[i - j][j];
        }

        // Sap xep cac phan tu tren duong cheo
        for (j = 0; j < len - 1; j++) {
            for (k = j + 1; k < len; k++) {
                if (temp[j] > temp[k]) {
                    hoanDoi(&temp[j], &temp[k]);
                }
            }
        }

        // Dua lai cac gia tri da sap xep vao ma tran
        for (j = 0; j <= i; j++) {
            a[i - j][j] = temp[j];
        }
    }

    // Duyet qua cac duong cheo tu duoi len tren
    for (i = 1; i < n; i++) {
        len = 0;
        for (j = 0; j < n - i; j++) {
            temp[len++] = a[n - 1 - j][i + j];
        }

        for (j = 0; j < len - 1; j++) {
            for (k = j + 1; k < len; k++) {
                if (temp[j] > temp[k]) {
                    hoanDoi(&temp[j], &temp[k]);
                }
            }
        }

        // Dua lai cac gia tri da sap xep vao ma tran
        for (j = 0; j < len; j++) {
            a[n - 1 - j][i + j] = temp[j];
        }
    }
}

// 5. Di chuyen cac phan tu chan len tren, phan tu le xuong duoi
void diChuyenChanLeLenTren(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int soPhanTuChan = 0, soPhanTuLe = 0;

    // Tach cac phan tu chan va le
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                temp[soPhanTuChan++] = a[i][j];
            }
            else {
                temp[n * n - (++soPhanTuLe)] = a[i][j];
            }
        }
    }

    // Chuyen cac phan tu chan va le vao ma tran
    for (int i = 0; i < soPhanTuChan; i++) {
        a[i / n][i % n] = temp[i];
    }
    for (int i = 0; i < soPhanTuLe; i++) {
        a[(soPhanTuChan + i) / n][(soPhanTuChan + i) % n] = temp[n * n - soPhanTuLe + i];
    }
}

// 6. Kiem tra doi xung qua duong cheo chinh
int kiemTraDoiXung(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0; // Khong doi xung
            }
        }
    }
    return 1; // Doi xung
}

// Ham in ma tran
void inMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int a[MAX][MAX];
    int tangDan;

    // Nhap kich thuoc va cac phan tu cua ma tran
    printf("Nhap kich thuoc ma tran: ");
    scanf_s("%d", &n);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    // Thuc hien cac chuc nang
    printf("Sap xep duong cheo phu (1: tang dan, 0: giam dan): ");
    scanf_s("%d", &tangDan);
    sapXepDuongCheoPhu(a, n, tangDan);
    inMaTran(a, n);

    printf("Sap xep cac dong (dong le tang, dong chan giam):\n");
    sapXepDong(a, n);
    inMaTran(a, n);

    printf("Sap xep cac cot (cot le giam, cot chan tang):\n");
    sapXepCot(a, n);
    inMaTran(a, n);

    printf("Sap xep cac duong cheo va cac duong cheo song song:\n");
    sapXepDuongCheo(a, n);
    inMaTran(a, n);

    printf("Di chuyen cac phan tu chan len tren, phan tu le xuong duoi:\n");
    diChuyenChanLeLenTren(a, n);
    inMaTran(a, n);

    if (kiemTraDoiXung(a, n)) {
        printf("Ma tran doi xung qua duong cheo chinh.\n");
    }
    else {
        printf("Ma tran khong doi xung qua duong cheo chinh.\n");
    }

    return 0;
}
