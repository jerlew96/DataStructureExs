#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct Queue{
    E* array;
    int capacity;
    int front, rear;
};

struct queueNode{
    E element;
    struct queueNode* next;
};

typedef struct Queue * ArrayQueue;
typedef struct queueNode * Node;

struct Queue_list{
    Node head, rear;
};

typedef struct Queue_list * Queue_list;
bool initQueue_list(Queue_list queue){
    Node node = malloc(sizeof (Node));
    if(node == NULL){
        return false;
    }
    queue->rear = queue->head = node;
    return true;
}

bool offerQueue_list(Queue_list queue, E element){
    Node node = malloc(sizeof(Node));
    if(node == NULL){
        return false;
    }
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    node->next = NULL;
    return true;
}

bool isEmpty_list(Queue_list queue){
    return queue->rear == queue->head;
}

E pollQueue_list(Queue_list queue){
    Node temp = queue->head->next;
    E e = temp->element;
    queue->head->next = queue->head->next->next;
    if(queue->rear == temp){
        queue->rear = queue->head;
    }
    free(temp);
    return e;

}

void printQueue_list(Queue_list queue){
    printf("<<<");
    Node node = queue->head->next;
    while(node){
        printf("%d ", node->element);
        node = node->next;
    }
    printf("<<<\n");
}

bool initQueue(ArrayQueue queue){
    queue->array = malloc(sizeof(E)*10);
    if(queue->array == NULL){
        return false;
    }
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return true;
}

bool offerQueue(ArrayQueue queue, E element){
    int pos = (queue->rear+1)%queue->capacity;
    if(pos == queue->front){
        return false;
    }
    queue->rear = pos;
    queue->array[queue->rear] = element;
    return true;
}

bool isEmpty(ArrayQueue queue){
    return queue->rear == queue->front;
}

E pollQueue(ArrayQueue queue){
    queue->front = (queue->front+1)%queue->capacity;
    return queue->array[queue->front];
}

void printQueue(ArrayQueue queue){
    printf("<<<");
    int i = queue->front;
    do{
        i = (i+1)%queue->capacity;
        printf("%d ", queue->array[i]);
    }while(i != queue->rear);
    printf("<<<\n");
}

int main() {
//    struct Queue queue;
//    initQueue(&queue);
//    for (int i = 1; i<5; i++){
//        offerQueue(&queue, i*100);
//    }
//    printQueue(&queue);
//    while(!isEmpty(&queue)){
//        printf("%d ", pollQueue(&queue));
//    }
    struct Queue_list queuel;
    initQueue_list(&queuel);

    for(int i = 1; i < 5; i++){
        offerQueue_list(&queuel, i*100);
    }
    printQueue_list(&queuel);
    while(!isEmpty_list(&queuel)){
        printf("%d ", pollQueue_list(&queuel));
    }

    return 0;
}

