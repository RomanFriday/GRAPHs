#include "functions_with_queue.h"
#include "utilits.h"
#include <stdlib.h>
// создание элемента очереди
q_elem* create_element(char c)
{
	q_elem *New;
	if( !(New = (q_elem*)malloc(sizeof(q_elem))) )
		return (q_elem*)Err(0);
	New->c = c;
	New->next = NULL;
	return New;
}

// добавление в очередь
int Q_push(Q *Queue, q_elem *element)
{
	if(!Queue || !element)
		return 0;
	if(Queue->quantity++==0)
		Queue->head = Queue->tail = element;
	else
	{
		element->next = Queue->head;
		Queue->head = element;
	}
	return 1;
}

// удаление из очереди (с освобождением памяти)
q_elem Q_pop(Q *Queue)
{
	q_elem element={0,0}, *pointer = NULL;
	if(!Queue)
		return element;
	if(!Queue->head || !Queue->quantity)
		return element;
	element = *(Queue->tail);
	pointer = Queue->tail;
	if(--Queue->quantity==0)// очередь пуста
	{
		free(pointer);
		Queue->head = Queue->tail = NULL;
	}
	else// есть хотя бы 1 элемент
	{
		// перемещаем указатель на предпоследний
		for(pointer = Queue->head; pointer->next && pointer->next!=Queue->tail;)
			pointer = pointer->next;
		Queue->tail = pointer;// обновляем конец
		element = *pointer;// обновляем возвращаемое значение
		free(pointer->next);
		Queue->tail->next = NULL;
	}
	return element;
}

// удаление всех элементов из очереди
void Q_clear(Q *Queue)
{
	if(!Queue->head)
		return;
	q_elem *cur = Queue->head;// запоминаем текущий
	Queue->head = Queue->head->next;// изменяем начало
	Q_clear(Queue); // очищаем остальные элементы
	free(cur);
	Queue->head = Queue->tail = NULL;// указываем начало нулём
	Queue->quantity = 0;
}
