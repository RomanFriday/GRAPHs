#include "utilits.h"
#include "graph_2d_min_way.h"
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
	case 3:
		printf("\n Roads no more than quantity of city pairs + quantity of cities !\n");
		break;
	case 4:
		printf("\n City entered does not exist.\n");
		break;
	case 5:
		printf("\n It is forbidden to change direction.\n");
		break;
	case 404:
		printf("\n ERROR 404: NOT FOUND\n");
		break;
	default: break;;
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
