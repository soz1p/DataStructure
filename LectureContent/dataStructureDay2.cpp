//배열 - 같은 자료형에 대한 데이터의 연속적인 저장 구조
//구조체 - 같은 자료형 또는 서로다른 자료형에 대한 데이터의 연속적인 저장 구조

#include <stdio.h>

struct student {
    char code;
    int num;
};

int main() {
    //선언문, 메모리를 요청하여 할당 받음
    struct student stu; // stu = 구조체 변수
    
    stu.code = '7'; //멤버 호출
    stu.num = 2191193;

    printf("%c\n", stu.code);
    printf("%d\n", stu.num);

    printf("구조체의 크기 = %d\n", sizeof(stu));

    //구조체와 포인터
    //포인터 변수의 선언
    struct student *ptr = &stu;

    ptr->code = '2';
    ptr->num = 123456;

    printf("%c\n", ptr->code);
    printf("%d\n", ptr->num);
}