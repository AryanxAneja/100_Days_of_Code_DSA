// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);

    postorder(root);

    return 0;
}