#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left, * right;
} TreeNode;

// 전역 변수로 이진탐색트리의 루트 노드 선언
TreeNode* root = NULL;

// 이진탐색트리에 노드 삽입
TreeNode* insertNode(TreeNode* node, int value) {
    if (node == NULL) {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node->data = value;
        node->left = node->right = NULL;
    }
    else if (value < node->data) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// 이진탐색트리 중위 순회
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}

// 이진탐색트리의 노드 수 계산
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// 이진탐색트리의 단말노드 수 계산
int countLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

// 이진탐색트리의 높이 계산
int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n");
        printf("------ 이진탐색트리 연산 메뉴 ------\n");
        printf("1. 노드 삽입\n");
        printf("2. 중위 순회\n");
        printf("3. 트리의 총 노드 수\n");
        printf("4. 트리의 단말노드 수\n");
        printf("5. 트리의 높이\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("프로그램을 종료합니다.\n");
            return 0;
        case 1:
            printf("삽입할 값을 입력하세요: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("중위 순회 결과: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("트리의 총 노드 수: %d\n", countNodes(root));
            break;
        case 4:
            printf("트리의 단말노드 수: %d\n", countLeaves(root));
            break;
        case 5:
            printf("트리의 높이: %d\n", getHeight(root));
            break;
        default:
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}
