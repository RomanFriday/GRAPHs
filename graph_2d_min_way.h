#ifndef _GRAPH_2D_MIN_WAY_H
#define _GRAPH_2D_MIN_WAY_H

// ввод количества городов и дорог
void input_N_M(int *N, int *M);

// ввод дороги (i, j, k) с верными значени€ми
void input_road(int *i, int *j, int *k, int **mat, int N);

// ввод дорог (i, j, k) в матрицу
void input_roads(int **mat, int N, int **road, int M);

// ввод номера существующего города
int input_item(int *item, int N);

// ввод начального и конечного пункта
void input_start_end(int *start, int *end, int N);

// сумма рассто€ний между городами
int sum_roads(int **mat, int N);

// шаг в алгоритме ƒейкстры, вернЄт 0 в случае завершени€
int deixtra_step(int **mat, int **arr, int N, int *flag, int max);

// алгоритм ƒейкстры дл€ максимального пути.
// ¬озвращает массив: way[i] =  город, предшествующий way[i]
// trivial = 1, если надо найти минимальный путь в тот же город
void deixtra_min(int **mat, int **arr, int N, int start, int trivial);

// нахождение длинны пути с конца
int lenght_way(int **mat, int N, int *way, int start, int end);

// нахождение минимальной длины нетривиальных путей
int not_trivial(int **mat, int N, int **arr, int *mini, int start, int end);

// нахождение тривиального пути arr-спец.массив, minimum-первый мин, sec-второй, mincnt-номер убираемой дороги
int trivial(int **mat, int N, int **road, int M, int **arr, int start, int end, int *minimum, int *mincnt, int *secmin);

// вывод не тривиального пути arr-спец.массив, mini-номер цикла
void print_nt_way(int **mat, int N, int **arr, int mini, int start, int end, int nt);

// вывод тривиального пути arr-спец.массив, mincnt-номер убираемой дороги
void print_tr_way(int **mat, int **arr, int N, int **road, int start, int end, int mincnt, int tr);

// второе минимальное рассто€ние до
int second_min(int **mat, int N, int start, int end, int **road, int M);

#endif// _GRAPH_2D_MIN_WAY_H