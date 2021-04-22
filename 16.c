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

int is_sub(LNode *A, LNode *B){
    LNode *pb, *pa = A->next, *p = A->next;
    while(p != NULL){
        pb = B->next;
        while(pa->data == pb->data){
            pa = pa->next;
            pb = pb->next;
            if(pb == NULL){
                return true;
            }
            if(pa == NULL){
                return false;
            }
        }
        pa = p->next;
        p = p->next;
    }
}

int A[] = {2, 4, 8, 10, 16, 1, 3, 7, 11, 21, 25, 32, 458, 818, 919};
int B[] = {1, 3, 7, 11, 21, 25, 32, 458, 818, 919};


void main(){
    LNode *A_head, *B_head;
    int sub;
    int A_length = sizeof(A) / sizeof(int);
    int B_length = sizeof(B) / sizeof(int);
    A_head = build_list(A, A_length);
    B_head = build_list(B, B_length);
    sub = is_sub(A_head, B_head);
    while(A_head->next != NULL){
        printf("A: %d\n", A_head->next->data);
        A_head = A_head->next;
    }
    while(B_head->next != NULL){
        printf("B: %d\n", B_head->next->data);
        B_head = B_head->next;
    }
    printf("%d", sub);
}