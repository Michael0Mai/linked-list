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

void sort_stb(LNode *head){
    LNode *pre = head, *p, *np = head, *mini_pre = head;
    int mini;
    while(np->next != NULL){
        mini = np->next->data; //设mini的值
        p = np->next; //设p的位置
        mini_pre = np;
        while(p != NULL){
            if(p->data < mini){
                mini = p->data;
                mini_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        if(mini_pre != np){ //如果第一个数不是最小值，才需要移动
            p = mini_pre->next;  //P是最小值
            mini_pre->next = p->next; // P拿出来
            p->next = np->next; //新链的后面P放入头节点
            np->next = p; //新链的后面P放入头节点
        }
        np = np->next; //新链的尾节点后移一位
        
    }
}

//int L[] = {2, 4, 8, 10, 16, 32, 458, 32, 818, 919, 919, 1, 2};
int L[] = {1, 919, 919, 818, 32, 458, 32, 16, 10, 8, 4, 2};

void main(){
    LNode *L_head, *start;
    int length = sizeof(L) / sizeof(int);
    L_head = build_list(L, length);
    sort_stb(L_head);  
    while(L_head){
        printf("%d\n", L_head->next->data);
        L_head = L_head->next;
    }
}