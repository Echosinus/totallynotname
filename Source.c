#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20
struct queue //очередь
{
char que[N];
int quefirst, quelast;
};
void inque(struct queue* q) //инициализация очереди
{
	q->quefirst = q;
	q->quelast = 0;
	return;
}
void insert(struct queue* q, char x) //добавление в очередь
{
	if (q->quelast < N - 1)
	{
		q->quelast++;
		q->que[q->quelast] = x;
	}
	else
		printf("queue is empty\n");
	return;
}
int isempty(struct queue* q) //проверка пуста ли очередь
{
	if (q->quelast < q->quefirst)
		return 1;
	else  return 0;
}
void print(struct queue* q) //вывод элементов
{
	int h;
	if (!isempty(q) == 1) 
	{
		printf("queue is empty\n");
		return;
	}
	for (h = q->quefirst; h <= q->quelast; h++)
		printf("%c ", q->que[h]);
	return;
}
int removex(struct queue* q) {
	int x;
	if (isempty(q) == 0) {
		printf("queue is empty\n");
		return(0);
	}
	x = q->que[q->quefirst];
	q->quefirst++;
	return x;
}
/*int removex(struct queue* q) {
	int x, h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	x = q->que[q->quefirst];
	for (h = q->quefirst; h < q->quelast; h++) {
		q->que[h] = q->que[h + 1];
	}
	q->quelast--;
	return x;
}*/
void main()
{
	/* int M;
	printf("enetry number of elements\n");
	scanf("%d", &M);
	*/
	struct queue* q;
	char a;
	q = malloc(sizeof(struct queue));
	inque(q);
	print(q);
	for (int i = 0; i < N; i++)
	{
		printf("enetry element\n");
		scanf("%c", &a);
		insert(q, a);
	}
	print(q);
	while (q->quefirst !=NULL)
	{
		a = removex(q);
		printf("delet element %d\n", a);
		print(q);
	}
	system("pause");
}