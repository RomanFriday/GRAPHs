#ifndef _GRAPH_2D_MIN_WAY_H
#define _GRAPH_2D_MIN_WAY_H

// ���� ���������� ������� � �����
void input_N_M(int *N, int *M);

// ���� ������ (i, j, k) � ������� ����������
void input_road(int *i, int *j, int *k, int **mat, int N);

// ���� ����� (i, j, k) � �������
void input_roads(int **mat, int N, int **road, int M);

// ���� ������ ������������� ������
int input_item(int *item, int N);

// ���� ���������� � ��������� ������
void input_start_end(int *start, int *end, int N);

// ����� ���������� ����� ��������
int sum_roads(int **mat, int N);

// ��� � ��������� ��������, ����� 0 � ������ ����������
int deixtra_step(int **mat, int **arr, int N, int *flag, int max);

// �������� �������� ��� ������������� ����.
// ���������� ������: way[i] =  �����, �������������� way[i]
// trivial = 1, ���� ���� ����� ����������� ���� � ��� �� �����
void deixtra_min(int **mat, int **arr, int N, int start, int trivial);

// ���������� ������ ���� � �����
int lenght_way(int **mat, int N, int *way, int start, int end);

// ���������� ����������� ����� ������������� �����
int not_trivial(int **mat, int N, int **arr, int *mini, int start, int end);

// ���������� ������������ ���� arr-����.������, minimum-������ ���, sec-������, mincnt-����� ��������� ������
int trivial(int **mat, int N, int **road, int M, int **arr, int start, int end, int *minimum, int *mincnt, int *secmin);

// ����� �� ������������ ���� arr-����.������, mini-����� �����
void print_nt_way(int **mat, int N, int **arr, int mini, int start, int end, int nt);

// ����� ������������ ���� arr-����.������, mincnt-����� ��������� ������
void print_tr_way(int **mat, int **arr, int N, int **road, int start, int end, int mincnt, int tr);

// ������ ����������� ���������� ��
int second_min(int **mat, int N, int start, int end, int **road, int M);

#endif// _GRAPH_2D_MIN_WAY_H