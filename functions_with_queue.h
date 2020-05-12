#ifndef _FUNCTIONS_WITH_QUEUE_H
#define _FUNCTIONS_WITH_QUEUE_H


typedef struct my_struct1
{
	char c;
	struct my_struct1 *next;
} q_elem;
typedef struct my_struct2
{
	int quantity;
	q_elem *head, *tail;
} Q;

// создание элемента очереди
q_elem* create_element(char c);

// добавление в очередь
int Q_push(Q *Queue, q_elem *element);

// удаление из очереди (с освобождением памяти)
q_elem Q_pop(Q *Queue);

// удаление всех элементов из очереди
void Q_clear(Q *Queue);

#endif //_FUNCTIONS_WITH_QUEUE_H