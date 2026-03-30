// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root, int* result, int* size) {
    if (root == NULL) return;
    inorder(root->left, result, size);
    result[(*size)++] = root->val;
    inorder(root->right, result, size);
}

void preorder(struct TreeNode* root, int* result, int* size) {
    if (root == NULL) return;
    result[(*size)++] = root->val;
    preorder(root->left, result, size);
    preorder(root->right, result, size);
}

void postorder(struct TreeNode* root, int* result, int* size) {
    if (root == NULL) return;
    postorder(root->left, result, size);
    postorder(root->right, result, size);
    result[(*size)++] = root->val;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    struct TreeNode* root = newNode(1);
    root->left           = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right    = newNode(5);

    int result[100];
    int size = 0;

    size = 0;
    preorder(root, result, &size);
    printf("Preorder:  ");
    printArray(result, size);

    size = 0;
    inorder(root, result, &size);
    printf("Inorder:   ");
    printArray(result, size);

    size = 0;
    postorder(root, result, &size);
    printf("Postorder: ");
    printArray(result, size);

    freeTree(root);
    return 0;
}