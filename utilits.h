#ifndef _UTILITS_H
#define _UTILITS_H

// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type);

//����� ��������
void change(int *a, int *b);

// ���� ������ �����
int input_int(int *n);

// ���� �������������� �����
int input_pos_int(int *n);

// ��������� ������ ��� ���������� ������ int �������� n
int* mem2arr_1d(int **arr, int n);

// ��������� ������ ��� ��������� ������ int ��������� m*n (m �����)
int** mem2arr_2d(int ***arr, int m, int n);

// ������������ ������ ���������� ������� ��������� m * ...
void free_arr_2d(int ***arr, int m);

// ��������� ����������� ������� �������� n
void null_arr_1d(int *arr, int n);

// ��������� ���������� ������� ��������� m*n
void null_arr_2d(int **arr, int m, int n);

// ����� ���������� ������� ��������� m*n ��� ������������
void print_arr_2d(int **arr, int m, int n);

// ����� ����������� ������� �������� n ��� ������������
void print_arr_1d(int *arr, int n);

// ���������������� ���������� �������
void transpose_square(int **mat, int n);

// ������ �������
void reverse(int *arr, int n);

// ���������� � �������
int Q_push(Q *Queue, q *element);

// �������� �� ������� (� ������������� ������)
q Q_pop(Q *Queue);

#endif // _UTILITS_H