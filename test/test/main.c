//
//  main.c
//  test
//
//  Created by Troy on 2019/9/26.
//  Copyright © 2019 Troy. All rights reserved.
//
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *p, int *q);
void MagicMatrix(int a[],int m,int n);

int N=0;

int main(void){
    int sq;
    printf("enter n:\n");
    scanf("%d",&sq);
    int n = sq*sq;
    int *a = malloc(sizeof(int)*n);
    for(int i =0;i<n;i++){
        a[i]=i+1;
    }
    MagicMatrix(a,0,n);
}

void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void MagicMatrix(int a[],int m,int n){
    int sq = sqrt(n);
    //幻和
    int Msum = sq*(n+1)/2;
    if(m==n){
        int sum=0;
        //判断每一行
        for(int x=0;x<sq;x++){
            for(int y=0;y<sq;y++){
                sum+=a[x*sq+y];
            }
            if(sum!=Msum) {
                return;
            }
            sum=0;
        }

        //判断每一列
        for(int x=0;x<sq;x++){
            for(int y=0;y<sq;y++){
                sum+=a[y*sq+x];
            }
            if(sum!=Msum) return;
            sum=0;
        }
        //判断主对角线
        
        for(int x=0;x<sq;x++){
            sum+=a[x*sq+x];
        }
        if(sum!=Msum) return;
        sum=0;
        
        //判断副对角线
        for(int x=0;x<sq;x++){
            sum+=a[(x+1)*(sq-1)];
        }
        if(sum!=Msum) return;
        sum=0;

        N++;
        printf("The %4d-th result is:\n",N);
        for(int y = 0; y < pow(n,0.5); y++){
            for(int j = 0; j< pow(n,0.5);j++){
                printf("%4d",a[3*y+j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else{
        //第一行
        if(m>=sq){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[y];
            }
            if(sum!=Msum) {
                return;
            }
        }
        //第二行
        if(m>=(2*sq)){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[sq+y];
            }
            if(sum!=Msum) return;
        }
        //中间四个
        
        if(m>10){
            int sum;
            sum = a[5]+a[6]+a[9]+a[10];
            if(sum!=Msum) return;
        }
        
        //第三行
        if(m>=(3*sq)){
            int sum = 0;
            for(int y=0;y<sq;y++){
                sum+=a[2*sq+y];
            }
            if(sum!=Msum) return;
        }
        //第一列&&副对角线
        if(m>(3*sq)){
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

