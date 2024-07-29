#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void xuatCacCotSoLe(int a[MAX][MAX], int m, int n) {
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        bool onlyOdd = true;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                onlyOdd = false;
                break;
            }
        }
        if (onlyOdd) {
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

int timMaxBien(int a[MAX][MAX], int m, int n) {
    int max = a[0][0];
    for (int i = 0; i < m; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
        if (a[m - 1][j] > max) max = a[m - 1][j];
    }
    return max;
}

int demPhanTuCoChuSo2(int a[MAX][MAX], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num > 0) {
                if (num % 10 == 2) {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return count;
}

bool laCucTieu(int a[MAX][MAX], int m, int n, int i, int j) {
    int val = a[i][j];
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] < val) {
                return false;
            }
        }
    }
    return true;
}

void xuatCacPhanTuCucTieu(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laCucTieu(a, m, n, i, j)) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
            }
        }
    }
}

void sapXepDongTangGiam(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) ||
                    (i % 2 != 0 && a[i][j] < a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void sapXepCotTangGiam(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) ||
                    (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

bool giamDanZicZac(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1] || a[i][j] < a[i + 1][j]) {
                return false;
            }
        }
    }
    return true;
}

void lietKeDongToanChan(int a[MAX][MAX], int m, int n) {
    printf("Chi so cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        bool allEven = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = false;
                break;
            }
        }
        if (allEven) {
            printf("Dong %d\n", i);
        }
    }
}

void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
    printf("Chi so cac dong chua gia tri giam dan:\n");
    for (int i = 0; i < m; i++) {
        bool decreasing = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                decreasing = false;
                break;
            }
        }
        if (decreasing) {
            printf("Dong %d\n", i);
        }
    }
}

int giaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int maxValue = a[0][0], maxCount = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (a[i][j] == a[x][y]) {
                        count++;
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxValue = a[i][j];
            }
        }
    }
    return maxValue;
}

void demChuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int count[10] = { 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num > 0) {
                count[num % 10]++;
                num /= 10;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    printf("Cac chu so xuat hien nhieu nhat:\n");
    for (int i = 0; i < 10; i++) {
        if (count[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void lietKeCotCoTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    int minIndex = 0;
    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
            minIndex = j;
        }
    }
    printf("Cot co tong nho nhat: %d\n", minIndex);
}

void hoanViHaiCot(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}

void hoanViHaiDong(int a[MAX][MAX], int m, int n, int k, int l) {
    for (int i = 0; i < n; i++) {
        int temp = a[k][i];
        a[k][i] = a[l][i];
        a[l][i] = temp;
    }
}

int main() {
    int m, n;
    int a[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    m = 4;
    n = 4;

    // 1. Xuất các cột chỉ chứa số lẻ
    xuatCacCotSoLe(a, m, n);

    // 2. Tìm phần tử lớn nhất trên biên của ma trận
    printf("Phan tu lon nhat tren bien: %d\n", timMaxBien(a, m, n));

    // 3. Đếm các phần tử có chữ số 2 trong ma trận
    printf("So luong phan tu co chu so 2: %d\n", demPhanTuCoChuSo2(a, m, n));

    // 4. Xuất các phần tử cực tiểu
    xuatCacPhanTuCucTieu(a, m, n);

    // 5. Sắp xếp dòng tăng dần và giảm dần
    sapXepDongTangGiam(a, m, n);

    // 6. Sắp xếp cột tăng dần và giảm dần
    sapXepCotTangGiam(a, m, n);

    // 7. Kiểm tra ma trận có giảm dần ziczac hay không
    if (giamDanZicZac(a, m, n)) {
        printf("Ma tran giam dan theo ziczac.\n");
    }
    else {
        printf("Ma tran khong giam dan theo ziczac.\n");
    }

    // 8. Liệt kê các dòng chứa toàn giá trị chẵn
    lietKeDongToanChan(a, m, n);

    // 9. Liệt kê các dòng có giá trị giảm dần
    lietKeDongGiamDan(a, m, n);

    // 10. Tìm giá trị xuất hiện nhiều nhất
    printf("Gia tri xuat hien nhieu nhat: %d\n", giaTriXuatHienNhieuNhat(a, m, n));

    // 11. Tìm các chữ số xuất hiện nhiều nhất
    demChuSoXuatHienNhieuNhat(a, m, n);

    // 12. Liệt kê các cột có tổng nhỏ nhất
    lietKeCotCoTongNhoNhat(a, m, n);

    // 13. Hoán vị hai cột
    hoanViHaiCot(a, m, n, 0, 1);

    // 14. Hoán vị hai dòng
    hoanViHaiDong(a, m, n, 0, 1);

    return 0;
}
