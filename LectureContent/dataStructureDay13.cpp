#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(element value) {
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
}

TreeNode* insert_node(TreeNode* root, element key) {
    if(root == NULL) {
        return new_node(key);
    }
    if(key > root->key) {
        root->right = insert_node(root->right, key);
    }
    else if(key < root->key) {
        root->left = insert_node(root->left, key);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
}