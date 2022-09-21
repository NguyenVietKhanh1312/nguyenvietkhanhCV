#include <stdio.h>

struct Node {
	int data;
	Node *prev;
	Node *next;
};

struct List {
	Node *first;
	Node*last;
};

List L;
Node *p;

void initList(List &L) {
	L.first = L.last = NULL;
}

Node *getNode(int x) {
	p = new Node;
	p->data = x;
	p->prev = p->next = NULL;
	return p;
}

void addFirst(List &L, Node *p) {
	if (L.first == NULL && L.last == NULL)
		L.first = L.last = p;
	else{
		p->next = L.first;
		L.first->prev = p;
		L.first = p;
	}
}

void addLast(List &L, Node *p) { 
	if(L.first == NULL && L.last == NULL)
		L.first = L.last = p;
	else {p->prev = L.last;
		L.last->next = p;
		L.last = p;
	}
}	

void deleteFirst(List &L) {
	if (L.first == NULL && L.last == NULL)
		return;
	p = L.first;
	if(L.first == L.last)
		L.first = L.last = NULL;
	else {
		L.first = L.first->next;
		L.first->prev = NULL;
	}
	
	delete p;
}

void deleteLast(List&L) {
	if (L.first == NULL && L.last == NULL)
		return;
	p = L.first;
	if (L.first == L.last)
		L.first = L.last = NULL;
	else {
		L.last = L.last->prev;
		L.last->next = NULL;
	}
	
	delete p;
}

void printList1(List L) {
	if (L.first == NULL && L.last == NULL)
		printf("Danh sach rong!");
	else {
		p = L.first;
	for (; p != NULL; p = p->next)
		printf("%d ", p->data);
	}
}

void printList2(List L) {
	if (L.first == NULL && L.last == NULL)
		printf("Danh sach rong!");
	else {
		p = L.last;
		for(; p != NULL; p = p->prev)
			printf("%d ", p->data);
	}
}

int main() 
{
	initList(L);
	for(int i = 1; i <= 5; i++) { 
		addLast(L, getNode(i));
	}
	
	printf("Danh sach tu fist: ");
	printList1(L);
//  printf("\nDanh sach tu last: ");
//  printList2(L);
	deleteFirst(L);\
	printf("\nDanh sach sau khi xoa phan tu dau tien: ");
	printList1(L);
	
	deleteLast(L);
	printf("\nDanh sach sau khi xoa phan tu cuoi cung: ");
	printList1(L);
}
