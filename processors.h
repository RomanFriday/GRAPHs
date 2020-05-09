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




// шкала выполнения задачи
int complited(int time_left, int lead_time);





// процесс работы
int process();

#endif // _PROCESSORS_H
