#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
}DlistNdoe;

void init(DlistNdoe* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert_node(DlistNdoe* before, element data) {
    DlistNdoe* newnode = (DlistNdoe*)malloc(sizeof(DlistNdoe));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

/* 과제 - 이중 연결 리스트 (7/9(일) -> 음악 재생 프로그램 만들기)
    0. 초기
    1. 수업시간에 그려주신 상태 (0이 들어간 노드 상태)
    2. 1이 들어간 노드 상태 그리기
    3. 2가 들어간 노드 상태 그리기
*/

int main() {
    DlistNode* head = (DlistNdoe*)malloc(sizeof(DlistNdoe));
    init(head);
    for(int i = 0; i < 5; i++) {
        dinsert_node(head, i);
    }
}