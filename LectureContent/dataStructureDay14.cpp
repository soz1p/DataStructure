#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode * new_node(int item) {
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode * insert_node(TreeNode* node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key); 
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    return node;
}

//오른쪽 서브트리에서 가장 작은 값을 찾는 함수
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node;

    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
    if(root == NULL) return root;

    if(key < root->key)
        root->left = delete_node(root->left, key);
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
    //자식 노드가 두개인 경우 -> 오른쪽에서 가장 작은 값을 가져오는 방법
    TreeNode* temp = min_value_node(root->right);

    root->key = temp->key;
    root->right = delete_node(root->right, temp->key); 
    }
return root;
}

void inorder(TreeNode* node) {
    if(node != NULL) {
        inorder(node->left);
        printf("%3d", node->key);
        inorder(node->right);
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
    root = insert_node(root, 35);

    //중위 순회 - 숫자가 오름차순임.
    inorder(root);
    printf("\n");
    root = delete_node(root, 30);
    inorder(root);
}