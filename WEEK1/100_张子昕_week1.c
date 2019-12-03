#include<stdio.h>
#include<math.h>
int max(int a, int b);
int main(){


// Chapter 1
printf("Chapter1\n");
	// 4
	printf("<4>\n");
	{
		printf("Hello world!\n");
	}
	
	// 6
	printf("<6>\n");
	{
		int a,b,c,m;
		printf("Please enter 3 numbers:\n");
		scanf("%d%d%d",&a,&b,&c);
		getchar();
		m=max(a,b);
		m=max(m,c);
		printf("%d\n",m);
	}

// Chapter 3
printf("Chapter 3\n");
	// 2
	printf("<2>\n");
	{
		float P[5]={};
		float r[5]={0.015, 0.021, 0.0275, 0.03, 0.0035};
		int n,i;
		//method 1
		P[0]=1000*(1+5*r[3]);
		P[1]=1000*(1+3*r[2])*(1+2*r[1]);
		P[2]=1000*(1+2*r[1])*(1+3*r[2]);
		P[3]=1000*pow((1+r[0]),5);
		P[4]=1000*pow((1+r[4]/4),4*5);
		for(i=0;i<5;i++){
			printf("%f\n",P[i]);
		}
	}
	
	// 6
	printf("<6>\n");
	{
		char c[5]={'C','H','I','N','A'};
		for(int i=0;i<5;i++){
			c[i]+=4;
			putchar(c[i]);
		}
		printf("\n");
		printf("%s\n",c);
	}

	//8
	printf("<8>\n");
	{
		char c1=getchar();
		getchar();
		char c2=getchar();
		putchar(c1);
		printf("\n");
		putchar(c2);
		printf("\n");
		printf("%c\n",c1);
		printf("%c\n",c2);
		//(1)
		printf("(1)二者皆可\n");
		//(2)
		printf("(2)printf(\"%%d\",c1)应用printf函数\n");
		printf("   %d\n",c1);
		//(3)
		printf("(3)不是,char能表示(0~255), int可以表示(-2^31, 2^31 -1)\n");
	}

//appendix
printf("appendix\n");	
	//1
	printf("<1>\n");
	{
		int sum=0;
		for(int i=1;i<=1000;i++){
			sum+=i;
		}
		printf("%d\n",sum);
	}

	//2
	printf("<4>\n");
	{
		int flag=1;
		float sum=1;
		for(int i=1;i<=1000;i++){
			sum+=1.0/i*flag;
			flag*=-1;
		}
		printf("%f\n",sum);
	}
	return 0;
}
int max(int a, int b){
	int m;
	if(a>b) m=a;
	else m=b;
	return(m);
}