#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int fac(int n);
void swap(int *p, int *q);
void permutation(int a[],int m,int n, int *p);
int main(void){
	int n;
	printf("enter n:\n");
	scanf("%d",&n);
	int *a,p;
	for(int i =0;i<n;i++){
		a[i]=i+1;
	}
	permutation(a,0,n,&p);
	printf("%d!=%d\nthe number of permutation is:%d\n",n,fac(n),p);
	//printf("%d\na=%d\nb=%d\n",n,a,b);
}
int fac(int n){
	if(n==1) return 1;
	return n*fac(n-1);
}
void swap(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}
void permutation(int a[],int m,int n, int *p){
	if(m==n){
		for(int i = 0; i < n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
		(*p)++;

	}
	else{
		for(int i = m; i<n; i++){
			swap(a+i,a+m);
			permutation(a,m+1,n,p);
			swap(a+i,a+m);
		}
	}
}