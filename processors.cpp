#include "processors.h"
#include "utilits.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define ESC 27
#define CNT_PROC 3

// ����� ���������� ������
int complited(int time_left, int lead_time)
{
	for(int i=0; i<50; i++)
		if(i<time_left*50/lead_time)
			printf("%c",178); // ���������
		else
			printf("%c", 176); // �� ���������
	printf("\n");
	if(time_left>lead_time)
		return 1;
	return 0;
}

// ������� ������� ����������
void process_1(Q *Queue, int *timer, int now_time)
{
	if(!Queue->quantity)
	{
		*timer = now_time;
		return;
	}


}

// �������������� ����� (����� 0 � ������ ������ �� ���������(��� ������� ESC))
int distributer(Q Queue[], char c)
{
	if(c==ESC)// ���������� ���������
		return 0;
	// ���������� � ������� ������ ������� ����������
	// ������ ��������� ������������ �����
	if(c>='0'&&c<='9')
		if( !Q_push(Queue+0, create_element(c)) )
			return 0;
		else
			return 1;
	// ���������� � ������� ������ ������� ����������
	// ������ ��������� ������������ ��������� �����
	if(c>='A'&&c<='Z' || c>='a'&&c<='z')
		if( !Q_push(Queue+1, create_element(c)) )
			return 0;
		else
			return 1;
	// ���������� � ������� ������ �������� ����������
	// ������ ��������� ������������ ��������� �������
	if( !Q_push(Queue+2, create_element(c)) )
		return 0;
	return 1;
}

// ���������� ��� �����������
int preparation(Q Queue[], int timer[])
{
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].quantity = 0;
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].head = Queue[i].tail = NULL;
	int now_t = (int)time(NULL);
	for(int i=0; i<CNT_PROC; i++)
		timer[i] = now_t;
	return 1;
}

// ���������� ������ - ������� ������
void the_end(Q Queue[])
{
	for(int i=0; i<CNT_PROC; i++)
		Q_clear(Queue+i);
}

// ������� ������
int process()
{
	char c = 0;
	Q Queue[CNT_PROC];// ������ �������� ��� ������� �� �����������
	int timer[CNT_PROC], now_time;// ������ �������� ��� ����������� (�� �������������)
	preparation(Queue, timer);
	while(1)
	{
		if(_kbhit())
		{
			c = _getch();
		if(!distributer(Queue, c))
			return 1;
		}
		system("cls");
		printf(" Input characters-command to processors:\n\n");
		for(int i=0;i<CNT_PROC; i++)
		{
			for(q *cur=Queue[i].head; cur; cur=cur->next )
				printf("%c", cur->c);
			printf("\n");
		}
		// ����� ������                        (�����, ������� � ���� ���� ������???)
		//P1;
		//P2;
		//P3;
	}
	the_end(Queue);
	return 1;
}