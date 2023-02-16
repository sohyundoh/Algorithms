#include <iostream>

using namespace std;

//implementing ListNode Struct
typedef struct ListNode {
	int data;
	ListNode* link;
} ListNode;
typedef struct {
	ListNode* head;
	ListNode* tail;
	int length;
} ListType;


void init(ListType* plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

//we have to implement inserting function because of initializing
void insert_last(ListNode** phead, ListNode* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = NULL;
		ListNode* last = *phead;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = new_node;
	}
}
//we have to implement adding function because of initializing
void add_last(ListType* list, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL) perror("Memory allocation error");
	p->data = value;
	insert_last(&(list->head), p);
	list->length++;
}
//implementing sorting fuction by recursion
ListNode* SortedMerge(ListNode* list1, ListNode* list2) {
	ListNode* result = NULL;
	if (list1 == NULL)
		return (list2);
	else if (list2 == NULL)
		return (list1);

	if (list1->data <= list2->data) {
		result = list1;
		result->link = SortedMerge(list1->link, list2);
	}
	else {
		result = list2;
		result->link = SortedMerge(list1, list2->link);
	}
	return (result);

	return list1;
}
void display_node(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

void display(ListType* list) {
	int i;
	ListNode* node = list->head;
	printf("(");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(")\n");
}
int main(void) {
	int a_value[7] = { 1,2,5,10,15,20,25 };
	int b_value[6] = { 3,7,8,15,18,30 };
	ListType list1, list2;
	init(&list1);
	init(&list2);
	for (int i = 0; i <= 6; i++) {
		add_last(&list1, a_value[i]);
	}
	for (int i = 0; i <= 5; i++) {
		add_last(&list2, b_value[i]);
	}
	display(&list1);
	display(&list2);
	display_node(SortedMerge((&list1)->head, (&list2)->head));
}