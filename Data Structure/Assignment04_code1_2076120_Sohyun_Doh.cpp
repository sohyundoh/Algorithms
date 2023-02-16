#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DStackNode {
	element item;
	struct DStackNode* rlink;
	struct DStackNode* llink;
} DStackNode;

typedef struct {
	DStackNode* top;
} DLinkedStackType;

void init(DLinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(DLinkedStackType* s)
{
	return (s->top == NULL);
}

void push(DLinkedStackType* s, element item)
{
	DStackNode* temp = (DStackNode*)malloc(sizeof(DStackNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else {
		temp->item = item;
		temp->rlink = s->top;
		temp->llink = NULL;
		if (!is_empty(s)) s->top->llink = temp;
		s->top = temp;
	}
}

element pop(DLinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
		DStackNode* temp = s->top;
		int item = temp->item;
		if (!(s->top->rlink == NULL)) {
			s->top = s->top->rlink;
			s->top->llink = NULL;
		}
		free(temp);
		return item;
	}
}

element peek(DLinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	DLinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}