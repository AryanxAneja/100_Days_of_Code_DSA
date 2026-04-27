// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

int search(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (arr[i] == val)
            return i;
    return -1;
}

struct Node* build(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = postorder[*postIndex];
    (*postIndex)--;

    if (inStart == inEnd) {
        node->left = node->right = NULL;
        return node;
    }

    int idx = search(inorder, inStart, inEnd, node->val);

    node->right = build(inorder, postorder, idx + 1, inEnd, postIndex);
    node->left = build(inorder, postorder, inStart, idx - 1, postIndex);

    return node;
}

void preorder(struct Node* root) {
    if (!root)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);
    return 0;
}