//
//  main.c
//  test
//
//  Created by Troy on 2019/11/4.
//  Copyright © 2019 Troy. All rights reserved.
//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void MagicMatrix(int a[],int m,int n);
int N=0;

int main(void){
    int n;
    printf("enter n:\n");
    scanf("%d",&n);
    n = n*n;
    int *a = (int*)malloc(sizeof(int)*n);
    for(int i =0;i<n;i++){
        a[i]=i+1;
    }
    MagicMatrix(a,0,n);
    free(a);
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
void MagicMatrix(int a[],int m,int n){
    int sq = pow(n,0.5);
    //幻和
    int Msum = sq*(n+1)/2;
    //printf("%d\n",Msum);
    if(m==n){
        int *sum = (int *)malloc(sizeof(int)*(2*n+2));
        //判断每一行
        for(int x=0;x<sq;x++){
            for(int y=0;y<sq;y++){
                sum[x]+=a[x*sq+y];
            }
            if(sum[x]!=Msum) return;
        }
        //判断每一列
        for(int x=0;x<sq;x++){
            for(int y=0;y<sq;y++){
                sum[x+sq]+=a[y*sq+x];
            }
            if(sum[x+sq]!=Msum) return;
        }
        //判断主对角线
        for(int x=0;x<sq;x++){
            sum[2*sq+1]+=a[x*sq+x];
        }
        if(sum[2*sq+1]!=Msum) return;
        //判断副对角线
        for(int x=0;x<sq;x++){
            sum[2*sq+2]+=a[(x+1)*(sq-1)];
        }
        if(sum[2*sq+2]!=Msum) return;
        N++;
        printf("The %4d-th result is:\n",N);
        for(int x = 0; x < sq; x++){
            for(int y = 0; y< sq;y++){
                printf("%4d",a[x*sq+y]);
            }
            printf("\n");
        }
        free(sum);

        printf("\n");

    }
    else{
        if(m>=sq){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[y];
            }
            if(sum!=Msum) return;
        }
        if(m>=2*sq){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[sq+y];
            }
            if(sum!=Msum) return;
        }
        
        if(n==16&&m>3*sq-1){
            int sum;
            sum = a[5]+a[6]+a[9]+a[10];
            if(sum!=Msum) return;
        }
         
        if(m>=3*sq){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[2*sq+y];
            }
            if(sum!=Msum) return;
        }
        if(m>3*sq){
            int sum1 = 0;
            int sum2 = 0;
            for(int y=0;y<sq;y++){
                sum1+=a[y*sq];
                sum2+=a[(y+1)*(sq-1)];
            }
            if(sum1!=Msum||sum2!=Msum) return;
        }
        for(int i = m; i<n; i++){
            swap(a+i,a+m);
            MagicMatrix(a,m+1,n);
            swap(a+i,a+m);
        }
    }
}





