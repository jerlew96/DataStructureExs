
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//链表 逻辑上相连 物理上不相连
typedef int E;

struct ListNode{
    E element;
    struct ListNode * next;

};

typedef struct ListNode *Node;

//void initList(Node node){
//    node->next = NULL;
//}

Node createList(){
    Node head = (Node)malloc(sizeof(Node));
    if(head == NULL){
        exit(-1);
    }
    head->next = NULL;
    return head;
}

bool inserList(Node head, E element, int index){
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
    node->next = head->next;
    head->next = node;
    return 1;
}

bool deleteList(Node head, int index){
    if(index<1){
        return 0;
    }

    while(--index){
        head = head->next;
        if(head == NULL){
            return 0;
        }
    }
    if(head->next == NULL){
        return 0;
    }
    Node temp = head->next;
    head->next = head->next->next;
    free(temp);
    return 1;
}

E* getList(Node head, int index){
    if(index<1){
        return 0;
    }
    while(index--){
        head = head->next;
        if(head == NULL){
            return 0;
        }
    }
    return &head->element;

}

int findElement(Node head, E element){
    head = head->next;
    int i = 1;
    while(head){
        if(head->element == element){
            return i;
        }
        head = head->next;
        i++;
    }
    return -1;
}

int calcLength(Node head){
    head = head->next;
    int i = 0;
    while(head){
        head = head->next;
        i++;
    }
    return i;
}

void traverseList(Node head){
    while(head->next){
        head = head->next;
        printf("%d ", head->element);
    }
}

int main() {
//    struct ListNode head;
//    initList(&head);
    Node head = createList();
    for (int i = 1; i <=3; i++){
        inserList(head, i*100, i);
    }
    traverseList(head);
//    struct ListNode a,b,c,d,e;
//
//    head->next = &a;
//
//    a.element = 1;
//    b.element = 2;
//    c.element = 3;
//    d.element = 4;
//    e.element = 5;
//
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = &e;
//    e.next = NULL;



//    traverseList(head);
//
//    inserList(head, 6, 2);
//    deleteList(head, 4);
//    traverseList(head);
//    printf("%d ",findElement(head, 300));
    printf("%d ",calcLength(head));




    return 0;
}
