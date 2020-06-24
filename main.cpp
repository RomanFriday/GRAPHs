// Задано N городов c номерами от 1 до N и сеть из M дорог с односторонним движением между ними. 
// Каждая дорога задается тройкой (i, j, k), где
// i - номер города, в котором дорога начинается,
// j - номер города, в котором дорога заканчивается, а k - ее длина (число k - натуральное).
// Дороги друг с другом могут пересекаться только в концевых городах.
// Все пути между двумя указанными городами A и B можно упорядочить в список по неубыванию их длин (если есть несколько путей одинаковой длины, то выбираем один из них). 


// (я вначале делал для пре - МАКСИМАЛЬНОГО)


// Необходимо найти один из путей, который может быть вторым в списке. 
// Вывести его длину L и города, через которые он проходит.
// Юркин Роман ИВТ-13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include "second_min_way.h"
#include "good_functions.h"
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
		printf("\n Roads no more than cities in square!\n");
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











int main()
{
	system("color F0");
	printf("\n Second min way int graph by Yurkin Roman IVT-13\n");
	// количество городов и дорог(прописано в условии задачи)
	// взвешенная матрица смежности,
	// матрица дорог M * 3 - (i, j, k)
	// начальный город, конченый город
	int N, M, **mat, **road, start, end;
	input_N_M(&N, &M);
	if(!mem2arr2(&mat, N, N))
		return 0;
	if(!mem2arr2(&road, M, 3))
		return 0;
	null_arr2(mat, N, N);
	input_roads(mat, N, road, M);
	input_start_end(&start, &end, N);
	system("cls");
	print_arr2(mat, N, N);
	printf("\nFrom %d to %d...\n", end, start);
	second_min(mat, N, start, end, road, M);
	free_arr2(&mat, N);
	printf("\n\n");
	system("pause");
	return 0;
}

/*
Примеры:

4
7
0 1 3
1 1 1000
0 2 12
1 3 3
1 2 4
2 3 3
3 0 1

0
3


-------------------------

5
5
0 1 1
1 2 1
2 3 2
3 1 3
1 4 5

0
4


     C____D
	  \  /
  A____\/_____E
        B

-----------------------








































*/