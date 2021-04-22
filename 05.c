#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *Linklist;

LNode*build_list(int S[],int S_len){
    LNode *temp, *p, *head;
    head = (LNode*)malloc(sizeof(LNode));
    head->data = NULL;
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


void reverse(LNode *head){
    LNode *p = head->next, *pre = head, *n = head, *mark = head->next;
    while(n != mark){
        while(p->next != NULL){
        pre = p;
        p = p->next;
        }
        n->next = p;
        pre->next = NULL;
        n = p;
        p = mark;
    }
}

//int L[] = {2, 4, 8, 10, 16, 32, 458, 32, 818, 919, 919};

void main(){
    LNode *L_head, *start;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    reverse(L_head);  
    while(L_head){
        printf("%d\n", L_head->next->data);
        L_head = L_head->next;
    }
}