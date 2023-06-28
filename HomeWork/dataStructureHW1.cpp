#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct 
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;

}QueueType;

void init_queue(QueueType* q) {
    q->rear = 0;
    q->front = 0;
}

int is_full(QueueType* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType* q, element num){
    //OverFlow check!!
    if(is_full(q)){
        printf("큐가 포화상태입니다\n");
    }
    q->rear = (q-> rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = num;
}

int is_empty(QueueType* q) {
    return q->front == q->rear;
}

void print_queue(QueueType* q) {
    printf("QUEUE(front=%d, rear=%d) : " , q->front, q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("[%d]", q->data[i]);
            if(i == q->rear)
            break;
        }while(i != q->front);
    }
    printf("\n");
}

element dequeue(QueueType* q){
    if(is_empty(q)) {
        printf("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main() {
    QueueType queue;
    init_queue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    print_queue(&queue);

    element temp = dequeue(&queue);
    printf("꺼내진 정수 : %d\n", temp);
    print_queue(&queue);
}