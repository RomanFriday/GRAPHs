#ifndef _UTILITS_H
#define _UTILITS_H
#include "functions_with_queue.h"

#define ESC 27

// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type);

// ��������� ����������� ������� �������� n
void null_arr_1d(int *arr, int n);

// ����� ���������� ������ (�� �������)
int complited(int performed, int total, int scale_lenght);

#endif // _UTILITS_H