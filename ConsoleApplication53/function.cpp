#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include "Header.h"

FILE*newFP = NULL;
int answer;


void temperature(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 20.0, max = -20.0;
	int indexMin, indexMax;
	int countSupervision = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->T;
				countSupervision++;

				if (*(weather + j)->T < min)
				{
					min = *(weather + j)->T;
					indexMin = j;
				}
				if (*(weather + j)->T > max)
				{
					max = *(weather + j)->T;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("T, температура воздуха (градусы Цельсия) на высоте 2 метра над поверхностью земли\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |         %d            \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"T, температура воздуха (градусы Цельсия) на высоте 2 метра над поверхностью земли\n");
			fprintf(newFP,"_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |         %d            \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP,"\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void atmosphericPressureStation(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 1000.0, max = 0.0;
	int indexMin, indexMax;
	int countSupervision = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->PO;
				countSupervision++;

				if (*(weather + j)->PO < min)
				{
					min = *(weather + j)->PO;
					indexMin = j;
				}
				if (*(weather + j)->PO > max)
				{
					max = *(weather + j)->PO;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("P0, атмосферное давление на уровне станции (миллиметры ртутного столба)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |         %d            \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"P0, атмосферное давление на уровне станции (миллиметры ртутного столба)\n");
			fprintf(newFP,"_______________________________________________\n");
			fprintf(newFP,"                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |         %d            \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP,"\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void atmosphericPressure(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 1000.0, max = 0.0;
	int indexMin, indexMax;
	int countSupervision = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->P;
				countSupervision++;

				if (*(weather + j)->P < min)
				{
					min = *(weather + j)->P;
					indexMin = j;
				}
				if (*(weather + j)->P > max)
				{
					max = *(weather + j)->P;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}
	}
	printf("P, атмосферное давление, приведенное к среднему уровню моря \n(миллиметры ртутного столба)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |         %d            \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"P, атмосферное давление, приведенное к среднему уровню моря \n(миллиметры ртутного столба)\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |         %d            \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");	
			fprintf(newFP,"\n-----------------------------------------------------------------------\n\n");

			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void relativeHumidity(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0.0;
	int min = 1000, max = 0;
	int indexMin, indexMax;
	int countSupervision = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->U;
				countSupervision++;

				if (*(weather + j)->U < min)
				{
					min = *(weather + j)->U;
					indexMin = j;
				}
				if (*(weather + j)->U > max)
				{
					max = *(weather + j)->U;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("U, относительная влажность на высоте 2 метра над поверхностью земли\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.0lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |         %d            \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("минимальное значение   |    %d - %d.%d.2018    \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
	printf("_______________________|_______________________\n\n");
	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"U, относительная влажность на высоте 2 метра над поверхностью земли\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.0lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |         %d            \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "минимальное значение   |    %d - %d.%d.2018    \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP,"\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void windSpeed(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0.0;
	int min = 1000, max = 0;
	int indexMin, indexMax;
	int countSupervision = 0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->FF;
				countSupervision++;

				if (*(weather + j)->FF < min)
				{
					min = *(weather + j)->FF;
					indexMin = j;
				}
				if (*(weather + j)->FF > max)
				{
					max = *(weather + j)->FF;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("FF, cкорость ветра на высоте 10-12 метров над земной поверхностью, \nосредненная за 10-минутный период, непосредственно предшествовавший сроку наблюдения (метры в секунду)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |         %d            \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  |    %d - %d.%d.2018    \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"FF, cкорость ветра на высоте 10-12 метров над земной поверхностью, \nосредненная за 10-минутный период, непосредственно предшествовавший сроку наблюдения (метры в секунду)\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |         %d            \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  |    %d - %d.%d.2018    \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP,"\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void minTemperature(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 50.0, max = -20.0;
	int indexMin, indexMax;
	double countSupervision = 0.0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->Tn;
				countSupervision++;

				if (*(weather + j)->Tn < min)
				{
					min = *(weather + j)->Tn;
					indexMin = j;
				}
				if (*(weather + j)->Tn > max)
				{
					max = *(weather + j)->Tn;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("Tn, минимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |        %2.0lf         \n", countSupervision / 8.3);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"Tn, минимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |        %2.0lf         \n", countSupervision / 8.3);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "минимальное значение   | %2.1lf - %d.%d.2018   \n", min, *(weather + indexMin)->day, *(weather + indexMin)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP, "\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void maxTemperature(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 50.0, max = -20.0;
	int indexMin, indexMax;
	double countSupervision = 0.0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->Tx;
				countSupervision++;

				if (*(weather + j)->Tx < min)
				{
					min = *(weather + j)->Tx;
					indexMin = j;
				}
				if (*(weather + j)->Tx > max)
				{
					max = *(weather + j)->Tx;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("Tx, максимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |        %2.0lf         \n", countSupervision / 4);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"Tx, максимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |        %2.0lf         \n", countSupervision / 4);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP, "\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void amountOfPrecipitation(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0.0, min = 50.0, max = -20.0;
	int indexMin, indexMax, countDays = 0, count;
	double countSupervision = 0.0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				countSupervision++;
				if ((*(weather + j)->RRR > 0) && (*(weather + j+1)->RRR == 0))
				{
					sum += *(weather + j)->RRR;
				}
				
				if (*((weather + j)->hour) == 21)
				{
					count = 0;
					for (int k = j; k < j + 8; k++)
					{
						if (*(weather + k)->RRR > 0)
						{
							count++;
							//printf("%2.1lf - %d\t", *(weather + k)->RRR, *(weather + k)->day);
						}
					}
					if (count > 0)
					{
						//printf("\n-----------------------------------\n\n");
						countDays += 1;
					}
				}

				if (*(weather + j)->RRR > max)
				{
					max = *(weather + j)->RRR;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("RRR, количество выпавших осадков (миллиметры)\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("сумма осадков          |        %2.1lf         \n", sum);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("число дней с осадками  |            %d         \n", countDays);//тут я по своему алгоритму высчитывала, иногда не сходится с сайтом
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |        %2.0lf         \n", countSupervision / 4);
	printf("_______________________|_______________________\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"RRR, количество выпавших осадков (миллиметры)\n");
			fprintf(newFP,"_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "сумма осадков          |        %2.1lf         \n", sum);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "число дней с осадками  |            %d         \n", countDays);//тут я по своему алгоритму высчитывала, иногда не сходится с сайтом
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |        %2.0lf         \n", countSupervision / 4);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

void heightOfSnowCover(int sd, int sm, int ed, int em, description*weather)
{
	double sum = 0, min = 50.0, max = -20.0;
	int indexMin, indexMax;
	double countSupervision = 0.0;
	int j = 0;
	for (int i = 0; i < 792; i++)
	{
		if (*(weather + i)->day == ed && *(weather + i)->month == em)
		{
			for (j = i; j < 792; j++)
			{
				sum += *(weather + j)->sss;

				if (*(weather + j)->sss >0)
				{
					countSupervision++;
				}
				if (*(weather + j)->sss > max)
				{
					max = *(weather + j)->sss;
					indexMax = j;
				}

				if (*((weather + j)->day) == sd && *(weather + j)->month == sm)
				{
					if (*((weather + j)->hour) == 0)
						break;
				}
			}
			i = j;
		}

	}
	printf("sss, высота снежного покрова (см\n");
	printf("_______________________________________________\n");
	printf("                       |                       \n");
	printf("период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("среднее значение       |        %2.1lf         \n", sum / countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("кол-во наблюдений      |        %2.0lf         \n", countSupervision);
	printf("_______________________|_______________________\n");
	printf("                       |                       \n");
	printf("максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
	printf("_______________________|_______________________\n\n");

	printf("хотите сохранить результат в файл?1/0 : ");
	scanf("%d", &answer);
	switch (answer)
	{
	case 1:
	{
		if ((newFP = fopen("results.txt", "a")) == NULL)
		{
			perror("Error");
			system("pause");
			exit(1);
		}
		else
		{
			fprintf(newFP,"sss, высота снежного покрова (см\n");
			fprintf(newFP, "_______________________________________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "период                 |     %d.%d-%d.%d       \n", sd, sm, ed, em);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "среднее значение       |        %2.1lf         \n", sum / countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "кол-во наблюдений      |        %2.0lf         \n", countSupervision);
			fprintf(newFP, "_______________________|_______________________\n");
			fprintf(newFP, "                       |                       \n");
			fprintf(newFP, "максимальное значение  | %2.1lf - %d.%d.2018   \n", max, *(weather + indexMax)->day, *(weather + indexMax)->month);
			fprintf(newFP, "_______________________|_______________________\n\n");
			fprintf(newFP, "\n-----------------------------------------------------------------------\n\n");
			printf("\nзапись завершена\n");
		}
		fclose(newFP);
	}break;
	case 0:
	{
		printf("\n");
	}break;
	}
}

