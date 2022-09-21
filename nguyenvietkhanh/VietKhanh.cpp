#include <stdio.h>

int n, k;

void xuat(int a[]){
	for(int i = 1; i <= k; i++){
		printf("%d", a[i]);
	}
	printf("\n");
}

void to_hop(int a[], int i){
	for(int j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if(i == k)
			xuat(a);
		else
			to_hop(a, i + 1);
	}	
}

int main(){
	int a[100],i;
	printf("Nhap n phan tu: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);

	to_hop(a, 1);
	return 0;
}
