#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
void taomangngaunhien(int a[][100], int m, int n,int c ,int b) {
	if (m < 0 && n < 0) {
		printf("nhap so dong so cot phai lon hon 0");
	}
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = c + rand() % (b - c + 1);
		}
		  
	}
}
void xuat(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", &a[i][j]);
		}
	}
}void tong(int a[][100], int m, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			sum += a[i][j];
			
		}
		printf("tong cua dong thu %d\n", i);
		printf("%d",sum);
	}
}
void giatrilonnhatcuacot(int a[][100], int m, int n) {
	int temp = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] > temp);
			temp = a[i][j];
		}
	}
	}
void vien(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = i ; j < n; j++) {
			printf("%d", &a[i][j]);
		}
		printf("\n");
	}
}
int xuatcucdai(int a[][100], int m, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > temp) {
				temp = a[i][j];
			}
		}
	}
	return temp;
}
//tim hoang hau
int xetDuongCheo(int a[][100], int dong, int cot, int i, int j) {
	int k, h; //k: dong, h: cot
	for (k = i, h = j; k >= 0 && h < cot; k--, h++)
		if (a[k][h] > a[i][j])
			return 0;
	for (k = i + 1, h = j - 1; k < dong && h >= 0; k++, h--)
		if (a[k][h] > a[i][j])
			return 0;
	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
		if (a[k][h] > a[i][j])
			return 0;
	for (k = i + 1, h = j + 1; k < dong && h < cot; k++, h++)
		if (a[k][h] > a[i][j])
			return 0;
	return 1;
}
int xetCotDong(int a[][100], int dong, int cot, int i, int j) {
	for (int k = 0; k < dong; k++)
		if (a[k][j] > a[i][j])
			return 0;
	for (int k = 0; k < cot; k++)
		if (a[i][k] > a[i][j])
			return 0;
	return 1;
}
int xetTongQuat(int a[][100], int dong, int cot, int i, int j) {
	if (xetCotDong(a, dong, cot, i, j) == 1)
		if (xetDuongCheo(a, dong, cot, i, j) == 1)
			return 1;
	return 0;
}
void xuatdongsochan(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] % 2 == 0) {
				printf("%d", a[i][j]);
			}
		}
	}
}
//Sắp xếp mảng a tăng theo từng dòng
void xapxeptungdong(int a[][100], int m, int n, int k) {
	int temp = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j) {
				if (a[k][i] < a[k][j]) {
					temp = a[k][i];
					a[k][i] = a[k][j];
					a[k][j] = temp;

				}
			}
		}
	}
}

		