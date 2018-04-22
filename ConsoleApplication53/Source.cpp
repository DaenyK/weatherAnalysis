#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include "Header.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	FILE * info = NULL;
	description * pogoda = NULL;
	pogoda = (description*)malloc(792 * sizeof(description));

	if ((info = fopen("22.txt", "r")) == NULL)
	{
		perror("Error");
		system("pause");
		exit(1);
	}
	else
	{
		if (pogoda == NULL)
		{
			printf("error\n");
			EXIT_FAILURE;
		}
		else
		{
			char c;
			int countStr = 0;
			while (!feof(info))
			{
				fscanf(info, "%c", &c);
				if (c == '\n')
					countStr++;
			}
			//cout <<endl<< countStr << endl;
			rewind(info);

			(pogoda)->day = (int*)malloc(792 * sizeof(int));
			(pogoda)->month = (int*)malloc(792 * sizeof(int));
			(pogoda)->year = (int*)malloc(792 * sizeof(int));
			(pogoda)->hour = (int*)malloc(792 * sizeof(int));
			(pogoda)->min = (int*)malloc(792 * sizeof(int));

			(pogoda)->T = (double*)malloc(792 * sizeof(double));
			(pogoda)->P = (double*)malloc(792 * sizeof(double));
			(pogoda)->PO = (double*)malloc(792 * sizeof(double));

			(pogoda)->U = (int*)malloc(792 * sizeof(int));
			(pogoda)->FF = (int*)malloc(792 * sizeof(int));

			(pogoda)->Tn = (double*)malloc(792 * sizeof(double));
			(pogoda)->Tx = (double*)malloc(792 * sizeof(double));
			(pogoda)->RRR = (double*)malloc(792 * sizeof(double));

			(pogoda)->sss = (int*)malloc(792 * sizeof(int));

			int* dd, *mm, *yy, *hh, *minutes, *u, *ff, *SSS;
			dd = (int*)malloc(792 * sizeof(int));
			mm = (int*)malloc(792 * sizeof(int));
			yy = (int*)malloc(792 * sizeof(int));
			hh = (int*)malloc(792 * sizeof(int));
			minutes = (int*)malloc(792 * sizeof(int));
			u = (int*)malloc(792 * sizeof(int));
			ff = (int*)malloc(792 * sizeof(int));
			SSS = (int*)malloc(792 * sizeof(int));

			double *t, *po, *p, *tx, *tn, *rrr;
			t = (double*)malloc(792 * sizeof(double));
			po = (double*)malloc(792 * sizeof(double));
			p = (double*)malloc(792 * sizeof(double));
			tx = (double*)malloc(792 * sizeof(double));
			tn = (double*)malloc(792 * sizeof(double));
			rrr = (double*)malloc(792 * sizeof(double));


			for (int i = 0; i < 792; i++)
			{
				fscanf(info, "%d.%d.%d %d:%d\t%lf\t%lf\t%lf\t%d\t%d\t%lf\t%lf\t%lf\t%d",
					&dd[i], &mm[i], &yy[i],
					&hh[i], &minutes[i],
					&t[i], &po[i], &p[i],
					&u[i], &ff[i],
					&tn[i], &tx[i], &rrr[i],
					&SSS[i]);

				(pogoda + i)->day = &dd[i];
				(pogoda + i)->month = &mm[i];
				(pogoda + i)->year = &yy[i];
				(pogoda + i)->hour = &hh[i];
				(pogoda + i)->min = &minutes[i];
				(pogoda + i)->U = &u[i];
				(pogoda + i)->FF = &ff[i];
				(pogoda + i)->sss = &SSS[i];

				(pogoda + i)->T = &t[i];
				(pogoda + i)->PO = &po[i];
				(pogoda + i)->P = &p[i];
				(pogoda + i)->Tx = &tx[i];
				(pogoda + i)->Tn = &tn[i];
				(pogoda + i)->RRR = &rrr[i];


				/*printf("%d.%d.%d %d:%d0\t%2.1lf\t%2.1lf\t%2.1lf\t%d\t%d\t%2.1lf\t%2.1lf\t%2.1lf\t%d\n",
					*(pogoda + i)->day, *(pogoda + i)->month, *(pogoda + i)->year,
					*(pogoda + i)->hour, *(pogoda + i)->min,
					*(pogoda + i)->T, *(pogoda + i)->PO, *(pogoda + i)->P,
					*(pogoda + i)->U, *(pogoda + i)->FF,
					*(pogoda + i)->Tx, *(pogoda + i)->Tn,*(pogoda + i)->RRR,
					*(pogoda + i)->sss);*/
			}
			rewind(info);

		}
		fclose(info);
	}

	int continuation;

	do {
		int symbol, startDay, startMonth, endDay, endMonth;

		printf("здравствуйте! введите, пожалуйста, значение для параметра\n\n");
		printf("1 - температура воздуха (по Цельсию)\n");
		printf("2 - атмосферное давление на уровне станции\n");
		printf("3 - атмосферное давление, приведенное к среднему уровню моря\n");
		printf("4 - относительная влажность на высоте 2 метра над поверхностью земли\n");
		printf("5 - cкорость ветра на высоте 10-12 метров над земной поверхностью\n");
		printf("6 -  мин. температура воздуха (градусы Цельсия) за прошедший период\n");
		printf("7 - макс. температура воздуха (градусы Цельсия) за прошедший период\n");
		printf("8- количество выпавших осадков (миллиметры)\n");
		printf("9 - высота снежного покрова (см)\n");
		printf("10 - выводит все и сразу\n");
		printf("0 - выход\n\nвведите нужную цифру: ");

		scanf("%d", &symbol);
		if (symbol == 0)
		{
			exit(1);
		}

		printf("\nпериод времени ограничен!\nрамки которого являются даты с 1 января по 9 апреля 2018 года, включительно");
		printf("\nпожалуйста, имейте в виду, если вы внесете несуществующие даты, программа остановится\n");
		printf("\nвведите период, который вас интересует (н: 9.2-4.3) : ");
		scanf("%d.%d-%d.%d", &startDay, &startMonth, &endDay, &endMonth);
		printf("\n");

		switch (symbol)
		{
		case 0:
		{
			exit(1);
		}break;
		case 1:
		{
			//printf("T, температура воздуха (градусы Цельсия) на высоте 2 метра \nнад поверхностью земли\n");
			temperature(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 2:
		{
			//printf("P0, атмосферное давление на уровне станции (миллиметры ртутного столба)\n");
			atmosphericPressureStation(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 3:
		{
			//printf("P, атмосферное давление, приведенное к среднему уровню моря \n(миллиметры ртутного столба)\n");
			atmosphericPressure(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 4:
		{
			//printf("U, относительная влажность на высоте 2 метра над поверхностью земли\n");
			relativeHumidity(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 5:
		{
			//printf("FF, cкорость ветра на высоте 10-12 метров над земной поверхностью, \nосредненная за 10-минутный период, непосредственно предшествовавший сроку наблюдения (метры в секунду)\n");
			windSpeed(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 6:
		{
			//printf("Tn, минимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
			minTemperature(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 7:
		{
			//printf("Tx, максимальная температура воздуха (градусы Цельсия) за прошедший \nпериод (не более 12 часов)\n");
			maxTemperature(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 8:
		{
			//printf("RRR, количество выпавших осадков (миллиметры)\n");
			amountOfPrecipitation(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 9:
		{
			//printf("sss, высота снежного покрова (см\n");
			heightOfSnowCover(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		case 10:
		{
			temperature(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			atmosphericPressureStation(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			atmosphericPressure(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			relativeHumidity(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			windSpeed(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			minTemperature(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			maxTemperature(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			amountOfPrecipitation(startDay, startMonth, endDay, endMonth, pogoda);
			printf("\n-----------------------------------------------------------------------\n\n");
			heightOfSnowCover(startDay, startMonth, endDay, endMonth, pogoda);
		}break;
		}
		printf("\nхотите продолжить?1/0 :");
		scanf("%d", &continuation);
		system("cls");
	} while (continuation == 1);


}


