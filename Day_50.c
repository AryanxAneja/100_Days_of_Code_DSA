// Problem: BST Search
// Implement the solution for this problem.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 1);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 5);

    int key = 2;

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL) {
        printf("Value %d found in BST\n", key);
    } else {
        printf("Value %d not found in BST\n", key);
    }

    return 0;
}