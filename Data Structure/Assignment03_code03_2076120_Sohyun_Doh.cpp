#include <stdio.h>
#include <stdlib.h>

//code for assginment03 #3

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
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
//insert node in the given position of the list
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		if (p == NULL) {
			printf("The preceding node cannot be NULL.\n");
			exit(1);
		}
		else {
			new_node->link = p->link;
			p->link = new_node;
		}
	}
}
//insert node in the fisrt of list
void insert_first(ListNode** phead, ListNode* new_node)
{
	if (*phead == NULL) { //if the list is blank
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = *phead;
		*phead = new_node;
	}
}
//insert node in the last of list
void insert_last(ListNode** phead, ListNode* new_node)
{
	if (*phead == NULL) { //if the list is blank
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = NULL;
		struct ListNode* last = *phead;
		while (last->link != NULL)
			last = last->link;
		last->link = new_node;
	}
}
//get the node of specific position
ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}
int is_empty(ListType* list)
{
	if (list->head == NULL) return 1;
	else return 0;
}
//given code in the slide
void add(ListType* list, int position, element data) {
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}
//my code, using the insert_first fuction to implement add_first
void add_first(ListType* list, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL) perror("Memory allocation error");
	p->data = value;
	insert_first(&(list->head), p);
	list->length++;
}
//using the insert_last fuction to implement add_last
void add_last(ListType* list, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL) perror("Memory allocation error");
	p->data = value;
	insert_last(&(list->head), p);
	list->length++;
}
void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (*phead == NULL) {
		printf("The list is blank.\n");
	}
	else {
		if (p == NULL)
			printf("The preceding node cannot be NULL.\n");
		else {
			p->link = removed->link;
			free(removed);
		}
	}
}
//just changing head pointer and free removed node for remove_first
void remove_first(ListNode** phead, ListNode* removed)
{
	if (*phead == NULL) {
		printf("The list is blank.\n");
	}
	else {
		*phead = (*phead)->link;
		free(removed);
	}
}

void delete_Node(ListType* list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* p = get_node_at(list, pos - 1);
		ListNode* removed = get_node_at(list, pos);
		remove_node(&(list->head), p, removed);
		list->length--;
	}
}
//using the remove_first to implement this fuction
void delete_first(ListType* list) {
	if (!is_empty(list)) {
		ListNode* removed = get_node_at(list, 0);
		remove_first(&(list->head), removed);
		list->length--;
	}
}
//we have to remove the node which is in last node(position is (list->length -1))
//and we have to change the tail by preceding one
//also we have to make free removed node
void delete_last(ListType* list) {
	if (!is_empty(list)) {
		ListNode* removed = get_node_at(list, (list->length) - 1);
		list->tail = get_node_at(list, (list->length) - 2);
		list->length--;
		free(removed);
	}
}
// Return the data at the ¡®pos¡¯.
element get_entry(ListType* list, int pos)
{
	ListNode* p;
	if (pos >= list->length) exit(1);
	p = get_node_at(list, pos);
	return p->data;
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
int is_in_list(ListType* list, element item)
{
	ListNode* p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return false;
	else return true;
}
int main(void) {
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);

	delete_Node(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == true ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}