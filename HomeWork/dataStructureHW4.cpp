#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef int element;
typedef struct ListNode
{
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

typedef struct ListType
{
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

ListType *create()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void insert_last(ListType *plist, int coef, int expon)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;

    if (plist->tail == NULL)
        plist->head = plist->tail = temp;
    else
    {
        plist->tail->link = temp;
        plist->tail = temp;
    }
}

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3)
{
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;

    while (a && b)
    {
        if (a->expon == b->expon)
        {
            insert_last(plist3, a->coef + b->coef, a->expon);
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon)
        {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else
        {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    for (; a != NULL; a = a->link)
        insert_last(plist3, a->coef, a->expon);
    for (; b != NULL; b = b->link)
        insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType *plist)
{
    ListNode *p = plist->head;
    for (; p; p = p->link)
    {
        printf("%dx^%d", p->coef, p->expon);
        if (p->link != NULL)
            printf(" + ");
    }
    printf("\n");
    
}

double poly_calc(ListType *plist, double x)
{
    double result = 0.0;
    ListNode *p = plist->head;

    while (p != NULL)
    {
        result += p->coef * pow(x, p->expon);
        p = p->link;
    }

    return result;
}

void clear_list(ListType *plist)
{
    ListNode *p = plist->head;
    ListNode *prev;

    while (p != NULL)
    {
        prev = p;
        p = p->link;
        free(prev);
    }

    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
}

int main()
{
    ListType *A = create();
    ListType *B = create();
    ListType *C = create();

    int choice;
    double x;

    while (1)
    {
        printf("\n다항식 계산기 메뉴\n");
        printf("1) 다항식 입력\n");
        printf("2) 다항식 C = A + B 결과 출력\n");
        printf("3) 10개의 랜덤 x에 대한 다항식 C 계산 결과 출력\n");
        printf("4) 다항식 초기화\n");
        printf("5) 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int coef, expon;
            int list_choice;

            printf("\n다항식 입력을 시작합니다.\n");
            printf("다항식 선택 (1: A, 2: B): ");
            scanf("%d", &list_choice);

            if (list_choice == 1)
            {
                printf("다항식 A 입력을 시작합니다.\n");
                printf("계수와 지수를 입력하세요. (0 0 입력 시 종료)\n");

                while (1)
                {
                    printf("계수 지수: ");
                    scanf("%d %d", &coef, &expon);
                    if (coef == 0 && expon == 0)
                        break;
                    insert_last(A, coef, expon);
                }

                printf("다항식 A: ");
                poly_print(A);
            }
            else if (list_choice == 2)
            {
                printf("다항식 B 입력을 시작합니다.\n");
                printf("계수와 지수를 입력하세요. (0 0 입력 시 종료)\n");

                while (1)
                {
                    printf("계수 지수: ");
                    scanf("%d %d", &coef, &expon);
                    if (coef == 0 && expon == 0)
                        break;
                    insert_last(B, coef, expon);
                }

                printf("다항식 B: ");
                poly_print(B);
            }
            else
            {
                printf("잘못된 다항식 선택입니다.\n");
            }

            break;
        }

        case 2:
        {
            printf("\n다항식 C = A + B 결과 출력\n");
            poly_add(A, B, C);
            printf("다항식 C: ");
            poly_print(C);
            break;
        }
        case 3:
        {
            printf("\n10개의 랜덤 x에 대한 다항식 C 계산 결과 출력\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++)
            {
                x = (double)(rand() % 10);
                printf("x = %.1lf, C = %.1lf\n", x, poly_calc(C, x));
            }
            break;
        }

        case 4 : 
        {
            printf("다항식을 초기화합니다.\n");
            clear_list(A);
            clear_list(B);
            clear_list(C);
            break;
        }

        case 5:
        {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
        default:
        {
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
            break;
        }
        }
    }

    return 0;
}
