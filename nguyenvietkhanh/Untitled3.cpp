#include <stdio.h>
struct HocSinh {
    int MaSV;
    char HoTen[20];
    float DiemMon1, DiemMon2, DiemTB;
};
struct Node {
    HocSinh info;
    Node *link;
};
struct List {
    Node *first;
    Node *last;
};
List L;
Node *p;
void initListLIFO(List &L) {
	L.first = L.last = NULL;
    int n;
    printf("Nhap so hoc sinh n = ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
    printf("Nhap hoc sinh thu %d:\n", i);
    p = new Node;
    printf("+ Ma hoc sinh: ");
    scanf("%d", &p->info.MaSV);
    fflush(stdin);
    printf("+ Ho va ten: ");
    gets(p->info.HoTen);
    printf("+ Diem mon 1: ");
    scanf("%f", &p->info.DiemMon1);
    printf("+ Diem mon 2: ");
    scanf("%f", &p->info.DiemMon2);
    p->info.DiemTB = (p->info.DiemMon1 + p->info.DiemMon2)/2;
    
    if (L.last == NULL)
        L.last = p;
    p->link = L.first;
    L.first = p;
 }
}
void printList(List L) {
    if (L.first == NULL && L.last == NULL)
        printf("Danh sach rong!");
    else
 		for (p = L.first; p != NULL; p = p->link)
 			printf("\n%d%20s\t%5.2f\t%5.2f\t%5.2f", p->info.MaSV,
 			p->info.HoTen, p->info.DiemMon1,
 			p->info.DiemMon2, p->info.DiemTB);
}
void deleteLast(List &L) {
    if (L.first == NULL && L.last == NULL)
 		return;
    p = L.last;
    if(L.first == L.last) {
    L.first = L.last = NULL;
    } else {
 		Node *q = L.first;
 		for(; q->link != L.last; q = q->link);
 		q->link = NULL;
 		L.last = q;
 }
    delete p;
}

int main()
{
    initListLIFO(L);
    printf("Danh sach LIFO duoc khoi tao la:");
    printList(L);
    deleteLast(L);
    printf("\nDanh sach sau khi xoa phan tu cuoi cung la:");
    printList(L);
}
