#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10

typedef char element;
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

int check_matching(const char* in) {
    StackType s;
    int n = strlen(in);
    char ch, open_ch;

    init(&s);

    //왼쪽 괄호를 만나면 스택에 push
    for(int i=0; i<n; i++) {
        ch = in[i];
        switch(ch) {
            //조건을 안주면 or과 같은 역할을 합니다
            case '(' : 
            case '{' : 
            case '[' : push(&s, ch);
            break;
            case ')' :
            case '}' :
            case ']' : 
                if(is_empty(&s)) return 0;
                else {
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') || 
                       (open_ch == '{' && ch != '}') ||
                       (open_ch == '[' && ch != ']')) {
                        return 0;
                       }
                        break;
                }
           
        }
    }
    if(!is_empty(&s)) return 0;
    return 1;
}

int main() {
    const char* p = "{A[(i+1)]=0;}"; //13개 문자 공백 포함한 14byte

    if(check_matching(p) == 1) {
        printf("%s : 괄호 검사 성공\n", p);
    }else{
        printf("%s : 괄호 검사 실패\n", p);
    }
}


