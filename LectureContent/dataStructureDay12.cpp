#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};

TreeNode* root = &n6;

// 15 4 1 20 16 25 -> 전위 순회
void preorder(TreeNode* root) { //전위 순회
    if(root !=  NULL) {
        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 1 4 15 16 20 25 -> 중위 순회
void inorder(TreeNode* root) { //중위 순회
    if(root != NULL) {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}

// 1 4 16 25 20 15 -> 후위 순회
void postorder(TreeNode* root) { //후위 순회
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}

int main() {
    printf(" +++ 전위 순회 +++ \n");
    preorder(root);
    printf("\n");
    printf(" +++ 중위 순회 +++ \n");
    inorder(root);
    printf("\n");
    printf(" +++ 후위 순회 +++ \n");
    postorder(root);
    printf("\n");
}