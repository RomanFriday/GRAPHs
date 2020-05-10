#define _CRT_SECURE_NO_WARNINGS
#include "processors.h"
#include "utilits.h"
#include <stdio.h>
#include <Windows.h>

// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type)
{
	switch(type)
	{
	case 0:
		printf("\n RAM is over\n");
		break;
	case 1:
		printf("\n Incorrect! Input integer number.\n");
		break;
	case 2:
		printf("\n Please, input positive number.\n");
		break;
	case 100:
		printf("\n Forbidden to divide by zero.\n");
		break;
	case 404:
		printf("\n ERROR 404: NOT FOUND\n");
		break;
	default: break;
	};
	return NULL;
}

// ����� ��������
void change(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���� ������ �����
int input_int(int *n)
{
	int check=0;
	while(!check)//���� �� ����� �����
	{
		check=scanf("%d", n);//scanf ����� 0, ���� ����� �� �����
		if(!check)//����� ������ - �������� ����
			Err(1); //�������� ����
		fflush(stdin);//���� ��������� �� ����� - �������� ��, ��� ���������
		//���� ������ "qwerty" ��� fflush ���� ���������� ������ ���, ������� ����� �������� (��� �������).
		//���� ������ "12345���������", �� ����������� "12345"
		//���� ������ "qwerty12345", ����������� "q" - ���� ����������
	}
	return *n;
}

// ���� �������������� �����
int input_pos_int(int *n)
{
	do
	{
		input_int(n);
		if(*n<=0)
			Err(2);// �� ������������� �����
	}while(*n<=0);
	return *n;
}

// ��������� ������ ��� ���������� ������ int �������� n
int* mem2arr_1d(int **arr, int n)
{
	if( !(*arr = (int*)malloc( n*sizeof(int) )) )
		return (int*)Err(0);// ��� ������ - ���������� NULL
	return *arr;
}

// ��������� ������ ��� ��������� ������ int ��������� m*n (m �����)
int** mem2arr_2d(int ***arr, int m, int n)
{
	if( !(*arr = (int **)malloc( m*sizeof(int*) )) )
		return (int**)Err(0);// ��� ������ - ���������� NULL
	for(int i=0; i<m; i++)
		if( !mem2arr_1d( *arr+i, n) )
			return (int**)Err(0);// ��� ������ - ���������� NULL
	return *arr;
}

// ������������ ������ ���������� ������� ��������� m * ...
void free_arr_2d(int ***arr, int m)
{
	for(int i=0; i<m; i++)
		free((*arr)[i]);
	free(*arr);
	*arr=NULL;
	return;
}

// ��������� ����������� ������� �������� n
void null_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		arr[i] = 0;
	return;
}

// ��������� ���������� ������� ��������� m*n
void null_arr_2d(int **arr, int m, int n)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			arr[i][j]=0;
	return;
}

// ����� ���������� ������� ��������� m*n ��� ������������
void print_arr_2d(int **arr, int m, int n)
{
	for(int i=0; i<m; i++)
	{
		printf("\n");
		for(int j=0; j<n; j++)
			printf(" %d", arr[i][j]);
	}
	printf("\n");
}

// ����� ����������� ������� �������� n ��� ������������
void print_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		printf(" %d", arr[i]);
	return;
}

// ���������������� ���������� �������
void transpose_square(int **mat, int n)
{
	for(int i=0; i*2<n; i++)
		for(int j=0; j<n; j++)
			change(mat[i]+j, mat[j]+i);
}

// ������ �������
void reverse(int *arr, int n)
{
	for(int i=0; i*2<n; i++)
		change(arr+i, arr+n-1-i);
}

// �������� �������� �������
q* create_element(char c)
{
	q *New;
	if( !(New = (q*)malloc(sizeof(q))) )
		return (q*)Err(0);
	New->c = c;
	New->next = NULL;
	return New;
}

// ���������� � �������
int Q_push(Q *Queue, q *element)
{
	if(!Queue || !element)
		return 0;
	if(Queue->quantity++==0)
		Queue->head = Queue->tail = element;
	else
	{
		element->next = Queue->head;
		Queue->head = element;
	}
	return 1;
}

// �������� �� ������� (� ������������� ������)
q Q_pop(Q *Queue)
{
	q element={0,0}, *pointer = NULL;
	if(!Queue)
		return element;
	if(!Queue->head || !Queue->quantity)
		return element;
	element = *(Queue->tail);
	pointer = Queue->tail;
	if(--Queue->quantity==0)// ������� �����
	{
		free(pointer);
		Queue->head = Queue->tail = NULL;
	}
	else// ���� ���� �� 1 �������
	{
		// ���������� ��������� �� �������������
		for(pointer = Queue->head; pointer->next && pointer->next!=Queue->tail;)
			pointer = pointer->next;
		Queue->tail = pointer;// ��������� �����
		element = *pointer;// ��������� ������������ ��������
		free(pointer->next);
		Queue->tail->next = NULL;
	}
	return element;
}

// �������� ���� ��������� �� �������
void Q_clear(Q *Queue)
{
	if(!Queue->head)
		return;
	q *cur = Queue->head;// ���������� �������
	Queue->head = Queue->head->next;// �������� ������
	Q_clear(Queue); // ������� ��������� ��������
	free(cur);
	Queue->head = Queue->tail = NULL;// ��������� ������ ����
	Queue->quantity = 0;
}


/*
int stack_realloc(stack *st, int new_size)
{

}

int stack_push(stack *st, int inf)
{
	if(!st)
		return 0;
	if(!st->arr)
		if( !(st->arr = (int*)malloc(2*sizeof(int))) )
			return Err(0);
	if(st->quantity++>=st->max_memory)
		if(!stack_realloc(st, max_memory*2+1/(max_memory+1))) //1+(max_memory+1) - ���� max_m = 0, ��������� ������ �� 1 �������
			return 0;
	st->arr[st->quantity-1] = inf;
	return 1;
}
*/




// ����� ���������� ������
int complited(int performed, int total, int scale_lenght)
{
	if(total==0)
		return Err(100);
	for(int i=0; i<scale_lenght; i++)
		if(i<performed*scale_lenght/total)
			printf("%c",178); // ���������
		else
			printf("%c", 176); // �� ���������
	if(performed>=total)
		return 1;
	return 0;
}

