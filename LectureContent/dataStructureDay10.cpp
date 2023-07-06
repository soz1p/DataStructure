#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNdoe;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return(q->front == NULL);
}

void enqueue(LinkedQueueType* q, element value) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = value;
	temp->link = NULL;
	
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

void print_queue(LinkedQueueType* q) {
	for (QueueNode* p = q->front; p; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}

element dequeue(LinkedQueueType* q) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp = q->front;
	element data;
	//underflow check!!
	if (is_empty(q)) {
		printf("Queue is empty!");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		//아주 중요한 코드
		if (q->front == NULL) { //이 경우는 하나 남은 노드를 삭제한 경우이기 때문
			q->rear = NULL;
		}
		return data;
	}
	free(temp);
}

int main() {
	LinkedQueueType queue;
	init(&queue);
	enqueue(&queue, 10);
	print_queue(&queue);
	enqueue(&queue, 20);
	print_queue(&queue);
	enqueue(&queue, 30);
	print_queue(&queue);

	element item = dequeue(&queue);
	printf("삭제된 변수 = %d\n", item);
	print_queue(&queue);
}
