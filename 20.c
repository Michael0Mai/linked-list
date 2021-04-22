#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct DLNode {
    int data, freq;
    struct DLNode *pred, *next;
}DLNode;

DLNode* build_dual_list(int S[],int S_len){
    DLNode *temp, *p, *head;
    head = (DLNode*)malloc(sizeof(DLNode));
    head->data = -1;
    head->pred = NULL;
    p = head;
    for(int i=0; i<S_len; i++){
        temp = (DLNode*)malloc(sizeof(DLNode));
        temp->freq = 0;
        temp->data = S[i];
        temp->pred = p;
        p->next = temp;
        p = p->next;
    }
    p->next = NULL;
    return head;    
}

DLNode* locat(DLNode *L, int x){
    DLNode *pre, *p = L->next;
    while(p->data != x){
        p = p->next;
    }
    p->freq++;
    p->pred->next = p->next;
    if(p->next != NULL){
        p->next->pred = p->pred;
    }
    pre = p->pred;
    while(pre->freq<p->freq && pre!=L){
        pre = pre->pred;
    }
    p->next = pre->next;
    p->pred = pre;
    pre->next = p;
    p->next->pred = p;
    return p;
    //printf("%d, %d, %d, %d\n", p->pred->data, p->next->pred->data, p->freq, p->next->data);
}





int A[] = {21, 25, 32, 16, 1, 3, 7, 11, 458, 818, 2, 4, 8, 10, 919};

void main(){
    DLNode *A_head, *p, *result;
    int A_length = sizeof(A) / sizeof(int);
    A_head = build_dual_list(A, A_length);
    p = A_head ->next;
    while(p != NULL){
        printf("A: %d, %d\n", p->data, p->freq);
        p = p->next;
    }
    result = locat(A_head, 1);
    result = locat(A_head, 10);
    result = locat(A_head, 919);
    p = A_head ->next;
    while(p != NULL){
        printf("A: %d, %d\n", p->data, p->freq);
        p = p->next;
    }
}