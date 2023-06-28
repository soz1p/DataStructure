#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10

typedef char element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    element top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_full(StackType *s)
{
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item)
{
    if (is_full(s))
    {
        printf("스택 포화 에러(overflow error)");
        return;
    }
    else
    {
        s->data[++(s->top)] = item;
    }
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        printf("스택 공백 에러(underflow error)");
        exit(1); // stdlib.h
    }
    else
    {
        return s->data[(s->top)--];
    }
}

element peek(StackType *s)
{
    if (is_empty(s))
    {
        printf("스택 공백 에러(underflow error)");
        exit(1); // stdlib.h
    }
    else
    {
        return s->data[(s->top)];
    }
}

int prec(char op)
{
    switch (op)
    {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(const char exp[])
{
    char ch, top_op;
    int len = strlen(exp);

    StackType s;
    init_stack(&s);

    for (int i = 0; i < len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
            case '+': case '-': case '*': case '/':
                // 우선순위 판단해서 push
                while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                {
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while (top_op != '(')
                {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }

    while (!is_empty(&s))
    {
        printf("%c", pop(&s));
    }
}

int main()
{
    const char *s = "(2+3)*4+9";
    infix_to_postfix(s);

    return 0;
}
