#include <stdio.h>
#include <math.h>
double g(double x);
int main(){
//Chpater 4
printf("Chapter 4\n");
	//8 
	printf("8]\n");
	{
		int grade;
		int flag;
		printf("enter your grade:\n");
		scanf("%d",&grade);
		flag = (grade >= 90)?1:(grade <= 89 && grade >= 80)?2:(grade <= 79 && grade >= 70)?3:(grade <= 69 && grade >= 60)?4:(grade <60 )?5:6;
		switch(flag){
			case 1:{
				printf("A\n");
				break;
			}
			case 2:{
				printf("B\n");
				break;
			}
			case 3:{
				printf("C\n");
				break;
			}
			case 4:{
				printf("D\n");
				break;
			}
			case 5:{
				printf("E\n");
				break;
			}
			case 6:{
				printf("error\n");
				break;
			}
		}
	}
	printf("\n");
	printf("10]\n");
	//10
	//(1)
	printf("(1)\n");
	{
		float I;
		float M;
		printf("enter I:\n");
		scanf("%f",&I);
		if(I<=100000){
			M = I*0.1;
		}
		else if(I<=200000){
			M = 10000+(I-100000)*0.075;
		}
		else if(I<=400000){
			M = 17500+(I-200000)*0.05;
		}
		else if(I<=600000){
			M = 27500+(I-400000)*0.03;
		}
		else if(I<=1000000){
			M = 30500+(I-600000)*0.015;
		}
		else{
			M = 36500+(I-100000)*0.01;
		}
		printf("%lf\n",M);
	}
	//(2)
	printf("(2)\n");
	{
		float I;
		float M;
		printf("enter I:\n");
		scanf("%f",&I);
		int flag = (I <= 100000)?1:(I <= 200000 && I > 100000)?2:(I <= 400000 && I > 200000)?3:(I <= 600000 && I > 400000)?4:(I <= 1000000 && I >600000)?5:(I > 1000000)?6:7;
		switch(flag){
			case 1:{
				M = I*0.1;
				break;
			}
			case 2:{
				M = 10000+(I-100000)*0.075;
				break;
			}
			case 3:{
				M = 17500+(I-200000)*0.05;
				break;
			}
			case 4:{
				M = 27500+(I-400000)*0.03;
				break;
			}
			case 5:{
				M = 30500+(I-600000)*0.015;
				break;
			}
			case 6:{
				M = 36500+(I-100000)*0.01;
				break;
			}
			case 7:{
				printf("error");
				break;
			}
		}
		printf("%lf\n",M);
	}
	printf("\n");

	//12
	printf("12]\n");
	{
		float x,y;
		int h;
		printf("enter(x,y):\n");
		scanf("%f,%f",&x,&y);
		if(pow((fabs(x)-2)*(fabs(x)-2)+(fabs(y)-2)*(fabs(y)-2),0.5)<=1){
			h = 10;
		}
		else h=0;
		printf("%d m\n",h);
		getchar();
	}
	printf("\n");

	//Chapter 5
	printf("Chapter 5\n");
	//4
	printf("4]\n");
	{
		int a=0,b=0,c=0,d=0;
		char s[100];
		gets(s);
		for(int i=0;s[i]!=0;i++){
			if((s[i]<=90&&s[i]>=65)||(s[i]>=97&&s[i]<=122)){
				a++;
				continue;
			}
			if(s[i]==32){
				b++;
				continue;
			}
			if(s[i]>=48&&s[i]<=57){
				c++;
				continue;
			}
			d++;
		}
		printf("character:%d\nspace:%d\nnumbers:%d\nothers:%d\n",a,b,c,d);
	}
	printf("\n");

	//6
	printf("6]\n");
	{
		unsigned long long int fac();
		unsigned long long int sum = 0;
		for(int i = 1;i<=20;i++){
			sum += fac(i);
		}
		printf("%llu\n", sum);
	}
	printf("\n");

	//8
	printf("8]\n");
	{
		int a,b,c;
		for(int i = 100;i<1000;i++){
			a = i/100;
			b = (i-100*a)/10;
			c = (i-100*a-10*b);
			if(pow(a,3)+pow(b,3)+pow(c,3)==i){
				printf("%d\n",i);
			}
		}
	}
	
	//10
	printf("10]\n");
	{
		float f();
		float sum = f(20);
		printf("%f\n",sum);
	}
	printf("\n");

	//12
	printf("12]\n");
	{
		int peach();
		int p=peach(10);
		printf("%d\n", p);
	}
	printf("\n");

	//14
	printf("14]\n");
	{
		double root(double x);
		double x = root(1.5);
		printf("%lf\n",x);
	}
	printf("\n");
	
	//16
	printf("16]\n");
	{
		for(int i = 1;i<=4;i++){
			for(int j = 0;j<4-i;j++){
				printf(" ");
			}
			for(int k = 1;k<=2*i-1;k++){
				printf("*");
			}
			for(int j = 0;j<4-i;j++){
				printf(" ");
			}
			printf("\n");
		}
		for(int i = 1;i<4;i++){
			for(int j = 0;j<i;j++){
				printf(" ");
			}
			for(int k = 0;k<(7-2*i);k++){
				printf("*");
			}
			for(int j = 0;j<i;j++){
				printf(" ");
			}
			printf("\n");
		}
	}
	printf("\n");

	//17
	printf("17]\n");
	{
		int A, B, C;
		for (A='X'; A<='Z'; A++){
			if(A!='X'){
				for (B='X'; B<='Z'; B++){
					if (A!=B){
						for(C='X'; C<='Z'; C++){
							if (C!='X' && C!='Z' && C!=B && C!=A){
								printf("A<-->%c\nB<-->%c\nC<-->%c\n",A,B,C);
							}
						}
					}
				}
			}
		}
	}
	printf("\n");


	return 0;
}
unsigned long long int fac(int n){
	if(n==1) 
		return 1;
	else 
		return n*fac(n-1);
	}

float f(int n){
	float f1 = 2;
	float f2 = 3;
	float g1 = 1;
	float g2 = 2;
	float f3,g3;
	for(int i=3;i<=n;i++){
		f3 = f1 + f2;
		g3 = g1 + g2;
		f1 = f2;
		f2 = f3;
		g1 = g2;
		g2 = g3;
		}
	if(n==2) return 3.5;
	return(f(n-1)+f3/g3);
	}

int peach(int n){
	int a=1;
	for(int i=1;i<=10-n;i++){
		a = 2*(a+1);
	}
	if (n == 0) return 1;
	return 2*(peach(n-1)+1);
}

double root(double x){
	if (fabs(g(x))<=1e-6) return x;
	else return root(
		x-g(x)/(6*pow(x,2)-8*x+3)
		);
}
double g(double x){
	return(2*pow(x,3)-4*pow(x,2)+3*x-6);
}













