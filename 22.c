#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *link;
}LNode;

LNode* build_list(int S[],int S_len){
    LNode *temp, *p, *head;
    head = (LNode*)malloc(sizeof(LNode));
    head->data = -1;
    for(int i=S_len-1; i>=0; i--){
        p = (LNode*)malloc(sizeof(LNode));
        p->data = S[i];
        if(i==S_len-1){
            p->link = NULL;
        }
        else{
            p->link = temp;
        }
        temp = p;
        //printf("%d\n", p->data);
    }
    head->link = p;
    return head;
}

void del_abs_same(LNode *L, int max){
    int temp[max+1];
    LNode *p = L->link, *pre = L;
    for(int i=0; i<=max; i++){
        temp[i] = 0;
    }
    while(p != NULL){
        if(temp[abs(p->data)] == 1){
            pre->link = p->link;
            free(p);
            p = pre->link;
        }
        else{
            temp[abs(p->data)] = 1;
            pre = p;
            p = p->link;
        }
    }
}






int A[] = {19, 2, 32, -10, 1, 3, 7, 11, -2, 4, 8, 2, 4, -8, 10, -19};



void main(){
    LNode *A_head, *p;
    int max = A[0];
    int A_length = sizeof(A) / sizeof(int);
    for(int i=0; i<A_length; i++){
        if(max < A[i]){
            max = A[i];
        }
    }
    A_head = build_list(A, A_length);
    p = A_head ->link;
    while(p != NULL){
        printf("A: %d\n", p->data);
        p = p->link;
    }
    printf("-------------------\n");
    del_abs_same(A_head, max);
    p = A_head ->link;
    while(p != NULL){
        printf("A: %d\n", p->data);
        p = p->link;
    }
}