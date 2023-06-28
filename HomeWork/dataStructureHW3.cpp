#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (s->capacity - 1));
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else
        return s->data[(s->top)--];
}

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE];

void generate_maze() {
    // 미로 초기화
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == 0 || i == MAZE_SIZE - 1 || j == 0 || j == MAZE_SIZE - 1) {
                maze[i][j] = '1'; // 사방은 벽으로 설정
            } else {
                maze[i][j] = '0'; // 내부는 이동 가능한 위치로 설정
            }
        }
    }

    // 랜덤한 벽 생성
    srand(time(NULL));
    for (int i = 1; i < MAZE_SIZE - 1; i++) {
        for (int j = 1; j < MAZE_SIZE - 1; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                if (rand() % 2 == 0) {
                    maze[i][j] = '1'; // 벽 생성
                }
            }
        }
    }

    // 시작점과 도착점 설정
    maze[1][0] = 'e'; // 시작점
    maze[MAZE_SIZE - 2][MAZE_SIZE - 1] = 'x'; // 도착점
}

//gpt에 도움을 받아 처리
void maze_print_with_path(char maze[MAZE_SIZE][MAZE_SIZE], int x, int y, StackType *s) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            if (maze[r][c] == '.')
                printf("•\t");  // 현재 경로 표시를 위해 변경된 출력 문자
            else
                printf("%c\t", maze[r][c]);
        }
        printf("\n");
    }
    printf("Current Position: (%d, %d)\n", x, y);
    printf("Path: ");
    for (int i = 0; i <= s->top; i++) {
        printf("(%d, %d) ", s->data[i].c, s->data[i].r);
    }
    printf("\n");
}

void push_loc(StackType *s, int r, int c) {
if (r < 0 || c < 0) return;
if (maze[r][c] != '1' && maze[r][c] != '.') {
element tmp;
tmp.r = r;
tmp.c = c;
push(s, tmp);
}
}

int main(void) {
    int r, c;
    StackType s;

    init_stack(&s);
    generate_maze(); // 미로 생성

    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print_with_path(maze, c, r, &s); // 현재 위치의 x, y 좌표를 숫자로 출력
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        if (is_empty(&s)) {
            printf("실패\n");
            return 0;
        } else
            here = pop(&s);
    }
    printf("도착 좌표: (%d, %d)\n", here.c, here.r);
    return 0;
}
