#include "good_functions.h"
#include"second_min_way.h"
#include <stdio.h>
// ���� ���������� ������� � �����
void input_N_M(int *N, int *M)
{
	printf("\n Input quantity of cities: ");
	input_pos_int(N);// N - ���������� �������(� ������)
	do
	{
		printf("\n Input quantity of roads: ");
		input_pos_int(M);
		if(*M>(*N)*(*N))
		{
			Err(3);
			continue;
		}
	}while(*M>(*N)*(*N));
	return;
}

// ���� ������ (i, j, k) � ������� ����������
void input_road(int *i, int *j, int *k, int **mat, int N)
{
	int check = 0;
	while(check==0)
	{
		if( (check=scanf("%d%d%d", i, j, k))<3 )
		{
			check = Err(1);// �������� ����
			fflush(stdin);
			continue;
		}
		if(*i<0 || *j<0 || *k<=0)
		{
			check = Err(2);// ������������� �����
			continue;
		}
		if(*i>=N || *j>=N)
		{
			check = Err(4);// ����� �� �������
			continue;
		}	
		if(mat[*j][*i]!=0)
		{
			check = Err(5);// ���� ����������������
			continue;
		}
	}
	return;
}

// ���� ����� (i, j, k) � �������
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

// ���� ������ ������������� ������
int input_item(int *item, int N)
{
	while(1)
	{
		input_int(item);
		if( *item>N || *item<0 )
			Err(4);
		else
			return *item;
	}
	printf("How u can leave the hospital?");
	return -1;// ���� ������ �������!
}

// ���� ���������� � ��������� ������
void input_start_end(int *start, int *end, int N)
{
	printf("\nInput start position: ");
	input_item(start, N);
	printf("\nInput end position: ");
	input_item(end, N);
}

// ����� ���������� ����� ��������
int sum_roads(int **mat, int N)
{
	int sum = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
				sum += mat[i][j];
	return sum;
}

// ��� � ��������� ��������, ����� 0 � ������ ����������
int deixtra_step(int **mat, int **arr, int N, int *flag, int max)
{
	int mini = N+1, min = max, temp;
	// ���� ��� �� ������������� �����, ���
	// ����� ���� �� ���� ������ ����������� (�� �������������)
	for(int i=0; i<N; i++)
		if(!arr[1][i] && arr[0][i]<min)
			min = arr[0][(mini = i)];
	// �� ����������� - �����
	if(mini == N+1)
		return 0;
	// ������������� ������ �� ���������� ������
	for(int i=0; i<N; i++)
		if(mat[mini][i])
			if((temp = min + mat[mini][i]) < arr[0][i])
			{
				arr[0][i] = temp;
				arr[2][i] = mini;
			}
	if(*flag)
	{
		arr[0][mini] = max;
		*flag=0;
		arr[2][mini] = -1;
	}
	else
		arr[1][mini] = 1; // ����� �������
	return 1;
}

// �������� �������� ��� ������������� ����.
// ���������� ������: way[i] =  �����, �������������� way[i]
// trivial = 1, ���� ���� ����� ����������� ���� � ��� �� �����
void deixtra_min(int **mat, int **arr, int N, int start, int trivial)
{
	// ������������ ����� ���� �� ����� ��������� ������� ����� ���� �����. �����-������������
	int	max = 2*sum_roads(mat, N)+1, flag = trivial;
	// ���������� �� ������� ������ ����������� � �� ���� ����� �� �������
	for(int i=0; i<N; i++)
		arr[(arr[1][i]=0)][i] = max;
	for(int i=0; i<N; i++)
		arr[2][i]=-1;
	arr[0][(arr[2][start]=start)] = 0;
	while(deixtra_step(mat, arr, N, &flag, max))
		;// ��� �����
	return;
}

// ���������� ������ ����
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

// ���������� ����������� ����� ������������� �����
int not_trivial(int **mat, int N, int **arr, int *mini)
{
	int min = 2*sum_roads(mat, N)+1, l, flag = 0;
	for(int i=0; i<N; i++)
	{
		deixtra_min(mat, arr, N, i, 1);
		if(arr[2][i]==-1)
			continue;
		l = lenght_way(mat, N, arr[2], i, i);
		if(l<min&&l!=0)
		{
			min = l;
			*mini = i;
			flag = 1;
		}
	}
	if(flag)
		return min;
	else
		return 0;
}

// ���������� ������������ ����
int trivial(int **mat, int N, int **road, int M, int **arr, int start, int end, int *minimum, int *mincnt, int *secmin)
{
	int tempmin;
	*minimum = lenght_way(mat, N, arr[2], start, end);
	for(int cnt=0; cnt<M; cnt++)
	{// �������� ������� ������
		mat[road[cnt][0]][road[cnt][1]] = 0;
		// ������� ��� ����
		deixtra_min(mat, arr, N, start, 0);
		if(arr[2][end]!=-1)
		{// ���� ����� ���� ������ �������� � ������ ������� ��������
			tempmin = lenght_way(mat, N, arr[2], start, end);
			if(tempmin>(*minimum) && tempmin<(*secmin))
			{
				*secmin = tempmin;//������ ������ �������
				*mincnt = cnt;// ���������� ���
			}
		}// ���������� ������
		mat[road[cnt][0]][road[cnt][1]] = road[cnt][2];
	}
	if(*mincnt>-1)
		return *secmin;
	return 0;
}

// ����� �� ������������ ����
void print_nt_way(int **mat, int N, int **arr, int mini, int start, int end, int nt)
{
	deixtra_min(mat, arr, N, start, 0);
	for(int k=end; k!=mini;k=arr[2][k])
		printf(" %d", k);
	deixtra_min(mat, arr, N, mini, 1);
	for(int k=mini; ;)
	{
		printf(" %d", k);
		k=arr[2][k];
		if(k==mini)
			break;
	}
	deixtra_min(mat, arr, N, start, 0);
	for(int k=mini; ;)
	{
		printf(" %d", k);
		k=arr[2][k];
		if(k==start)
			break;
	}
	printf("\n\nlenght = %d\n", nt);
}

// ����� ������������ ����
void print_tr_way(int **mat, int **arr, int N, int **road, int start, int end, int mincnt, int tr)
{
	printf("\n %d", end);
	mat[road[mincnt][0]][road[mincnt][1]]=0;
	deixtra_min(mat, arr, N, start, 0);
	for(int k=end; k!=start; k=arr[2][k])
		printf(" %d", arr[2][k]);
	printf("\n\nLenght = %d\n", tr);
	mat[road[mincnt][0]][road[mincnt][1]]=road[mincnt][2];
}

// ������ ����������� ���������� ��
int second_min(int **mat, int N, int start, int end, int **road, int M)
{
	int **arr = mem2arr2(&arr, 3, 2*N+1), minimum=-1, secmin=2*sum_roads(mat, N)+1, tr=0, mincnt=-1, nt=0, mini;
	// arr[0] - ������ ����������� ���������� �� ������ i
	// arr[1] - ������ ���������� ������� (0 - �� �������)
	// arr[2] - ������ ������� �������, �������������� i
	if(!arr)
		return 0;
	deixtra_min(mat, arr, N, start, 0);
	if(arr[2][end]==-1)
		return Err(404);
	else
	{
		tr = trivial(mat, N, road, M, arr, start, end, &minimum, &mincnt, &secmin);
		nt = not_trivial(mat, N, arr, &mini);
		if(tr)
			if(nt)
				if(nt>tr)
						print_nt_way(mat, N, arr, mini, start, end, nt+minimum);
				else
					print_tr_way(mat, arr, N, road, start, end, mincnt, tr);
			else
				print_tr_way(mat, arr, N, road, start, end, mincnt, tr);
		else
			if(nt)
				print_nt_way(mat, N, arr, mini, start, end, nt+minimum);
			else
				Err(404);
	}
	free_arr2(&arr, 3);
	return 0;
}