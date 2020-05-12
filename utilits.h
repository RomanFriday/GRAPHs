#ifndef _UTILITS_H
#define _UTILITS_H
#include "functions_with_queue.h"

#define ESC 27

// ¬ывести сообщение по коду ошибки. ¬озвращаетс€ всегда 0
int Err(int type);

// обнуление одномерного массива размером n
void null_arr_1d(int *arr, int n);

// шкала выполнени€ задачи (по времени)
int complited(int performed, int total, int scale_lenght);

#endif // _UTILITS_H