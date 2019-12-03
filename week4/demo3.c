#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int fac(int n);
void swap(int *p, int *q);
void permutation(int a[],int m,int n, int *p);
void MagicMatrix(int a[],int m,int n, int *p);
int main(void){
	int n;
	//printf("enter n:\n");
	//scanf("%d",&n);
	//n = n*n;
	int *a,p;
	for(int i =0;i<n;i++){
		a[i]=i+1;
	}
	MagicMatrix(a,0,9,&p);
	//permutation(a,0,n,&p);
	//printf("%d!=%d\nthe number of permutation is:%d\n",n,fac(n),p);
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
void MagicMatrix(int a[],int m,int n, int *p){
	int sq = pow(n,0.5);
	if(m==n){
		int flag=1;
		int sum[8]={0};
		for(int y = 0; y < sq; y++){
			sum[0]+=a[y*(sq+1)];
			sum[1]+=a[(y+1)*(sq-1)];
			sum[2]+=a[y];
			sum[3]+=a[sq+y];
			sum[4]+=a[2*sq+y];
			sum[5]+=a[y*sq];
			sum[6]+=a[y*sq+1];
			sum[7]+=a[y*sq+2];
		}
		for(int j = 0; j<7;j++){
			if(sum[j]!=sum[j+1]) {
				flag=0;
				break;
			}
		}
		if(flag==1){
			(*p)++;
			printf("The %4d-th result is:\n",*p);
			for(int y = 0; y < pow(n,0.5); y++){
				for(int j = 0; j< pow(n,0.5);j++){
					printf("%4d",a[3*y+j]);
				}
				printf("\n");
			}
		}
		//printf("\n");

	}
	else{
		for(int i = m; i<n; i++){
			swap(a+i,a+m);
			permutation(a,m+1,n,p);
			swap(a+i,a+m);
		}
	}
}
/*void permutation(int a[],int m,int n, int *p){
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
*/