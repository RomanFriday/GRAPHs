// Представить модель работы трёх процессоров
// Распределитель задач посылает команды для исполнения для каждого процессора
// Поток задач для каждого из процессоров формируется в виде очереди
// Юркин Роман ИВТ-13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "processors.h"
#include "utilits.h"

void main()
{
	system("color F0");
	printf(" Model of the thee processors by Roman Yurkin IVT-13\n\n");
	system("pause");
	process();
	printf("\n\n");
	system("pause");
	return;
}