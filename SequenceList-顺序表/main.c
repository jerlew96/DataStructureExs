 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

//按位序来算

struct List{
    E * array;
    int capacity;
    int size;
};

typedef struct List * ArrayList;

bool initList(ArrayList list){
    list->array = malloc(sizeof(E)*10);
    if(list->array == NULL){
        return 0;
    }
    list->capacity = 10;
    list->size = 0;
    return 1;
}

bool insertList(ArrayList list, E element, int index){
    if(index<1 || index > list->size+1){
        return 0;
    }

    if(list->size>=list->capacity){
        int newCapacity = list->capacity + (list->capacity>>1);
        E* newArray = realloc(list->array, newCapacity*sizeof(E));
        if(newArray == NULL){
            return 0;
        }
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for(int i = list->size; i>=index; i-- ){
        list->array[i] = list->array[i-1];
    }
    list->array[index-1] = element;
    list->size++;
    return 1;
}

bool deleteList(ArrayList list, int index){
    if(index<1 || index>list->size){
        return 0;
    }
    for(int i = index-1; i <= list->size-1; i++){
        list->array[i] = list->array[i+1];
    }
    list->size--;
    return 1;

}

int getSize(ArrayList list){
    return list->size;
}

E* getElementAdress(ArrayList list, int index){
    if(index<1 || index>list->size){
        return NULL;
    }
    return &list->array[index-1];
}

int findElement(ArrayList list, E ele){
    for(int i = 0; i!=list->size; i++) {
        if (list->array[i] == ele) {
            return i + 1;
        }
    }
    return -1;
}

void printList(ArrayList list){
    for (int i = 0; i<list->size; i++){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}

int main() {
    struct List list;
    if(initList(&list)){
//        insertList(&list, 666, 1);
//        printList((&list));
//        insertList(&list, 777, 1);
//        printList((&list));
//        insertList(&list, 888, 2);
//        printList((&list));
    for(int i = 0; i!=30; i++){
        insertList(&list, i*10, i+1);
    }
    printList(&list);
    deleteList(&list, 4);
    printList(&list);
//    printf("%d", *getElementAdress(&list, 50));
    printf("%d", findElement(&list, 100));

    }else{
        printf("顺序表初始化失败,无法启动");
    }


    return 0;
}

