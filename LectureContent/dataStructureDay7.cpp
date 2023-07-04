#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; 
	int expon; 
	struct ListNode* link; 
}ListNode;

typedef struct ListType {
	int size; 
	ListNode* head; 
	ListNode* tail; 
}ListType;

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType)); //공간먼저할당
	plist->size = 0; 
	plist->head = NULL; 
	plist->tail = NULL;
	return plist; 
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); //공간먼저할당 
	temp->coef = coef; 
	temp->expon = expon; 
	temp->link = NULL; 

	if (plist->tail == NULL) { 
		plist->head = plist->tail = temp; //head, tail 둘 다 변경 
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head; 
	ListNode* b = plist2->head; 
	int sum;
	while (a!=NULL && b!=NULL) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef; 
			if(sum!=0)insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon < b->expon) {
			insert_last(plist3, b->coef, b->expon);
			b = b->link; //b만 보내야해서...!
		}
		else {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
	}//end while

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon); 
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head; 
	for (; p; p = p->link) {
		printf("%dx^%d+", p->coef, p->expon); 
	}
	printf("\n"); 
}

int main() {
	ListType* list1, * list2, * list3; 

	list1 = create(); 
	list2 = create(); 
	list3 = create(); 

	//여기부터 안 나옴
	insert_last(list1, 3, 12); 
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 10);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_add(list1, list2, list3); 
	poly_print(list3); 
}