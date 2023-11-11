#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode{
    E element;
    struct ListNode* next;
    struct ListNode* prev;
};

typedef struct ListNode* Node;

void initList(Node head){
    head -> next = NULL;
    head -> prev = NULL;
}

bool insertList(Node head, E element, int index){
    if(index<1){
        return 0;
    }
    while(--index){
        head = head->next;
        if(head == NULL){
            return 0;
        }
    }
    Node node = malloc(sizeof (struct ListNode));
    if(node == NULL){
        return 0;
    }
    node->element = element;
    if(head->next != NULL){
        node->next = head->next;
        head->next->prev = node;
    }else{
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 1;
}

bool deleteList(Node head, int index) {
    if (index < 1) {
        return 0;
    }
    while (--index) {
        head = head->next;
        if (head == NULL) {
            return 0;
        }
    }
    if (head->next == NULL) {
        return 0;
    }
    Node temp = head->next;
    if (head->next->next) {
        head->next->next->prev = head;
        head->next = head->next->next;
    } else {
     head->next = NULL;
    }

    free(temp);
    return 1;
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i =1; i<=5; i++){
        insertList(&head, i*100, i);
    }

    Node node = &head; //正向遍历
//    node = node->next;
    while(node->next !=NULL){
        node = node->next;
        printf("%d ->", node->element);
    }
    printf("\n");

     //反向遍历

    while(node->prev !=NULL){
        printf("%d <-", node->element);
        node = node->prev;
    }
    printf("\n");

    deleteList(node, 4);
    while(node->next !=NULL){
        node = node->next;
        printf("%d ->", node->element);
    }
    printf("\n");
    return 0;
}

