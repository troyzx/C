//
//  main.c
//  pointer
//
//  Created by Troy on 2019/10/17.
//  Copyright © 2019 Troy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned seed = 0;

int intRand(int Min, int Max);
void print_line(void);
void swap(int *p, int *q);
void sort(int *a, int n);
void swap_pointer(int **p, int **q);

int main(int argc, const char * argv[]) {
    //init
    
    int i = 0,j=0,k=0;
    int city_length[5]={};
    int ***country = (int***)malloc(5*sizeof(int**));
    for(i = 0; i < 5; i++){
        int c_len = intRand(3,5);
        city_length[i]=c_len;
        *(country+i) = (int**)malloc(c_len*sizeof(int*));
        for(j = 0; j<c_len; j++){
            int s_len = intRand(6,11);
            *(*(country+i)+j) = (int*)malloc(s_len*sizeof(int));
            *(*(*(country+i)+j)) = s_len;
            for(k = 1; k<s_len; k++){
                *(*(*(country+i)+j)+k) = intRand(0,10000);
            }
        }
    }
    
    //begin simulation
    print_line();
    printf("Simulation begin!\n");
    print_line();
    
    //print orginal data
    
    for(i = 0; i < 5; i++){
        printf("Province %d (%d cities):\n",i,city_length[i]);
        for(j = 0; j<city_length[i]; j++){
            printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
            for(k = 1; k<*(*(*(country+i)+j)); k++){
                printf("%8d",*(*(*(country+i)+j)+k));
            }
            printf("\n");
        }
        printf("\n");
    }
    
    print_line();
    printf("City competition\n");
    print_line();
    getchar();
    
    //find the highest score in a city
    for(i = 0; i < 5; i++){
        printf("Province %d (%d cities):\n",i,city_length[i]);
        for(j = 0; j<city_length[i]; j++){
            printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
            sort((*(*(country+i)+j)+1), *(*(*(country+i)+j))-1);
            for(k = 1; k<*(*(*(country+i)+j)); k++){
                printf("%8d",*(*(*(country+i)+j)+k));
            }
            printf("\n");
        }
        printf("\n");
    }
    
    print_line();
    printf("Province competition\n");
    print_line();
    getchar();
    
    //find the highest city
    for(i = 0; i < 5; i++){
        printf("Province %d (%d cities):\n",i,city_length[i]);
        
        for(j = city_length[i]-1; j>0; j--){
            if(*(*(*(country+i)+j)+1)>*(*(*(country+i)+j-1)+1))
                swap_pointer(*(country+i)+j, *(country+i)+j-1);
        }
        
        for(j = 0; j<city_length[i]; j++){
            
            printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
            sort((*(*(country+i)+j)+1), *(*(*(country+i)+j))-1);
            for(k = 1; k<*(*(*(country+i)+j)); k++){
                printf("%8d",*(*(*(country+i)+j)+k));
            }
            printf("\n");
        }
        printf("\n");
    }
    
    //Whole country
    print_line();
    printf("Country competition\n");
    print_line();
    getchar();
    
    int max_province = 0;
    for(i = 0; i < 5; i++){
        if(*(*(*(country+i))+1)>*(*(*(country+max_province))+1)){
            max_province = i;
        }
    }
    printf("Province %d wins!\tscore=%d\n", max_province,*(*(*(country+max_province))+1));
    
    print_line();
    printf("press to see statics\n");
    print_line();
    getchar();
    
    int sum[5]={};
    for(i = 0; i < 5; i++){
        for(j = 0; j<city_length[i]; j++){
            sum[i]+=*(*(*(country+i)+j));
        }
        printf("Province %3d : %3d cities, %3d students, maxscore = %5d.\n\n",i,city_length[i],sum[i],*(*(*(country+i))+1));
    }
    
    //free
    for(i = 0; i < 5; i++){
        for(j = 0; j<city_length[i]; j++){
            free(*(*(country+i)+j));
        }
        free(*(country+i));
    }
    free(country);
   
    //1e7 simulations
    print_line();
    printf("press to start 1e7 simulations\n");
    print_line();
    getchar();
    
    int n_sim = 0;
    int prob=0;
    while(n_sim<=10000000){
        
        n_sim++;
        
        
        int i = 0,j=0,k=0;
        int city_length[5]={};
        int ***country = (int***)malloc(5*sizeof(int**));
        for(i = 0; i < 5; i++){
            int c_len = intRand(3,5);
            city_length[i]=c_len;
            *(country+i) = (int**)malloc(c_len*sizeof(int*));
            for(j = 0; j<c_len; j++){
                int s_len = intRand(6,11);
                *(*(country+i)+j) = (int*)malloc(s_len*sizeof(int));
                *(*(*(country+i)+j)) = s_len;
                for(k = 1; k<s_len; k++){
                    *(*(*(country+i)+j)+k) = intRand(0,10000);
                }
            }
        }
        
        //print orginal data
        
        for(i = 0; i < 5; i++){
            //printf("Province %d (%d cities):\n",i,city_length[i]);
            for(j = 0; j<city_length[i]; j++){
                //printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
                for(k = 1; k<*(*(*(country+i)+j)); k++){
                    //printf("%8d",*(*(*(country+i)+j)+k));
                }
                //printf("\n");
            }
            //printf("\n");
        }
        
        
        //find the highest score in a city
        for(i = 0; i < 5; i++){
            //printf("Province %d (%d cities):\n",i,city_length[i]);
            for(j = 0; j<city_length[i]; j++){
                //printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
                sort((*(*(country+i)+j)+1), *(*(*(country+i)+j))-1);
                for(k = 1; k<*(*(*(country+i)+j)); k++){
                    //printf("%8d",*(*(*(country+i)+j)+k));
                }
                //printf("\n");
            }
            //printf("\n");
        }
        
        
        //find the highest city
        for(i = 0; i < 5; i++){
            //printf("Province %d (%d cities):\n",i,city_length[i]);
            
            for(j = city_length[i]-1; j>0; j--){
                if(*(*(*(country+i)+j)+1)>*(*(*(country+i)+j-1)+1))
                    swap_pointer(*(country+i)+j, *(country+i)+j-1);
            }
            
            for(j = 0; j<city_length[i]; j++){
                
                //printf("City %d (%3d students):", j,*(*(*(country+i)+j))-1);
                sort((*(*(country+i)+j)+1), *(*(*(country+i)+j))-1);
                for(k = 1; k<*(*(*(country+i)+j)); k++){
                    //printf("%8d",*(*(*(country+i)+j)+k));
                }
                //printf("\n");
            }
            //printf("\n");
        }
        
        
        int max_province = 0;
        for(i = 0; i < 5; i++){
            if(*(*(*(country+i))+1)>*(*(*(country+max_province))+1)){
                max_province = i;
            }
        }
        //printf("Province %d wins!\tscore=%d\n", max_province,*(*(*(country+max_province))+1));
        
        
        int sum[5]={};
        for(i = 0; i < 5; i++){
            for(j = 0; j<city_length[i]; j++){
                sum[i]+=*(*(*(country+i)+j));
            }
            //printf("Province %3d : %3d cities, %3d students, maxscore = %5d.\n\n",i,city_length[i],sum[i],*(*(*(country+i))+1));
        }
        
        //see if the province has the most people wins
        int max_people=0;
        for(i = 0; i < 5; i++){
            if(sum[max_people]<sum[i]){
                max_people=i;
            }
        }
        if(max_province==max_people){
            prob++;
        }
        
        //free
        for(i = 0; i < 5; i++){
            for(j = 0; j<city_length[i]; j++){
                free(*(*(country+i)+j));
            }
            free(*(country+i));
        }
        free(country);
        
        
        //loading
        if(n_sim%100000==0){
            printf("Finishing  %10d simulations  (%4f%%)\n",n_sim,n_sim/10000000.0*100);
        }
    }
    printf("In 10000000 simulations, %d (%4f%%) equals",prob,prob/10000000.0*100);
    return 0;
}
int intRand(int Min, int Max){
    seed++;
    srand((unsigned)time(NULL)*seed);
    return rand() % (Max+1 - Min) + Min;
}
void print_line(void){
    int n=0;
    while(n<100) {
        printf("-");
        n++;
    }
    printf("\n\n");
}

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int *a, int n){
    int i,j,k;
    for(i = 0; i<n; i++){
        k=i;
        for( j = i; j<n; j++){
            if(*(a+j)>=*(a+k))
                k = j;
        }
        swap(a+k,a+i);
    }
    /*for(i = 0; i<n; i++){
        printf("%5d",a[i]);
    }
    printf("\n");
     */
}
void swap_pointer(int **p, int **q){
    int *ptemp = *p;
    *p = *q;
    *q = ptemp;
}

