#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9
typedef struct Element{
    int key;
}* Element;

typedef struct HashTable{
    Element * table;
}* HashTable;

void init(HashTable hashTable){
    hashTable->table = malloc(sizeof(struct Element)*SIZE);
    for (int i = 0; i<SIZE; i++){
        hashTable->table[i] = NULL;
    }
}

int hash(int key){
    return key % SIZE;
}

void insert(HashTable hashTable, Element element){
    int hashCode = hash(element->key);
    hashTable->table[hashCode] = element;
}

bool find(HashTable hashTable, int key){
    int hashCode = hash(key);
    if(hashTable->table[hashCode] == NULL) {
        return false;
    }
    return hashTable->table[hashCode]->key == key;
}

Element create(int key){
    Element element = malloc(sizeof (struct Element));
    element->key = key;
    return element;
}
int main() {
    struct HashTable htable;
    init(&htable);

    insert(&htable, create(10));
    insert(&htable, create(7));
    insert(&htable, create(13));
    insert(&htable, create(29));

    for (int i = 0; i<SIZE; i++){
        if(htable.table[i]==NULL){
            printf("NULL");
        }else{
            printf("%d ", htable.table[i]->key);
        }

    }

    printf("%d\n", find(&htable, 1));
    printf("%d\n", find(&htable, 13));

    return 0;
}
