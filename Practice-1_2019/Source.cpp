#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#define SIZE 1024

void shifting_txt(char*, char);

int main()
{
	setlocale(LC_CTYPE, "rus");

	printf_s("Введите текст! (радмер до 1024 символа)\nВаш текст: ");
	char text[SIZE] = { '0' };
	char signs[] = { ' ','.',',','!','?','-',':','_','(',')', ';', '<', '>' };
	gets_s(text, SIZE);

	for (int i = 0; i < 13; i++)
	{
		shifting_txt(text, signs[i]);
	}

	int size_txt = 0;
	size_txt = strlen(text);

	int* mass_leter_num = (int*)calloc(size_txt, sizeof(int));
	char* new_text = (char*)malloc(size_txt);
	
	for (int i = 0; i < size_txt; i++)
	{
		mass_leter_num[i] = size_txt;
		new_text[i] = { '0' };
	}
	
	srand((int) time(NULL));

	for (int i = 0; i < size_txt; i++)
	{
		int num = 0;
		num = rand() % size_txt;

		if (mass_leter_num[num] == size_txt)
		{
			mass_leter_num[num] = i;
			new_text[num] = text[i];
		}
		else
		{
			i--;
			continue;
		}
	}

	new_text[size_txt] = { '\0' };

	printf_s("анаграмма выглядит следующим образом: ");
	puts(new_text);

	system("pause");

	return 0;
}

void shifting_txt(char* text, char sign)
{
	char* label_1 = text, *label_2 = text;

	while (1)
	{
		label_1 = strchr(text, sign);

		if (label_1 == NULL)
		{
			break;
		}

		label_2 = label_1 + 1;

		for (; (*label_1) != '\0'; label_1++)
		{
			(*label_1) = (*label_2);
			label_2++;
		}

		(*label_1) = '\0';
	}

	return;
}