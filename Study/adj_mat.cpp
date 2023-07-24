#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICS 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICS][MAX_VERTICS];
} GraphType;

void init(GraphType* g) {
    g->n = 0;
    for(int r=0; r<MAX_VERTICS; r++) {
        for(int c=0; c<MAX_VERTICS; c++) {
            g->adj_mat[r][c]=0;        
        }
    }
}

//v 받는 이유는 뭘까? -> 이유 없음
void insert_vertex(GraphType* g, int v) {
    if(((g->n) + 1) > MAX_VERTICS) {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프 : 정점 번호 오류"); //버퍼 바로 출력
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;

}

void print_adj_mat(GraphType* g) {
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType);
    init(g);

    for(int i=0; i<4; i++) {
        insert_vertex(g, i);
    }

    //무방향 그래프를 가정하고..?
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    print_adj_mat(g);

    free(g);
}