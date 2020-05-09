// Представить модель работы трёх процессоров
// Распределитель задач посылает команды для исполнения для каждого процессора
// Поток задач для каждого из процессоров формируется в виде очереди
// Юркин Роман ИВТ-13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "processors.h"
#include "utilits.h"



#include <time.h>
#include <conio.h>


void main()
{
	system("color F0");
	printf(" Model of the thee processors by Roman Yurkin IVT-13\n\n");


	int a, b, d, p1=0,e1, p2=0,e2, p3=0,e3;
	printf("\ntime P1:");scanf("%d",&e1);
	printf("\ntime P2:");scanf("%d",&e2);
	printf("\ntime P3:");scanf("%d",&e3);
	system("pause");
	a=clock();
	while(1)
	{
		if(_kbhit())
		{
			switch(_getch())
			{
			case '1': p1=clock(); break;
			case '2': p2=clock(); break;
			case '3': p3=clock(); break;
			default: return;
			};
		}
		if((d=clock())-a>100)
		{
			a=d;
			system("cls");
			printf("\n");
			if(complited(clock()-p1,e1))
				printf(" complited");
			printf("\n");
			if(complited(clock()-p2,e2))
				printf(" complited");
			printf("\n");
			if(complited(clock()-p3,e3))
				printf(" complited");
		}
	}
	system("pause");
	return;

	process();
	system("pause");
}