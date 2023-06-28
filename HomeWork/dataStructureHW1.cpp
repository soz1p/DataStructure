#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_full(StackType *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("스택 포화 에러(overflow error)");
        return;
    } else {
        s->data[++(s->top)] = item;
    }
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

element pop(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 에러(underflow error)");
        exit(1); //stdlib.h
    } else {
        return s->data[(s->top)--];
    }
}

//후위 표기 수식의 계산을 위한 함수
int eval(const char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;

    StackType s;
    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        } else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    int result;
    result = eval("82/3-32*+");
    printf("결과값: %d\n", result);
}