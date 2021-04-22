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


void del_min(LNode *head){
    LNode *p = head->next, *pre = head;
    int mini = p->data;
    while(p != NULL){
        if(p->data < mini){
            mini = p->data;
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else{
            pre = p;
            p = p->next;
        }
        //printf("%d\n", p->data);
        //p = p->next;
    }
    if(mini == head->next->data){
        p = head->next;
        head->next = p->next;
        free(p);
    }

}

int L[] = {2, 4, 8, 10, 16, 32};
void main(){
    LNode *L_head, *start;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    del_min(L_head);  
    while(L_head){
        printf("%d\n", L_head->next->data);
        L_head = L_head->next;
    }
}