#ifndef _UTILITS_H
#define _UTILITS_H

// Вывести сообщение по коду ошибки. Возвращается всегда 0
int Err(int type);

//смена значений
void change(int *a, int *b);

// ввод целого числа
int input_int(int *n);

// ввод положительного числа
int input_pos_int(int *n);

// выделение памяти под одномерный массив int размером n
int* mem2arr_1d(int **arr, int n);

// выделение памяти под двумерный массив int размерами m*n (m строк)
int** mem2arr_2d(int ***arr, int m, int n);

// освобождение памяти двумерного массива размерами m * ...
void free_arr_2d(int ***arr, int m);

// обнуление одномерного массива размером n
void null_arr_1d(int *arr, int n);

// обнуление двумерного массива размерами m*n
void null_arr_2d(int **arr, int m, int n);

// вывод двумерного массива размерами m*n без варавнивания
void print_arr_2d(int **arr, int m, int n);

// вывод одномерного массива размером n без выравнивания
void print_arr_1d(int *arr, int n);

// транспонирование квадратной матрицы
void transpose_square(int **mat, int n);

// реверс массива
void reverse(int *arr, int n);

// добавление в очередь
int Q_push(Q *Queue, q *element);

// удаление из очереди (с освобождением памяти)
q Q_pop(Q *Queue);

#endif // _UTILITS_H