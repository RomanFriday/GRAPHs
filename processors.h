#ifndef _PROCESSORS_H
#define _PROCESSORS_H

typedef struct my_struct1
{
	char c;
	struct my_struct1 *next;
} q;
typedef struct my_struct2
{
	int quantity;
	q *head, *tail;
} Q;
/*
typedef struct my_struct3
{
	int quantity, max_memory;
	int *arr;
}stack;
*/

// функция первого процессора вернёт 0 при нехватке памяти
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*параметры для функций*/);

// функция первого процессора вернёт 0 при нехватке памяти
int processor_2(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*параметры для функций*/);

// функция первого процессора вернёт 0 при нехватке памяти
int processor_3(Q *Queue, int *timer, int *iteration, /**/int time_to_complete /**/ /*параметры для функций*/);

// распределитель задач (вернёт 0 в случае выхода из программы(при нажатии ESC))
int distributer(Q Queue[], char c);

// подготовка для процессоров
int preparation(Q Queue[], int timer[], int iteration[]);

// завершение работы - очистка памяти
void the_end(Q Queue[]);

// процесс работы
int process();

#endif // _PROCESSORS_H
