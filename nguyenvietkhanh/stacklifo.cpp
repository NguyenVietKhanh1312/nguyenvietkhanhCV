#include <stdio.h>

struct Student {
	int MaSV;
	char Hoten[20];
	float Diem;
};

struct Element {
	Student value;
	Element *link;
};

struct Stack {
	Element *top;
};

Stack S;

void initStack(Stack &S) {
	S.top = NULL;
}
	
bool isEmpty(Stack S) {
	return S.top == NULL? true : false;
}

void push(Stack &S, Student value) {
	Element *p = new Element;
	p->value = value;
	p->link = S.top;
	S.top = p;
}

Student pop(Stack &S) {
	Element *p;
	p = S.top;
	S.top = S.top->link;
	return p->value;
}

int main()
{
	initStack(S);
	Student student;
	char ch;
	
	do {
		printf("+ Ma sinh vien: ");
		scanf("%d", &student.MaSV);
		fflush(stdin);
		printf("+ Ho va ten: ");
		gets(student.Hoten);
		printf("+ Diem: ");
		scanf("%f", &student.Diem);
		push(S, student);
		fflush(stdin);
		printf("Ban co tiep tuc khong (c/k)? ");
		ch = getchar();
	} while (ch != 'k');
	printf("Ket qua lay ra tu stack:\n");
		while (!isEmpty(S)) {
		student = pop(S);
		printf("%5d%20s%10.2f\n", student.MaSV, student.Hoten, student.Diem);
	}
}
