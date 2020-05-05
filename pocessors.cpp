#include <conio.h>
#include "pocessors.h"
#include "utilits.h"

typedef struct my_struct1
{
	char c;
	struct my_struct1 *next;
} q;
typedef struct my_struct2
{
	int quantity;
	q *head, *penul;
} Q;

int preparation()
{

	return 1;
}

int process()
{

	return 1;
}