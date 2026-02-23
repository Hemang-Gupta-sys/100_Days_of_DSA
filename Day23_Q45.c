/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;    
}
int main() {
    int n, m, arr1[100], arr2[100];
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the first linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter the elements of the second linked list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* current;

    for (int i = n - 1; i >= 0; i--) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr1[i];
        newNode->next = l1;
        l1 = newNode;
    }

    for (int i = m - 1; i >= 0; i--) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr2[i];
        newNode->next = l2;
        l2 = newNode;
    }

    struct ListNode* mergedHead = mergeTwoLists(l1, l2);
    
    printf("Merged linked list: ");
    current = mergedHead;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}
