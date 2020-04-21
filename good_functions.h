#ifndef _GOOD_FUNCTIONS_H
#define _GOOD_FUNCTIONS_H

// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type);

// ���� ������ �����
int input_int(int *n);

// ���� �������������� �����
int input_pos_int(int *n);

// ��������� ������ ��� ���������� ������ int �������� n
int* mem2arr1(int **arr, int n);

// ��������� ������ ��� ��������� ������ int ��������� m*n (m �����)
int** mem2arr2(int ***arr, int m, int n);

// ������������ ������ ���������� ������� ��������� m * ...
void free_arr2(int ***arr, int m);

// ��������� ����������� ������� �������� n
void null_arr1(int *arr, int n);

// ��������� ���������� ������� ��������� m*n
void null_arr2(int **arr, int m, int n);

// ����� ���������� ������� ��������� m*n ��� ������������
void print_arr2(int **arr, int m, int n);

// ����� ����������� ������� �������� n ��� ������������
void print_arr1(int *arr, int n);

#endif //_GOOD_FUNCTIONS_H