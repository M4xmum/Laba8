#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <queue>
using namespace std;

void bfs(int ver, int* v, int n, int** matr) {
	queue <int> q;
	q = {};
	q.push(ver);
	v[ver] = 1;
	while (q.size() != 0) {
		ver = q.front();
		q.pop();
		printf("%d \t", ver + 1);
		for (int i = 0; i < n; i++) {
			if (matr[ver][i] == 1 && v[i] == 0) {
				q.push(i);
				v[i] = 1;
			}
		}
	}

}



int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n = 0;
	printf("Введите количество вершин: ");
	scanf_s("%d", &n);
	int** matr1 = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr1[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr1[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matr1[i][j] = rand() % 2;
			matr1[j][i] = matr1[i][j];
			if (i == j)
				matr1[i][j] = 0;
		}

	}



	printf("\n   Матрица M1:    \n№  ");
	for (int i = 0; i < n; i++) {
		printf(" %d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("__");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%d ", matr1[i][j]);
			printf("\n");
		}
	}

	int ver = 0, op = 0, iz = 0;
	while (1) {
		printf("\nВведите номер операции:\n1)Выбрать вершину для обхода 2)Выйти\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
		{
			int* v = (int*)malloc(sizeof(int) * n);
			for (int i = 0; i < n; i++)
				v[i] = 0;

			printf("Выберите вершину, с которой начинать обход:");
			scanf_s("%d", &ver);
			iz = 0;
			for (int i = ver - 1; i < ver; i++)
				for (int j = 0; j < n; j++) {
					if (matr1[i][j] == 1)
						iz++;
				}
			if (iz != 0) {
				for (int i = 0; i < n; i++) {
					iz = 0;
					for (int j = 0; j < n; j++) {
						if (matr1[i][j] == 1)
							iz++;
					}
					if (iz == 0)
						v[i] = 1;
				}

				if (ver <= n && ver > 0) {
					ver -= 1;
					for (int i = 0; i < n; i++) {
						while (v[i] == 0) {
							bfs(ver, v, n, matr1);
						}
					}
				}
				else
					printf("Нет вершины!");
			}
			else
				printf("Вершина изолированная!");

			free(v);
			break;
		}
		case 2:
			for (int i = 0; i < n; i++) {
				free(matr1[i]);
			}
			free(matr1);

			return 0;
		}
	}

}