#include "processors.h"
#include "functions_with_queue.h"
#include "utilits.h"
#include <stdio.h>
#include <Windows.h>

// ¬ывести сообщение по коду ошибки. ¬озвращаетс€ всегда 0
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

// обнуление одномерного массива размером n
void null_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		arr[i] = 0;
	return;
}

// шкала выполнени€ задачи
int complited(int performed, int total, int scale_lenght)
{
	if(total==0)
		return Err(100);
	for(int i=0; i<scale_lenght; i++)
		if(i<performed*scale_lenght/total)
			printf("%c",178); // заполнено
		else
			printf("%c", 176); // не заполнено
	if(performed>=total)
		return 1;
	return 0;
}

