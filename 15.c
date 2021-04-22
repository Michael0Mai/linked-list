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

void find_common_num(LNode *A, LNode *B){
    LNode *pre = A, *p = A;
    p = p->next;
    B = B->next;
    while(p != NULL && B != NULL){
        //printf("%d\n", p->data);
        if(p->data == B->data){
            printf("%d\n", p->data);
            p = p->next;
            B = B->next;
        }
        else if(p->data > B->data){
            B = B->next;
        }
        else{
            pre->next = p->next;
            //printf("%d\n", p->data);
            free(p);
            p = pre->next;
        }
    }/*
    while(p != NULL){
        //printf("%d\n", pre->data);
        pre->next = NULL;
        pre = p;
        p = p->next;
    }*/
    while(A != NULL){
        //printf("%d\n", A->data);
        A = A->next;
    }
}

int A[] = {2, 7, 8, 9, 10, 21, 25, 32, 458, 818, 919};
int B[] = {1, 2, 3, 7, 10, 21, 25, 26};


void main(){
    LNode *A_head, *B_head;
    int A_length = sizeof(A) / sizeof(int);
    int B_length = sizeof(B) / sizeof(int);
    A_head = build_list(A, A_length);
    B_head = build_list(B, B_length);
    find_common_num(A_head, B_head);  
    while(A_head->next != NULL){
        printf("%d\n", A_head->next->data);
        A_head = A_head->next;
    }
    while(B_head->next != NULL){
        printf("%d\n", B_head->next->data);
        B_head = B_head->next;
    }
}