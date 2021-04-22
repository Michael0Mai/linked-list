#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *Linklist;

LNode*build_list(int S[],int S_len){
    LNode *temp, *p;
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
    }
    return p;
}

int del_X(LNode *p, int x){
    printf("%d\n", p->data);
    if(p->next->data == x){
        p->next = p->next->next;
    }
    if(p->next == NULL){
        return 0;
    }
    else{
        del_X(p->next, x);
    }
}

int L[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};
int x = 2;

void main(){
    LNode *L_head, *start;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    while(L_head->data == x){
        L_head = L_head->next;
    }
    start = L_head;
    printf("%d\n", start);
    int i= del_X(L_head, x);
    printf("%d\n", start);
    while(start){
        printf("%d\n", start->data);
        start = start->next;
    }
}