#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct student
{
	char Famil[20];
	char Name[20], Facult[20];
	int Nomzach;
};

void findBy(student st[], int len) {
	//index 1 for name, 2 for famil, 3 for facul, 4 for nomzach
	printf("Введите параметр поиска\n");
	printf("1 - Имя \n2 - Фамилия\n3 - Факультет \n4 - Номер зачетки\n");
	int index;
	int paramz = 0;
	char param[20];
	char ch;
	scanf("%d", &index);


	if ((index > 0) && (index < 4)) {
		printf("Введите параметр поиска: ");
		scanf("%20s", &param);
		printf("\n");
	}
	else if (index == 4) {
		printf("Введите номер: ");
		scanf("%d", &paramz);
		printf("\n");
	}

	for (int i = 0; i < len; i++) {
		student stud = st[i];
		switch (index) {
		case 1:
			if (strcmp(stud.Name, param) == 0) {
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 2:
			if (strcmp(stud.Famil, param) == 0) {
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 3:
			if (strcmp(stud.Facult, param) == 0) {
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 4:
			if (stud.Nomzach == paramz) {
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		default:
			break;
		}
	}
	printf("\n");
}

int maxDiffMin(int mas[], int len) {

	int max = mas[0];
	int min = mas[0];

	for (int i = 1; i < len; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
		else if (mas[i] < min) {
			min = mas[i];
		}
	}

	return max - min;
}

int* randMas(int size) {
	int* mas = (int*)malloc(size * sizeof(int));

	int min = 0;
	int max = 100;

	for (int i = 0; i < size; i++) {
		mas[i] = min + rand() % (max - min + 1);//заполнение массива случайными числами
	}

	return mas;
	free(mas);// Освобождение памяти
}

void sumRowCol(int mas[3][3]) {
	int rowsum = 0;
	int colsum = 0;

	for (int i = 0; i < 3; i++) {
		rowsum = 0;
		for (int j = 0; j < 3; j++)
		{
			rowsum = rowsum + mas[i][j];
		}
		printf("В %d строке: %d\n", i, rowsum);
	}

	for (int i = 0; i < 3; i++) {
		colsum = 0;
		for (int j = 0; j < 3; j++)
		{
			colsum = colsum + mas[j][i];
		}
		printf("В %d колонке: %d\n", i, colsum);
	}
}

void createStudents(student stud[]) {
	char ch;
	for (int i = 0; i < 3; i++) {
		printf("Введите Фамилию студента\n");
		scanf("%20s", stud[i].Famil);

		printf("Введите Имя студента %s\n", stud[i].Famil);
		scanf("%20s", stud[i].Name);

		printf("Введите название Факультета студента %s %s\n", stud[i].Famil, stud[i].Name);
		scanf("%20s", stud[i].Facult);

		printf("Введите номер зачетной книжки студента %s %s\n", stud[i].Famil, stud[i].Name);
		scanf("%d", &stud[i].Nomzach);
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
}


int main() {
	struct student stud[3];
	setlocale(LC_ALL, "Rus");

	//Первое задание
	int intmas[5] = { 1,2,3,4,5 };
	int dif = maxDiffMin(intmas, 5);
	printf("Задание 1\n");
	printf("Разница элементов: %d\n", dif);

	//Второе задание
	printf("Задание 2\n");
	int size = 10;
	int* randmas = randMas(size);
	for (int i = 0; i < size; i++) {
		printf("%d ", randmas[i]);
	}
	printf("\n");

	//Третье задание
	printf("Задание 3\n");
	printf("Введите число элементов: ");
	scanf("%d", &size);
	int* randmas2 = randMas(size);
	for (int i = 0; i < size; i++) {
		printf("%d ", randmas2[i]);
	}
	printf("\n");

	//Четвертое задание
	printf("Задание 4\n");
	int mas[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	sumRowCol(mas);

	//Пятое задание
	printf("Задание 5\n");
	createStudents(stud);

	findBy(stud, 3);


	getchar();

	return 0;
}
