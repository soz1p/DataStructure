#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200 /*최대 히프 크기 +1*/
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct element{
  int key;
}element;

element heap[MAX_ELEMENTS];
int n=0;

void push(element item, int *n)
{
  int i;
  if(HEAP_FULL(*n)){
    fprintf(stderr, "The heap is full. \n");
    exit(EXIT_FAILURE);
  }
  i = ++(*n);
  while ((i != 1) && (item.key > heap[i/2].key)){
    heap[i] = heap[i/2];
    i /= 2;
  }
  heap[i] = item;
}
int main()
{
    struct element node1 = {23};
    struct element node2 = {54};
    struct element node3 = {3};
    struct element node4 = {27};
    struct element node5 = {21};
    struct element node6 = {8};
    struct element node7 = {99};
    struct element node8 = {34};
    push(node1, &n);
    push(node2, &n);
    push(node3, &n);
    push(node4, &n);
    push(node5, &n);
    push(node6, &n);
    push(node7, &n);
    

    for(int k=1;k<10;k++){
        printf("%d ",heap[k].key);
    }
    return 0;
}
