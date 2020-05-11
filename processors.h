#ifndef _PROCESSORS_H
#define _PROCESSORS_H

typedef struct my_struct1
{
	char c;
	struct my_struct1 *next;
} q;
typedef struct my_struct2
{
	int quantity;
	q *head, *tail;
} Q;
/*
typedef struct my_struct3
{
	int quantity, max_memory;
	int *arr;
}stack;
*/

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/);

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_2(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*��������� ��� �������*/);

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_3(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*��������� ��� �������*/);

// �������������� ����� (����� 0 � ������ ������ �� ���������(��� ������� ESC))
int distributer(Q Queue[], char c);

// ���������� ��� �����������
int preparation(Q Queue[], int timer[], int iteration[]);

// ���������� ������ - ������� ������
void the_end(Q Queue[]);

// ������� ������
int process();

#endif // _PROCESSORS_H
