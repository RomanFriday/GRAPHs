#include <conio.h>
#include "processors.h"
#include "utilits.h"
#define ESC 27/*-32 27*/
#define CNT_PROC 3
// ���������� ��� �����������
int preparation(Q Queue[])
{
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].quantity = 0;
	return 1;
}

// �������������� ����� (����� 0 � ������ ������ �� ���������(��� ������� ESC))
int distributer(Q Queue[], char c)
{
	if(c==-32)
		if(_getch()==ESC)// ���������� ���������
			return 0;

	return 1;
}

// ������� ������
int process()
{
	char c=0;
	Q Queue[CNT_PROC];// ������ �������� ��� ������� �� �����������
	preparation(Queue);
	while(1)
	{
		if(_kbhit())
		{
			c = _getch();
		if(!distributer(Queue, c))
			return 1;
		}
		// ����� ������                        (�����, ������� � ���� ���� ������???)
		P1;
		P2;
		P3;
	}
	return 1;
}