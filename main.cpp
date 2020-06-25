﻿// Задано N городов c номерами от 1 до N и сеть из M дорог с односторонним движением между ними. 
// Каждая дорога задается тройкой (i, j, k), где
// i - номер города, в котором дорога начинается,
// j - номер города, в котором дорога заканчивается, а k - ее длина (число k - натуральное).
// Дороги друг с другом могут пересекаться только в концевых городах.
// Все пути между двумя указанными городами A и B можно упорядочить в список по неубыванию их длин (если есть несколько путей одинаковой длины, то выбираем один из них). 


// Необходимо найти один из путей, который может быть вторым в списке. 
// Вывести его длину L и города, через которые он проходит.
// Юркин Роман ИВТ-13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include "second_min_way.h"
#include "utilits.h"

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
	if(!mem2arr_2d(&mat, N, N))
		return 0;
	if(!mem2arr_2d(&road, M, 3))
		return 0;
	null_arr_2d(mat, N, N);
	input_roads(mat, N, road, M);
	input_start_end(&start, &end, N);
	system("cls");
	print_arr_2d(mat, N, N);
	printf("\nFrom %d to %d...\n", start, end);
	second_min(mat, N, start, end, road, M);
	free_arr_2d(&mat, N);
	printf("\n\n");
	system("pause");
	return 0;
}

/*
Примеры:

4
7
0 1 3
1 1 4
0 2 12
1 3 3
1 2 4
2 3 3
3 0 1

0
3

был баг с 2 3

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



3
3
0 1 2
1 2 3
2 0 4
0
2



3
4
0 1 2
1 2 3
2 0 4
1 1 5






-----------------------


6
6
0 1 1
1 2 2
2 3 3
2 4 4
3 4 4
4 5 5
0
5


------------------------
3
4
0 1 1
1 1 4
1 2 3
0 2 4
0
2








































*/