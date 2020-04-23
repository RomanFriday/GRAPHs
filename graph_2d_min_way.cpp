#include "utilits.h"
#include"graph_2d_min_way.h"
#include <stdio.h>
#include <malloc.h>
// ввод количества городов и дорог
void input_N_M(int *N, int *M)
{
	printf("\n Input quantity of cities: ");
	input_pos_int(N);// N - количество городов(в задаче)
	do
	{
		printf("\n Input quantity of roads: ");
		input_pos_int(M);
		if(*M>(*N)*(*N-1)/2 + (*N))// количество дорог не превосходит кол. пар городов + кол. городов (петель)
		{
			Err(3);
			continue;
		}
	}while(*M>(*N)*(*N-1)/2+(*N));
	return;
}

// ввод дороги (i, j, k) с верными значениями
void input_road(int *i, int *j, int *k, int **mat, int N)
{
	int check = 0;
	while(check==0)
	{
		if( (check=scanf("%d%d%d", i, j, k))<3 )
		{
			check = Err(1);// неверный ввод
			fflush(stdin);
			continue;
		}
		if(*i<0 || *j<0 || *k<=0)
		{
			check = Err(2);// отрицательное число
			continue;
		}
		if(*i>=N || *j>=N)
		{
			check = Err(4);// выход за пределы
			continue;
		}	
		if(mat[*j][*i]!=0)
		{
			check = Err(5);// граф однонаправленный
			continue;
		}
	}
	return;
}

// ввод дорог (i, j, k) в матрицу
void input_roads(int **mat, int N, int **road, int M)
{
	printf("\nNumer of cities started by 0\nInput %d roads like: i j k\n", M);
	int i, j, k;
	for(int cnt=0; cnt<M; cnt++)
	{
		input_road(&i, &j, &k, mat, N);
		road[cnt][0] = i;
		road[cnt][1] = j;
		road[cnt][2] = mat[i][j] = k;
	}
	return;
}

// ввод номера существующего города
int input_item(int *item, int N)
{
	while(1)
	{
		input_int(item);
		if( *item>=N || *item<0 )
			Err(4);
		else
			return *item;
	}
	printf("How u can leave the hospital?");
	return -1;// сюда нельзя попасть!
}

// ввод начального и конечного пункта
void input_start_end(int *start, int *end, int N)
{
	printf("\nInput start position: ");
	input_item(start, N);
	printf("\nInput end position: ");
	input_item(end, N);
}

// сумма расстояний между городами
int sum_roads(int **mat, int N)
{
	int sum = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
				sum += mat[i][j];
	return sum;
}

// шаг в алгоритме Дейкстры, вернёт 0 в случае завершения
int deixtra_step(int **mat, int **arr, int N, int *flag, int max)
{
	int mini = N+1, min = max, temp;
	// ищем ещё не рассмотренный город, что
	// длина пути до него меньше минимальной (не рассмотренной)
	for(int i=0; i<N; i++)
		if(!arr[1][i] && arr[0][i]<min)// условие
			min = arr[0][(mini = i)];// запоминаем город и его значение
	// всё рассмотрели - выход
	if(mini == N+1)
		return 0;
	// рассматриваем дороги от найденного города
	for(int i=0; i<N; i++)
		if(mat[mini][i])// путь от города mini до i существует
			if((temp = min + mat[mini][i]) < arr[0][i] || !arr[0][i])// новое значение меньше старого
			{
				arr[0][i] = temp;// новое значение минимального пути до города i
				arr[2][i] = mini;// mini - предыдущий город для i
			}
	// если надо найти минимальный путь до стартовой вершины - обозначаем её как не рассмотренную
	if(*flag)
	{
		if(!arr[0][mini])// если нет петли
		{
			arr[0][mini] = max;// значение минимального пути не найдено
			arr[2][mini] = -1;// предыдущий город не найден
		}
		*flag=0;// стартовая вершина подлежит рассмотру
	}
	else
		arr[1][mini] = 1; // город посещён
	return 1;
}

// алгоритм Дейкстры для максимального пути.
// Возвращает массив: way[i] =  город, предшествующий way[i]
// trivial = 1, если надо найти минимальный путь в тот же город
void deixtra_min(int **mat, int **arr, int N, int start, int trivial)
{
	// максимальная длина пути не может превышать двойной суммы всех путей. Иначе-зацикливание
	int	max = 2*sum_roads(mat, N)+1, flag = trivial;
	// расстояния до каждого города максимальны и ни один город не посещён
	for(int i=0; i<N; i++)
	{
		arr[1][i]=0;// город i не посещён
		arr[0][i] = max;// минимальное расстояние не найдено
	}
	for(int i=0; i<N; i++)
		arr[2][i]=-1;// предыдущий город не определён
	//arr[2][start] = start; предыдущий город для стартового - он сам
	arr[0][start] = 0;// минимальный путь до стартового горада принимаем за 0
	while(deixtra_step(mat, arr, N, &flag, max))// выполняем шаг алгоритма
		;// шаг цикла
	return;
}

// нахождение длинны пути
int lenght_way(int **mat, int N, int *way, int start, int end)
{
	int l=0;
	for(int i=end;;)
	{
		l += mat[way[i]][i];
		i=way[i];
		if(i==start)
			break;
	}
	return l;
}

// нахождение минимальной длины нетривиальных путей
int not_trivial(int **mat, int N, int **arr, int *mini, int start, int end)
{
	int min = 2*sum_roads(mat, N)+1, l=0, flag = 0;
	for(int i=0; i<N; i++, l=0)
	{
		deixtra_min(mat, arr, N, start, 1);
		if(arr[2][i]==-1)// путь до города i не найден
			continue;
		if(i != start)
			l += arr[0][i];// вычисляем длину пути до i города
		deixtra_min(mat, arr, N, i, 1);
		if(arr[2][i]==-1 || arr[2][end]==-1)// цикла в графе с i нет или до города end нельзя добраться
			continue;// данный путь не рассматриваем
		l += arr[0][i];
		if(i!=end)
			l += arr[0][end];
		if(l<min&&l!=0)// если длина минимальна
		{
			min = l;
			*mini = i;
			flag = 1;
		}
	}
	if(flag)// если существует цикл
		return min;
	else
		return 0;
}

// нахождение тривиального пути
int trivial(int **mat, int N, int **road, int M, int **arr, int start, int end, int *minimum, int *mincnt, int *secmin)
{
	int tempmin;
	*minimum = lenght_way(mat, N, arr[2], start, end);// значение минимального пути
	for(int cnt=0; cnt<M; cnt++)
	{	// временно удаляем дорогу
		mat[road[cnt][0]][road[cnt][1]] = 0;
		// находим мин путь
		deixtra_min(mat, arr, N, start, 1);
		if(arr[2][end]!=-1)// если новый путь существует
		{// если новый путь больше меньшего и меньше второго минимума
			tempmin = lenght_way(mat, N, arr[2], start, end);
			if(tempmin>(*minimum) && tempmin<(*secmin))
			{
				*secmin = tempmin;//меняем второй минимум
				*mincnt = cnt;// запоминаем шаг
			}
		}
		// возвращаем дорогу
		mat[road[cnt][0]][road[cnt][1]] = road[cnt][2];
	}
	if(*mincnt>-1)// новый путь найден
		return *secmin;
	return 0;
}

// вывод не тривиального пути
void print_nt_way(int **mat, int N, int **arr, int mini, int start, int end, int nt, int *way)
{
	int k,// номер города
		n=0;// количество городов в пути
	if(end!=mini)// вывод до цикла(в графе)
	{
		deixtra_min(mat, arr, N, mini, 1);
		for(k=end; k!=mini;k=arr[2][k])//номер предыдущего города
			way[n++]=k;                                                          //printf(" %d", k);
	}
	//вывод при цикле(в графе)
	deixtra_min(mat, arr, N, mini, 1);
	for(k=mini; ;)
	{
		way[n++]=k;                                                              //printf(" %d", k);
		k=arr[2][k];// номер предыдущего гороода
		if(k==mini)
			break;
	}
	if(k!=start)// вывод после цикла(в графе), если надо
	{
		deixtra_min(mat, arr, N, start, 1);
		for(k=mini; ;)
		{
			way[n++]=k;                                                          // printf(" %d", k);
			k=arr[2][k];
			if(k==start)
				break;
		}
	}
	way[n++]=start;
	reverse(way, n);
	print_arr_1d(way, n);
	printf("\n\nlenght = %d\n", nt);
}

// вывод тривиального пути
void print_tr_way(int **mat, int **arr, int N, int **road, int start, int end, int mincnt, int tr, int *way)
{
	int n=0;// количество городов в пути
	way[n++]=end;                                                                 // printf("\n %d", end);
	mat[road[mincnt][0]][road[mincnt][1]]=0;
	deixtra_min(mat, arr, N, start, 1);
	for(int k=end; k!=start; k=arr[2][k])// номер предыдущего города
		way[n++]=arr[2][k];                                                       // printf(" %d", arr[2][k]);
	reverse(way, n);
	print_arr_1d(way, n);
	printf("\n\nLenght = %d\n", tr);
	mat[road[mincnt][0]][road[mincnt][1]]=road[mincnt][2];
}

// второе минимальное расстояние до
int second_min(int **mat, int N, int start, int end, int **road, int M)
{
	int **arr,
		minimum=-1,
		secmin=2*sum_roads(mat, N)+1,
		tr=0, mincnt=-1,
		nt=0, mini,
		*way;
	// arr[0] - массив минимальных расстояний до города i
	// arr[1] - массив посещённых городов (0 - не посещён)
	// arr[2] - массив номеров городов, предшествующих i
	if(!mem2arr_1d(&way, 2*N+1))
		return 0;
	if(!mem2arr_2d(&arr, 3, 2*N+1))
	{
		free(way);
		return 0;
	}
	deixtra_min(mat, arr, N, start, 1);// находим минимальный путь от start до end
	if(arr[2][end]==-1)// минимального пути не существует
		return Err(404);
	else
	{
		tr = trivial(mat, N, road, M, arr, start, end, &minimum, &mincnt, &secmin);
		nt = not_trivial(mat, N, arr, &mini, start, end);
		if(!(tr+nt))// второго по длинне пути не существует
			Err(404);
		else// хотя бы 1 путь найден
			if(tr>0 && (!nt || tr<nt))// путь с удалением дороги меньше пути с циклом
				print_tr_way(mat, arr, N, road, start, end, mincnt, tr, way);
			else
				print_nt_way(mat, N, arr, mini, start, end, nt, way);
	}
	free_arr_2d(&arr, 3);
	return 0;
}