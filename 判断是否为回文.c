#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

typedef struct heap{
    int data;
    struct heap *next;
}heap;

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
    }
    head->next = p;
    return head;
}

heap* build_heap(){
    heap *h;
    h = (heap*)malloc(sizeof(heap));
    return h;
}

int is_symmetry(LNode *h){
    heap *top;
    top = (heap*)malloc(sizeof(heap));
    top->next = NULL;
    LNode *p = h->next;
    if(p == NULL){
        return true;
    }
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    p = h->next;
    for(int i=0; i<count/2; i++){
        heap *temp;
        temp = (heap*)malloc(sizeof(heap));
        temp->data = p->data;
        temp->next = top->next;
        top->next = temp;
        p = p->next;
    }
    if(count%2 == 1){
            p = p->next;
    }
    while(top->next != NULL){
        printf("%d", top->next->data);
        printf("%d\n", p->data);
        if(top->next->data == p->data){
            top = top->next;
            p = p->next;
        }
        else{
            printf("no symmetry\n");
            return false;
        }
    }
    printf("symmetry\n");
    return true;
}



int A[] = {21, 25, 32, 16, 1, 3, 7, 7, 3, 1, 16, 32, 25, 21};

void main(){
    LNode *L;
    int A_len, result;
    A_len = sizeof(A) / sizeof(int);
    L = build_list(A, A_len);
    result = is_symmetry(L);
    printf("%d\n", result);
}