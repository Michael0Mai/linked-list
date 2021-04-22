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

void build_Y_Link(LNode *A, LNode *B, int B_len){ //将2条链合在一起
    for(int i=0; i<B_len/2 +2; i++){
        B = B->next;
    }
    while(A->next != NULL){
        A = A->next;
    }
    A->next = B;
}

LNode* find_common_node(LNode *A, LNode *B){
    LNode *pA = A->next, *pB = B->next;
    int len_A=0, len_B=0, diff;
    while(pA != NULL){
        len_A++;
        pA = pA->next;
    }
    while(pB != NULL){
        len_B++;
        pB = pB->next;
    }
    diff = len_A - len_B;
    printf("diff: %d\n", diff);

    if(diff > 0){
        while(diff > 0){
            A = A->next;
            diff--;
        }
    }
    else if(diff < 0){
        while(diff < 0){
            B = B->next;
            diff++;
        }
    }
    else{
        NULL;
    }
    while(A!=NULL && B!=NULL){
        
        if(A == B){
            printf("%d\n", A->data);
            printf("%d\n", B->data);
            return A;
        }
        else{
            A = A->next;
            B = B->next;
        }
    }
    return NULL;
}

int A[] = {1, 3, 7, 11, 21, 25};
int B[] = {2, 4, 8, 10, 16, 32, 458, 818, 919};

void main(){
    LNode *A_head, *B_head, *common_node;
    int A_length = sizeof(A) / sizeof(int);
    int B_length = sizeof(B) / sizeof(int);
    A_head = build_list(A, A_length);
    B_head = build_list(B, B_length);
    build_Y_Link(A_head, B_head, B_length);
    common_node = find_common_node(A_head, B_head);  
    
    while(A_head->next != NULL){
        printf("A: %d\n", A_head->next->data);
        A_head = A_head->next;
    }
    while(B_head->next != NULL){
        printf("B: %d\n", B_head->next->data);
        B_head = B_head->next;
    }
    while(common_node != NULL){
        printf("%d\n", common_node->data);
        common_node = common_node->next;
    }
        
}