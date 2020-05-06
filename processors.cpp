#include <conio.h>
#include "processors.h"
#include "utilits.h"
#define ESC 27/*-32 27*/
#define CNT_PROC 3
// подготовка для процессоров
int preparation(Q Queue[])
{
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].quantity = 0;
	return 1;
}

// распределитель задач (вернёт 0 в случае выхода из программы(при нажатии ESC))
int distributer(Q Queue[], char c)
{
	if(c==-32)
		if(_getch()==ESC)// завершение программы
			return 0;

	return 1;
}

// процесс работы
int process()
{
	char c=0;
	Q Queue[CNT_PROC];// массив очередей для каждого из процессоров
	preparation(Queue);
	while(1)
	{
		if(_kbhit())
		{
			c = _getch();
		if(!distributer(Queue, c))
			return 1;
		}
		// вызов процов                        (может, сделать в виде цила вызова???)
		P1;
		P2;
		P3;
	}
	return 1;
}