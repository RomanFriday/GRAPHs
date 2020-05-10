#include "processors.h"
#include "utilits.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define ESC 27
#define CNT_PROC 3
const int LEAD_TIME[CNT_PROC]={
	3500, // время выполнения задачи первого процессора в миллисек
	6000, // время выполнения задачи второго процессора в миллисек
	2500 // время выполнения задачи третьего процессора в миллисек
};

// функция первого процессора вернёт 0 при нехватке памяти
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*параметры для функций*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc1 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//какая-то обработка задачи
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func1_1();
		//	return 1;
		//case 1:
		//	if( !func1_2() )
		//		return 0;
		//	return 1;
		//default: break;// все функции выполнены
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// функция первого процессора вернёт 0 при нехватке памяти
int processor_2(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*параметры для функций*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc2 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//какая-то обработка задачи
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func2_1();
		//	return 1;
		//case 1:
		//	func2_2();
		//	return 1;
		//default: break;// все функции выполнены
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// функция первого процессора вернёт 0 при нехватке памяти
int processor_3(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*параметры для функций*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc3 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//какая-то обработка задачи
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func3_1();
		//	return 1;
		//case 1:
		//	func3_2();
		//	return 1;
		//default: break;// все функции выполнены
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// распределитель задач (вернёт 0 в случае выхода из программы(при нажатии ESC))
int distributer(Q Queue[], char c)
{
	if(c==ESC)// завершение программы
		return 0;
	// добавление в очередь команд первого процессора
	// первый процессор обрабатывает цифры
	if(c>='0'&&c<='9')
		if( !Q_push(Queue+0, create_element(c)) )
			return 0;
		else
			return 1;
	// добавление в очередь команд второго процессора
	// второй процессор обрабатывает латинские буквы
	if(c>='A'&&c<='Z' || c>='a'&&c<='z')
		if( !Q_push(Queue+1, create_element(c)) )
			return 0;
		else
			return 1;
	// добавление в очередь команд третьего процессора
	// третий процессор обрабатывает остальные символы
	if( !Q_push(Queue+2, create_element(c)) )
		return 0;
	return 1;
}

// подготовка для процессоров
int preparation(Q Queue[], int timer[], int iteration[])
{
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].quantity = 0;
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].head = Queue[i].tail = NULL;
	int now_t = clock();
	for(int i=0; i<CNT_PROC; i++)
		timer[i] = now_t;
	null_arr_1d(iteration, CNT_PROC);
	return 1;
}

// завершение работы - очистка памяти
void the_end(Q Queue[])
{
	for(int i=0; i<CNT_PROC; i++)
		Q_clear(Queue+i);
}

// процесс работы
int process()
{
	char c = 0;
	Q Queue[CNT_PROC];// массив очередей для каждого из процессоров
	int timer[CNT_PROC],// массив таймеров для процессоров (по миллисекундам)
		iteration[CNT_PROC],// какая по счёту функция выполняется в каждом процессорке
		now_time = clock(); // задержка для прорисовки
	preparation(Queue, timer, iteration);
	while(1)
	{
		if(_kbhit())
		{
			c = _getch();
		if(!distributer(Queue, c))
			break;
		}
		if(clock()-now_time > 200)// обновление каждые 200 миллисек
		{
			now_time = clock();
			system("cls");
			printf(" Input characters-command to processors:\n\n");
			for(int i=0;i<CNT_PROC; i++)
			{
				for(q *cur=Queue[i].head; cur; cur=cur->next )
					printf("%c", cur->c);
				printf("\n");
			}
			// выов функций процессоров
			// ------------------------------------------------------------
			// вызвать по-циклу можно лишь в том случае, если все параметры
			// функций процессоров одинакового типа
			// ------------------------------------------------------------
			if( !processor_1(Queue+0, timer+0, iteration+0, LEAD_TIME[0]) /*параметры для функций 1 проц*/)
				return 0;
			if( !processor_2(Queue+1, timer+1, iteration+1, LEAD_TIME[1]) /*параметры для функций 2 проц*/)
				return 0;
			if( !processor_3(Queue+2, timer+2, iteration+2, LEAD_TIME[2]) /*параметры для функций 3 проц*/)
				return 0;
		}
	}
	the_end(Queue);
	return 1;
}