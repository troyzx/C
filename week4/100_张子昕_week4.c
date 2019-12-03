#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define S(a,b) a*b
#define STAR '*'
#define C "%c"

void transpose(int a[3][3]);
void lenmax(char c[], int*len, int*index);
float le(int n,float x);
void trans(int a, char* c);
int main(){
	
	printf("4]\n");
	{
		static int a[3][3]={};
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				a[i][j]=rand()%100;
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		transpose(a);
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
	}
	
	printf("10]\n");
	{
		int i=0;
		static int len=0,index=0;
		static char c[]={};
		gets(c);
		lenmax(c,&len,&index);
		printf("The longest word is:\n");
		while(i<=len){
			printf("%c",c[index]);
			i++;
			index++;
		}
		printf("\n");
	}

	printf("13]\n");	
	{
		float result = le(4,3.0);
		printf("%f",result);
	}

	printf("17\n");
	{
		int a;
		printf("enter a number:\n");
		scanf("%d",&a);
		getchar();
		char w[]={};
		trans(a, w);
		puts(w);
	}

	printf("SelfLearning\n");
	{
		printf(C,STAR);
		printf("\n");

		int a = 3, b = 4;
		printf("a=%d\nb=%d\nS=%d\n",a,b,S(a,b));

	}
}
void transpose(int a[3][3]){
	int i,j,t;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j>i){
				t = a[j][i];
				a[j][i] = a[i][j];
				a[i][j] = t;
			}
		}
	}
}
void lenmax(char c[], int*len, int*index){
	int i,tlen=0;
	for(i=0;c[i]!='\0';i++){
		if(((c[i]>64&&c[i]<91)||(c[i]>96&&c[i]<123))&&c[i+1]!='\0'){
			tlen++;
		}
		else{
			if(tlen>=(*len)){
				*len = tlen;
				(*index) = i - tlen;
			}
			tlen = 0;
		} 
			
	}
}
float le(int n,float x){
	if(n==0) return 0;
	if(n==1) return x;
	return(2*n-1*x-le(n-1,x)-(n-1)*le(n-2,x)*n);
}
void trans(int a, char* x){
	int n = a%10;
	char temp[] = {n+'0'};
	//printf("%c",temp[0]);
	if(a/10==0) strcat(x,temp);
	else {
		trans((a-n)/10, x);
		strcat(x,temp);
		//printf("*");
	}
}