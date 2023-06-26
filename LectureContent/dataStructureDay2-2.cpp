#include <stdio.h>	

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}

int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check!
	if (is_full(s)) {
		printf("스택 포화 에러");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	//underflow check!
	if (is_empty(s)) {
		printf("저장 공간이 부족합니다!");
	}
	else {
		element item = s->data[s->top--];
		return item;
	}
}

int main() {
	StackType s;

	init(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	for (int i = 0; i <= s.top; i++) {
		printf("%3d \n", s.data[i]);
	}
	printf("\n");

	element item = pop(&s);
	printf("pop value=%d\n", item);
}