#include "utl.h"
#include <stdio.h>
#include <Windows.h>
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
int* mem2arr1(int **arr, int n)
{
	if( !(*arr = (int*)malloc( n*sizeof(int) )) )
		return (int*)Err(0);// ��� ������ - ���������� NULL
	return *arr;
}

// ��������� ������ ��� ��������� ������ int ��������� m*n (m �����)
int** mem2arr2(int ***arr, int m, int n)
{
	if( !(*arr = (int **)malloc( m*sizeof(int*) )) )
		return (int**)Err(0);// ��� ������ - ���������� NULL
	for(int i=0; i<m; i++)
		if( !mem2arr1( *arr+i, n) )
			return (int**)Err(0);// ��� ������ - ���������� NULL
	return *arr;
}

// ������������ ������ ���������� ������� ��������� m * ...
void free_arr2(int ***arr, int m)
{
	for(int i=0; i<m; i++)
		free((*arr)[i]);
	free(*arr);
	*arr=NULL;
	return;
}

// ��������� ����������� ������� �������� n
void null_arr1(int *arr, int n)
{
	for(int i=0; i<n; i++)
		arr[i] = 0;
	return;
}

// ��������� ���������� ������� ��������� m*n
void null_arr2(int **arr, int m, int n)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			arr[i][j]=0;
	return;
}

// ����� ���������� ������� ��������� m*n ��� ������������
void print_arr2(int **arr, int m, int n)
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
void print_arr1(int *arr, int n)
{
	for(int i=0; i<n; i++)
		printf(" %d", arr[i]);
	return;
}