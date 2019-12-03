//
//  main.c
//  week7
//
//  Created by Troy on 2019/10/17.
//  Copyright © 2019 Troy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seed = 0;

int intRand(int Min, int Max);
float get_avg(float *a,int n);

struct student {
    int id;
    float *score;
    int age;
    float avg;
    struct student * next;
};

struct student * creat_chain(int n){
    struct student * head = NULL;
    
    struct student * p = NULL;
    
    int id, age; float *score; float avg = 0.0;
    
    int i;
    
    for(i=0; i<n; i++){
        id = rand()%100; age = rand()%10+10;
        score = (float*)malloc(sizeof(float)*3);
        float sum = 0;
        for(int j = 0; j<3; j++){
            score[j] = intRand(70, 100);
            sum+=score[j];
        }
        avg = sum/3;
        if(i==0){
            head = (struct student *)malloc(sizeof(struct student));
            head->id =id; head->age=age; head-> score = score; head->avg = avg;
            head->next = NULL;
            p = head;
        }
        else{
            p->next = (struct student *)malloc(sizeof(struct student));
            p = p->next;
            p->id =id; p->age=age; p->score = score; p->avg = avg; p->next = NULL;
        }
    }
    return head;
};

void print_line(void){
    int n=0;
    while(n<33) {
        printf("-");
        n++;
    }
    printf("\n");
}

void print_chain(struct student * head){
    struct student *p = head;
    int i=1;
    printf("\nid\tage\t\t\tscore\t\t\tavg\n");
    while(p!=NULL){
        printf("%d\t%d\t", p->id, p->age);
        for(int j = 0; j<3; j++){
            printf("%.1f\t",p->score[j]);
        }
        printf("%.1f",p->avg);
        printf("\n");
        p = p->next;
        i++;
    }
}

void find_chain_max(struct student *max, struct student * head){
    struct student *p = head;
    while(p!=NULL){
        if(p->avg>max->avg){
            *max = *p;
        }
        p = p->next;
    }
}



struct num{
    int id;
    struct num *next;
};

struct num * creat_numchain(int n){
    struct num * head = NULL;
    
    struct num * p = NULL;
    
    for(int i=0; i<n; i++){
        if(i==0){
            head = (struct num *)malloc(sizeof(struct num));
            head->id = i+1;
            head->next = NULL;
            p = head;
        }
        else{
            p->next = (struct num *)malloc(sizeof(struct num));
            p = p->next;
            p->id =i+1;
        }
    }
    p->next=head;
    return head;
};

struct num *delete_numchain(struct num *head,int given_id){
    struct num *p, *ptmp;
    while(head->id == given_id){
        p = head;
        head = head->next;
        free(p);
    }
    p = head;
    while(1){
        if(p==NULL||p->next==head) break;
        if(p->next->id == given_id){
            ptmp = p->next;
            p->next = p->next->next;
        }
        p = p->next;
    }
    return head;
}

void print_numchain(struct num * head){
    struct num *p = head;
    while(1){
        printf("%d\t", p->id);
        p = p->next;
        if(p==head) break;
    }
    printf("\n");
}


struct student *delete_chain(struct student *head,int given_id){
    struct student *p, *ptmp = NULL;
    while(head->id == given_id){
        p = head;
        head = head->next;
        //free(p);
    }
    p = head;
    while(1){
        if(p==NULL||p->next==NULL) break;
        if(p->next->id == given_id){
            ptmp = p->next;
            p->next = p->next->next;
        }
        p = p->next;
    }
    return head;
}

struct student *find_chain_maxid(struct student * head){
    struct student *p = head;
    struct student *max = p;
    while(p!=NULL){
        if(p->id > max->id){
            max = p;
        }
        p = p->next;
    }
    return max;
}

struct student *delete_chain_nohead(struct student *head,int given_id){
    struct student *p, *ptmp = NULL;
    p = head;
    while(1){
        if(p==NULL||p->next==NULL) break;
        if(p->next->id == given_id){
            ptmp = p->next;
            p->next = p->next->next;
        }
        p = p->next;
    }
    return head;
}

struct student *sort(struct student * head, int n){
    struct student *max=NULL;
    struct student *new_head=NULL;
    struct student *p = (struct student *)malloc(sizeof(struct student));
    for(int i=0;i<n-1;i++){
        max = find_chain_maxid(head);
        //printf("%d",max->id);
        delete_chain(head, max->id);
        if(i==0){
            p->id = max->id;
            p->age = max->age;
            p->score = max->score;
            p->avg = get_avg(p->score, 3);
            continue;
        }
        p->next = (struct student *)malloc(sizeof(struct student));
        p = p->next;
        p->id = max->id;
        p->age = max->age;
        p->score = max->score;
        p->avg = get_avg(p->score, 3);
        p->next = NULL;
    }
    return new_head;
}

struct student *insert_chain(struct student *head,int given_id,
                             int given_age,
                             float given_score[3]){
    struct student *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = (struct student *)malloc(sizeof(struct student));
    p = p->next;
    p->id = given_id;
    p->age = given_age;
    p->score = given_score;
    p->avg = get_avg(p->score, 3);
    p->next = NULL;
    return head;
}


void swapint(int* p, int* q);
void swapfloat(float* p, float* q);
void swapfloatarray(float *p, float *q, int n);

void SortList(struct student* head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        struct student* pTailNode = NULL;
        struct student* pFlagNode = NULL;
        
        while (pFlagNode != head)
        {
            pTailNode = pFlagNode;
            pFlagNode = head;
            struct student* pPreNode = head;
            while (pPreNode->next != pTailNode)
            {
                struct student* pCurNode = pPreNode->next;
                if (pPreNode->id > pCurNode->id)
                {
                    swapint(&pPreNode->id,&pCurNode->id);
                    swapint(&pPreNode->age,&pCurNode->age);
                    swapfloat(&pPreNode->avg,&pCurNode->avg);
                    swapfloatarray(pPreNode->score, pCurNode->score, 3);
                    //记住最后一次发生交换的地方
                    pFlagNode = pPreNode->next;
                }
                pPreNode = pPreNode->next;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    printf("5]\n");
    {
        struct student *p = creat_chain(10);
        print_chain(p);
        struct student *max = p;
        find_chain_max(max, p);
        printf("the highest score goes to:\n");
        printf("%d\t%d\t", max->id, max->age);
        for(int j = 0; j<3; j++){
            printf("%.1f\t",max->score[j]);
        }
        printf("%.1f",max->avg);
        printf("\n");
    }
    
    printf("\n6]\n");
    {
        struct num *head = creat_numchain(13);
        struct num *p = head;
        //p = delete_numchain(p, 7);
        //print_numchain(p);
        int i = 0;
        while(p->next!=p){
            i++;
            if(i%3==0){
                //printf("%d\n",p->id);
                p = delete_numchain(p,p->id);
                i=1;
                print_numchain(p);
            }
            p = p->next;
        }
        print_numchain(p);
    }
    
    printf("\n7]\n");
    {
        int n;
        struct student *p = creat_chain(10);
        print_chain(p);
        printf("\nenter the id you want to delete:\n");
        scanf("%d",&n);
        p = delete_chain(p, n);
        print_chain(p);
        
    }
    
    printf("\n8]\n");
    {
        struct student *p = creat_chain(10);
        print_chain(p);
        float given_score[3] = {99,76,87};
        printf("\nnow insert a student...\n");
        p = insert_chain(p, 11, 18, given_score);
        print_chain(p);
        
    }
    
    printf("\n9]\n");
    {
        int n;
        struct student *p= creat_chain(10);
        print_chain(p);
        printf("\nenter the id you want to delete:\n");
        scanf("%d",&n);
        p = delete_chain(p, n);
        float given_score[3]={99,88,77};
        printf("\nnow insert a student...\n");
        p = insert_chain(p, 11, 16, given_score);
        print_chain(p);
    }
    
    printf("\n10]\n");
    {
        struct student *p=creat_chain(5);
        print_chain(p);
        struct student *q=creat_chain(10);
        print_chain(q);
        struct student *ptmp = p;
        while(ptmp->next!=NULL){
            ptmp=ptmp->next;
        }
        ptmp->next=q;
        print_chain(p);
        SortList(p);
        printf("\nafter sorted by id:\n");
        print_chain(p);
    }
    return 0;
}

int intRand(int Min, int Max){
    seed++;
    srand((unsigned)time(NULL)*seed);
    return rand() % (Max+1 - Min) + Min;
}
float get_avg(float *a,int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum/n;
}

void swapint(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swapfloat(float* p, float* q){
    float temp = *p;
    *p = *q;
    *q = temp;
}


void swapfloatarray(float *p, float *q, int n){
    for(int i = 0; i<n; i++){
        swapfloat(p+i,q+i);
    }
}
