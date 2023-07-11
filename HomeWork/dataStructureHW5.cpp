#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

DListNode* current;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead, DListNode* current) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current) {
            printf("<-| #%s# |->", p->data);
        } else {
            printf("<-| %s |-> ", p->data);
        }
    }
    printf("\n");
}


void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    strcpy(newnode->data, data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void playMusic(DListNode* head) {
    DListNode* current = head->rlink;
    int count = 0;

    printf("재생할 음악의 번호를 입력하세요: ");
    scanf("%d", &count);

    for (int i = 1; i < count; i++) {
        current = current->rlink;
        if (current == head)
            current = current->rlink;
    }

    if (current != head) {
        printf("음악 재생 중: %s\n", current->data);
        print_dlist(head, current); // 현재 재생 중인 노드를 표시
    } else {
        printf("해당하는 음악을 찾을 수 없습니다.\n");
    }
}

int main() {
    char ch;
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    do {
        printf("\n------ MP3 플레이어 메뉴 ------\n");
        printf("1. 음악 추가\n");
        printf("2. 음악 삭제\n");
        printf("3. 음악 재생\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf(" %c", &ch);
        getchar(); // 개행 문자 제거

        switch (ch) {
            case '0':
                printf("프로그램을 종료합니다.\n");
                break;
            case '1': {
                element newSong;
                printf("추가할 음악의 제목을 입력하세요: ");
                fgets(newSong, sizeof(newSong), stdin);
                newSong[strcspn(newSong, "\n")] = '\0'; // 개행 문자 제거
                dinsert(head, newSong);
                break;
            }
            case '2': {
                element removeSong;
                printf("삭제할 음악의 제목을 입력하세요: ");
                fgets(removeSong, sizeof(removeSong), stdin);
                removeSong[strcspn(removeSong, "\n")] = '\0'; // 개행 문자 제거

                DListNode* current = head->rlink;
                while (current != head) {
                    if (strcmp(current->data, removeSong) == 0) {
                        ddelete(head, current);
                        printf("음악이 삭제되었습니다.\n");
                        break;
                    }
                    current = current->rlink;
                }

                if (current == head) {
                    printf("해당하는 음악을 찾을 수 없습니다.\n");
                }
                break;
            }
            case '3':
                printf("음악을 재생합니다.\n");
                playMusic(head);
                break;
            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
                break;
        }

    } while (ch != '0');

    return 0;
}
