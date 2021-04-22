#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *Linklist;


LNode* build_list(int S[],int S_len){
    LNode *temp, *p, *head;
    head = (LNode*)malloc(sizeof(LNode));
    head->data = -1;
    for(int i=S_len-1; i>=0; i--){
        p = (LNode*)malloc(sizeof(LNode));
        p->data = S[i];
        if(i==S_len-1){
            p->next = NULL;
        }
        else{
            p->next = temp;
        }
        temp = p;
        //printf("%d\n", p->data);
    }
    head->next = p;
    return head;
}



int find_last_k(LNode *L, int k){
    LNode *p = L->next, *q = L;
    for(; k-1>0; k--){
        if(p==NULL && q==L){
            printf("can not find\n");
            return 0;
        }
        else{
            p = p->next;
        }
    }
    while(p != NULL){
        p = p->next;
        q = q->next;
    }
    printf("%d\n", q->data);
    return 1;
}

int A[] = {21, 25, 32, 16, 1, 3, 7, 11, 458, 818, 2, 4, 8, 10, 919};

void main(){
    LNode *A_head, *p;
    int k = 17, last_k;
    int A_length = sizeof(A) / sizeof(int);
    A_head = build_list(A, A_length);
    p = A_head ->next;
    while(p != NULL){
        printf("A: %d\n", p->data);
        p = p->next;
    }
    last_k = find_last_k(A_head, k);
    printf("%d", last_k);
}