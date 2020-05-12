#ifndef _PROCESSORS_H
#define _PROCESSORS_H

#include "utilits.h"
#define CNT_PROC 3
const int LEAD_TIME[CNT_PROC]={
	3500, // время выполнения задачи первого процессора в миллисек
	6000, // время выполнения задачи второго процессора в миллисек
	2500 // время выполнения задачи третьего процессора в миллисек
};
// функция первого процессора вернёт 0 при нехватке памяти
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*параметры для функций*/);

// функция первого процессора вернёт 0 при нехватке памяти
int processor_2(Q *Queue, int *timer, int *iteration, int time_to_complete/*параметры для функций*/);

// функция первого процессора вернёт 0 при нехватке памяти
int processor_3(Q *Queue, int *timer, int *iteration, int time_to_complete /*параметры для функций*/);

// распределитель задач (вернёт 0 в случае выхода из программы(при нажатии ESC))
int distributer(Q Queue[], char c);

// подготовка для процессоров
int preparation(Q Queue[], int timer[], int iteration[]);

// завершение работы - очистка памяти
void the_end(Q Queue[]);

// процесс работы
int process();

#endif // _PROCESSORS_H
