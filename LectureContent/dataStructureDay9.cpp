#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element data;
    struct StackNode * link;
}StackNode;

typedef struct {
    StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {
    s->top = NULL;
}

void push(LinkedStackType* s, element item) {
    //배열을 이용한 단순 연결리스트와의 차이점->overflow check를 따로 진행하지 않음
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

void print_stack(LinkedStackType* s) {
    for(StackNode* p = s->top; p; p = p->link ) {
        printf("%d->", p->data);
    }
    printf("\n");
}

int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}

element pop(LinkedStackType* s) {
    //underflow check는 진행시켜야 함
    if(is_empty(s)) {
        printf("스택이 비어 있음\n");
        exit(1);
    }
    StackNode* temp = s->top;
    element data = s->top->data; // temp->data도 가능하다
    s->top = s->top->link;
    return data;
    free(temp);
}

int main() {
    LinkedStackType s;
    init(&s);
    push(&s, 10);
    print_stack(&s);
    push(&s, 20);
    print_stack(&s);
    push(&s, 30);
    print_stack(&s);

    element item = pop(&s);
    printf("pop value=%d\n", item);
    print_stack(&s);
}