#include <stdio.h>

 struct Student {
 	int MaSV;
 	char HoTen[20];
	float Diem;
};

struct Element {
	Student value;
	Element *link;
};

struct Queue {
	Element *front;
	Element *rear;
};

Queue Q;

void InitQueue(Queue &Q) {
	Q.front = Q.rear = NULL;
}

bool IsEmpty(Queue Q) {
	return (Q.front == NULL) && (Q.rear == NULL)? true: false;
}

void EnQueue(Queue &Q, Student calue) {
	Element *element = new Element;
	element->value = value;
	element->link = NULL;
	if(IsEmpty(Q))
	Q.front = element;
	else
		Q.rear->link = element;
	Q.rear = element;
	
}

Student DeQueue(Queue &Q) {
	Element *element = Q.front;
	if(Q.front == Q.rear) {
		Q.front = Q.rear = NULL;
	} else {
		Q.front = Q.front->link;
	}
	return element->value;
}
int main()
{
	InitQueue(Q);
	Student sudent;
	char ch;
	
	do {
		printf("+ Ma sinh vien: ");
		scanf("%d", &student.MaSV);
		fflush(stdin);
		printf("+ Ho va ten: ");
		gets(student.HoTen);
		printf("+ Diem: ");
		scanf("%f", &student.Diem);
		EnQueue(Q,student);
		fflush(stdin);
		printf("Ban co tiep tuc khong (c/k)? ");
		ch=getchar();
		} while(ch! = 'k');
		printf("Ket qua lay ra tu Queue:\n");
		while(!IsEmpty(Q)) {
			student = DeQueue(Q);
			printf("%5d%20s%10.2f\n", student.MaSV,student.HoTen,student.Diem,
	}
}
			
		
	


