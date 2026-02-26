/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
    struct ListNode* prev;
};
typedef struct {
    struct ListNode* head;
    struct ListNode* tail;
    int size;
} MyLinkedList;


    
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    struct ListNode* current = obj->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = obj->head;
    newNode->prev = NULL;
    
    if (obj->head != NULL) {
        obj->head->prev = newNode;
    } else {
        obj->tail = newNode;
    }
    
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = obj->tail;
    
    if (obj->tail != NULL) {
        obj->tail->next = newNode;
    } else {
        obj->head = newNode;
    }
    
    obj->tail = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        return;
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    
    struct ListNode* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    current->next->prev = newNode;
    current->next = newNode;
    
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }
    
    struct ListNode* current = obj->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        obj->head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        obj->tail = current->prev;
    }
    
    free(current);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode* current = obj->head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}

int main() {
    MyLinkedList* myLinkedList = myLinkedListCreate();
    myLinkedListAddAtHead(myLinkedList, 1);
    myLinkedListAddAtTail(myLinkedList, 3);
    myLinkedListAddAtIndex(myLinkedList, 1, 2); 
    printf("%d\n", myLinkedListGet(myLinkedList, 1)); 
    myLinkedListDeleteAtIndex(myLinkedList, 1); 
    printf("%d\n", myLinkedListGet(myLinkedList, 1)); 
    
    myLinkedListFree(myLinkedList);
    return 0;
}