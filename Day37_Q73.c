/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->arr = (int*)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void insert(PriorityQueue* pq, int x) {
    if (pq->size == pq->capacity) {
        return;
    }
    pq->arr[pq->size++] = x;
}

int deleteMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1;
    }

    int minIndex = 0;

    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }

    int minValue = pq->arr[minIndex];

    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }

    pq->size--;

    return minValue;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1;
    }

    int minValue = pq->arr[0];

    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < minValue) {
            minValue = pq->arr[i];
        }
    }

    return minValue;
}

int main() {
    int N;
    scanf("%d", &N);

    PriorityQueue* pq = createPriorityQueue(N);

    for (int i = 0; i < N; i++) {
        char operation[10];
        int value;

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(pq, value);
        }
        else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", deleteMin(pq));
        }
        else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek(pq));
        }
    }

    free(pq->arr);
    free(pq);

    return 0;
}