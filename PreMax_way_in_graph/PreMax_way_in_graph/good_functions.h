#ifndef _GOOD_FUNCTIONS_H
#define _GOOD_FUNCTIONS_H

// Вывести сообщение по коду ошибки. Возвращается всегда 0
int Err(int type);

// ввод целого числа
int input_int(int *n);

// ввод положительного числа
int input_pos_int(int *n);

// выделение памяти под одномерный массив int размером n
int* mem2arr1(int **arr, int n);

// выделение памяти под двумерный массив int размерами m*n (m строк)
int** mem2arr2(int ***arr, int m, int n);

// освобождение памяти двумерного массива размерами m * ...
void free_arr2(int ***arr, int m);

// обнуление одномерного массива размером n
void null_arr1(int *arr, int n);

// обнуление двумерного массива размерами m*n
void null_arr2(int **arr, int m, int n);

// вывод двумерного массива размерами m*n без варавнивания
void print_arr2(int **arr, int m, int n);

// вывод одномерного массива размером n без выравнивания
void print_arr1(int *arr, int n);

#endif //_GOOD_FUNCTIONS_H