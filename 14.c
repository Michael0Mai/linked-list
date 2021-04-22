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

LNode* find_common_num(LNode *A, LNode *B){
    LNode *C, *temp, *cp;
    C = (LNode*)malloc(sizeof(LNode));
    cp = C;
    A = A->next;
    B = B->next;
    while(A != NULL && B != NULL){
        if(A->data == B->data){
            temp = (LNode*)malloc(sizeof(LNode));
            temp->data = A->data;
            cp->next = temp;
            cp = cp->next;
            A = A->next;
            B = B->next;
        }
        else if(A->data > B->data){
            B = B->next;
        }
        else{
            A = A->next;
        }
    }
    cp->next = NULL;
    return C;

}

int A[] = {1, 2, 3, 7, 10, 21, 25};
int B[] = {2, 7, 8, 10, 21, 25, 32, 458, 818, 919};

void main(){
    LNode *A_head, *B_head, *common;
    int A_length = sizeof(A) / sizeof(int);
    int B_length = sizeof(B) / sizeof(int);
    A_head = build_list(A, A_length);
    B_head = build_list(B, B_length);
    common = find_common_num(A_head, B_head);  
    while(A_head->next != NULL){
        printf("%d\n", A_head->next->data);
        A_head = A_head->next;
    }

    while(B_head->next != NULL){
        printf("%d\n", B_head->next->data);
        B_head = B_head->next;
    }
    while(common->next != NULL){
        printf("%d\n", common->next->data);
        common = common->next;
    }
}