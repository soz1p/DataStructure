// 자기참조 구조체란 연결 리스트
// 배열 리스트는 시험에 나오지 않는다

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode // 링크의 이름이 없으면 주소를 줄 수 없게 된다 
{   //자기 참조 구조체
    element data;
    struct ListNode* link; // struct ListNode가 아니라 ListNode는 선언되지 않았기 때문에 이름 생략 불가
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //명시적 형변환
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode* head) {
    for( ListNode* p = head; p != NULL; p = p->link) { //리스트를 출력하는 기본 코드
        printf("%d->", p->data);
    }
    printf("\n");
}

ListNode * delete_first(ListNode* head){
    ListNode* removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode * search_list(ListNode* head, element data) {
    ListNode* p = head;
    while(p != NULL) {
        if(p->data == data){ 
            return p->link;
        }
        p = p->link; 
    }
    return NULL;
}

int main() {
    ListNode* head = NULL;

    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_first(head, 30);
    head = insert_first(head, 40);
    head = insert_first(head, 50);

    print_list(head);

    head = delete_first(head);
    print_list(head);

    head = delete_first(head);
    print_list(head);

    ListNode * s = search_list(head, 20);

    //search한 아이를 삭제할 수 있는 코드를 추가해보세요
}