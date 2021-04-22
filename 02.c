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


int del_X(LNode *head, int x){
    LNode *pre = head, *p;
    p = pre->next;
    while(p != NULL){
        if(p->data == x){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = p;
            if(p){
                p = p->next;
            }
            //printf("%d\n", p->data);
        }
        
    }
}


int L[] = {2, 4, 8, 10, 16, 32, 458, 32, 818, 919, 919};
int x = 919;

void main(){
    LNode *L_head, *start;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    del_X(L_head, x);
    while(L_head){
        printf("%d\n", L_head->next->data);
        L_head = L_head->next;
    }
}