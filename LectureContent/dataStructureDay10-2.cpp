#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNdoe;

ListNode* insert_last(ListNode* head, element data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	if (head == NULL) {
		head = temp;
		temp->data = data;
		temp->link = temp; // == head->link = temp;
	}
	else {
		temp->link = head->link;
		head->link = temp;
		//insert_frist는 이 부분만 다릅니다
		head = temp; //중요한 코드입니다
	}
	return head;
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	if (head == NULL) {
		head = temp;
		temp->data = data;
		temp->link = temp; // == head->link = temp;
	}
	else {
		temp->link = head->link;
		head->link = temp;
	}
	return head;
}

int is_empty(ListNode* head) {
	return (head == NULL);
}

void print_list(ListNode* head) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = head->link; // head로 부터 찍어버리면 맨 마지막 데이터부터 출력하기때문
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->\n", p->data);
}

int main() {
	ListNode* head = NULL;
	head = insert_last(head, 10);
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	print_list(head);
}
