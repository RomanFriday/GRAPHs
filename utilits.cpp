#include "utilits.h"
#include "graph_2d_min_way.h"
#include <stdio.h>
#include <Windows.h>

// Вывести сообщение по коду ошибки. Возвращается всегда 0
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

// смена значений
void change(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ввод целого числа
int input_int(int *n)
{
	int check=0;
	while(!check)//пока не ввели число
	{
		check=scanf("%d", n);//scanf вернёт 0, если ввели НЕ число
		if(!check)//ввели символ - неверный ввод
			Err(1); //неверный ввод
		fflush(stdin);//если прочитали НЕ число - отбросим всё, что прочитали
		//если ввести "qwerty" без fflush цикл повторится столко раз, сколько здесь символов (без первого).
		//если ввести "12345вралылпаы", то прочитается "12345"
		//если ввести "qwerty12345", прочитается "q" - цикл повторится
	}
	return *n;
}

// ввод положительного числа
int input_pos_int(int *n)
{
	do
	{
		input_int(n);
		if(*n<=0)
			Err(2);// не положительное число
	}while(*n<=0);
	return *n;
}

// выделение памяти под одномерный массив int размером n
int* mem2arr_1d(int **arr, int n)
{
	if( !(*arr = (int*)malloc( n*sizeof(int) )) )
		return (int*)Err(0);// нет памяти - возвращаем NULL
	return *arr;
}

// выделение памяти под двумерный массив int размерами m*n (m строк)
int** mem2arr_2d(int ***arr, int m, int n)
{
	if( !(*arr = (int **)malloc( m*sizeof(int*) )) )
		return (int**)Err(0);// нет памяти - возвращаем NULL
	for(int i=0; i<m; i++)
		if( !mem2arr_1d( *arr+i, n) )
			return (int**)Err(0);// нет памяти - возвращаем NULL
	return *arr;
}

// освобождение памяти двумерного массива размерами m * ...
void free_arr_2d(int ***arr, int m)
{
	for(int i=0; i<m; i++)
		free((*arr)[i]);
	free(*arr);
	*arr=NULL;
	return;
}

// обнуление одномерного массива размером n
void null_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		arr[i] = 0;
	return;
}

// обнуление двумерного массива размерами m*n
void null_arr_2d(int **arr, int m, int n)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			arr[i][j]=0;
	return;
}

// вывод двумерного массива размерами m*n без варавнивания
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

// вывод одномерного массива размером n без выравнивания
void print_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		printf(" %d", arr[i]);
	return;
}

// транспонирование квадратной матрицы
void transpose_square(int **mat, int n)
{
	for(int i=0; i*2<n; i++)
		for(int j=0; j<n; j++)
			change(mat[i]+j, mat[j]+i);
}

// реверс массива
void reverse(int *arr, int n)
{
	for(int i=0; i*2<n; i++)
		change(arr+i, arr+n-1-i);
}
