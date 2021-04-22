#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *Linklist;

LNode* build_sigal_cycle_list(int S[],int S_len){
    LNode *temp, *p, *head;
    head = (LNode*)malloc(sizeof(LNode));
    head->data = -1;
    p = head;
    for(int i=0; i<S_len; i++){
        temp = (LNode*)malloc(sizeof(LNode));
        temp->data = S[i];
        p->next = temp;
        p = p->next;
    }
    p->next = head;
    return head;    
}

void find_del_min(LNode *A){
    LNode *min_pre, *pre, *p;
    int mini;
    while(A->next != A){
        pre = A;
        p = A->next;
        mini = p->data;
        while(p != A){
            if(mini > p->data){
                mini = p->data;
                min_pre = pre;
            }
            pre = p;
            p = p->next;
            //printf("%d\n", mini);
        }/*
        if(min_pre->next != A){
            printf("%d\n", mini);
        }*/
        p = min_pre->next;
        //printf("%d\n", min_pre->data);
        min_pre->next = p->next;
        printf("%d\n", p->data);
        free(p);
    }
    free(A);
}

int A[] = {21, 25, 32, 16, 1, 3, 7, 11, 458, 818, 2, 4, 8, 10, 919};


void main(){
    LNode *A_head, *p;
    int symmetric;
    int A_length = sizeof(A) / sizeof(int);
    A_head = build_sigal_cycle_list(A, A_length);/*
    p = A_head ->next;
    while(p != A_head){
        printf("A: %d\n", p->data);
        p = p->next;
    }*/
    find_del_min(A_head);
}