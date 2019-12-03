#include<stdio.h>
#include<stdlib.h>
void sort(int *a, int n);
int main(){
	printf("Chapter 6\n");
	
	printf("2]\n");
	{
		int a[10];
		int i,j,k,t;
		for(i = 0; i<10; i++){
			scanf("%d",&a[i]);
		}
		sort(a,10);
	}

	printf("4]\n");
	{
		int len = 10;
		int x,i;
		int* a = (int*)malloc(len*sizeof(int));
		for(i = 0; i<len; i++){
			a[i] = rand()%100;
		}
		sort(a,len);
		printf("Please enter the number you want to insert:\n");
		scanf("%d", &x);
		getchar();
		int *olda = a;
		len++;
		a  = realloc(a,len*sizeof(int));
		a[len-1]=x;
		sort(a,len);
		free(olda);
		printf("\n");
	}

	printf("6]\n");
	{
		int a[10][10]={{1},{1,1}};
		int i,j;
		for(i = 1; i<10; i++){
			a[i][0] = 1;
			a[i][i] = 0;
			for (j =1 ; j<=i; j++){
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(i =0 ;i < 10; i++){
			for(j=0;j<=i;j++){
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
	}

	printf("8]\n");
	{
		int i,j,l=0,k=0;
		int a[5][5]={{1,2,3,6,4},{7,8,9,8,3},{2,1,3,9,7},{1,2,5,9,10},{2,6,5,7,2}};
		for(i =0 ;i < 5; i++){
			for(j=0;j< 5;j++){	
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}
		for(i =0 ,k=0 ;i < 5; i++){
			for(j=0;j< 5;j++){
				if(a[i][j]>a[i][l]){
					l = j;
				}
			}
			for(int n = 0; n < 5; n++){
				if(a[n][l]<a[i][l]){
					k=1;
				}
			}
			if(k==0)
				printf("a[%d][%d]=%d\n",i,l,a[i][l]);
		}
		printf("\n");
	}
	printf("Caculator\n");
	{
		{
		char c[]={};
		float a[]={};
		gets(c);
		int i,n;
		for(i = 0;c[i]!='\0';i++){
			if(!((c[i]==42)||(c[i]==43)||(c[i]==45)||(c[i]<=57&&c[i]>=47))||((c[i]<=57&&c[i]>47)&&(c[i+1]<=57&&c[i+1]>47))){
						printf("\aError.\nOnly 0~9 Four Arithmetic Operations allowed\n");
						return 0;
					}	
				if(c[i]<58&&c[i]>47)
					c[i] = c[i]-48;
		}

		for(i = 0;c[i]!='\0';i++){
			switch(c[i]){
				case '*' : {
					c[i-1] = c[i-1]*c[i+1]; 
				//printf("%d\n",c[i-1]);
				//puts(c);
					if(c[i+2]!='\0'){
						for(n = i; c[n+2]!='\0'; n++){
							c[n] = c[n+2];
						}
					//puts(c);
						c[n]='\0';
						i = 0;
					}
					else{
						c[i]='\0';
					//puts(c);
					}
					break;
				//printf("%d\n",c[0]);
				}
				case '/' : {
					c[i-1] = c[i-1]/c[i+1];
				//printf("%d\n",c[i-1]);
					if(c[i+2]!='\0'){
						for(n = i; c[n+2]!='\0'; n++){
							c[n] = c[n+2];
						}
						c[n]='\0';
						i = 0;
					}
					else{
						c[i]='\0';
					}
					break;
				}
				default : continue;
			}//puts(c);	
		}
		//puts(c);
		for(i = 0;c[i]!='\0';i++){
			switch(c[i]){
				case '+' : {
					c[i-1] = c[i-1]+c[i+1];
				//printf("%d\n",c[i-1]);
					if(c[i+2]!='\0'){
						for(n = i; c[n+2]!='\0'; n++){
							c[n] = c[n+2];
						}
						c[n]='\0';
						i = 0;
					}
					else{
						c[i]='\0';
					}
					break;
				//puts(c);
				}
				case '-' :{
					c[i-1] = c[i-1]-c[i+1];
					//printf("%d\n",c[i-1]);
					if(c[i+2]!='\0'){
						for(n = i; c[n+2]!='\0'; n++){
							c[n] = c[n+2];
						}
						c[n]='\0';
						i = 0;
					}
					else{
						c[i]='\0';
					}
					break;
				}
				default : continue;
			}	
		}
		printf("%d\n",c[0]);
		//puts(c);
		return 0;
	}

	}
}


void sort(int *a, int n){
	int i,j,t,k;
	for(i = 0; i<n; i++){
		k=i;
		for( j = i; j<n; j++){
			if(*(a+j)>=*(a+k))
			k = j;
		}
			t=*(a+k);*(a+k)=*(a+i);*(a+i)=t; 
		}
	for(i = 0; i<n; i++){
		printf("%5d",a[i]);
		}
		printf("\n");
	}

