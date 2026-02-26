/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
    struct ListNode* prev;
};
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
struct ListNode* insertAtEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    if (head == NULL) {
        return newNode;
    }
    
    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    
    return head;
}
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
int main() {
    int n, val;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    
    struct ListNode* head = NULL;
    printf("Enter the values of the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertAtEnd(head, val);
    }
    
    printf("Linked list elements in forward order: ");
    printList(head);
    
    return 0;
}
