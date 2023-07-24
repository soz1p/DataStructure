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

//item 받는 이유는 뭘까?
void insert_vertex(GraphType* g) {
    if(((g->n) + 1) > MAX_VERTICS) {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

int main() {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);

    for(int i=0; i<51; i++) {
        insert_vertex(g);
    }
}