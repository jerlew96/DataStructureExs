#include <iostream>

class ListNode{
public:
    ListNode(){}
    ListNode * next;
    int Element;

    void init(ListNode * head){
        head->next = nullptr;
        Element = 0;
    }

    void insert(ListNode* head, int element){
        ListNode * node = new ListNode;
        node->Element = element;
        node->next = head->next;
        head->next = node;
    }

    void printElement(ListNode * head){
        ListNode * current = head->next;
        while (current){
            std::cout<<current->Element<<std::endl;
            current = current->next;
        }
    }

    void deleteElement(ListNode* head, int element){
        while(head->next != nullptr){
            if(head->next->Element == element){
                ListNode * node;
                node = head->next;
                head->next = head->next->next;
                delete node;
                if(head->next == nullptr){
                    break;
                }
            }
            head = head->next;
        }
    }
};


int main() {
    ListNode head;
    head.init(&head);
    head.insert(&head,1);
    head.insert(&head,2);
    head.insert(&head,3);

    head.deleteElement(&head, 2);
    head.printElement(&head);

    return 0;
}
