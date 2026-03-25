// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─── Node Definition ───────────────────────────────────────────
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ─── Helper: Create a new node ─────────────────────────────────
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// ─── Queue for BFS ─────────────────────────────────────────────
#define MAX 1000

struct Queue {
    struct TreeNode* data[MAX];
    int front, rear;
};

void initQueue(struct Queue* q)       { q->front = q->rear = 0; }
int  isEmpty(struct Queue* q)         { return q->front == q->rear; }
void enqueue(struct Queue* q, struct TreeNode* node) { q->data[q->rear++] = node; }
struct TreeNode* dequeue(struct Queue* q)            { return q->data[q->front++]; }


// ───────────────────────────────────────────────────────────────
//  BUILD TREE FROM LEVEL-ORDER
//  arr[]  : level-order values  (-1 means NULL)
//  n      : total elements in arr
// ───────────────────────────────────────────────────────────────
struct TreeNode* buildFromLevelOrder(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;                          // index into arr[]

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q);

        // ── Left Child ──────────────────────────────────────
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                enqueue(&q, curr->left);
            }
            i++;
        }

        // ── Right Child ─────────────────────────────────────
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                enqueue(&q, curr->right);
            }
            i++;
        }
    }

    return root;
}


// ─── Verify: Inorder Print ─────────────────────────────────────
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// ─── Verify: Level-Order Print ─────────────────────────────────
void levelOrder(struct TreeNode* root) {
    if (!root) return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct TreeNode* curr = dequeue(&q);
        if (curr) {
            printf("%d ", curr->val);
            enqueue(&q, curr->left);
            enqueue(&q, curr->right);
        } else {
            printf("null ");
        }
    }
}


// ─── Driver ────────────────────────────────────────────────────
int main() {
    //  Example 1:  [1, null, 2, 3]  →  represented as {1,-1,2,3}
    int arr1[] = {1, -1, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    struct TreeNode* root1 = buildFromLevelOrder(arr1, n1);
    printf("Example 1 Inorder   : "); inorder(root1);     printf("\n");
    printf("Example 1 LevelOrder: "); levelOrder(root1);  printf("\n\n");

    //  Example 2:  [1,2,3,4,5,null,8,null,null,6,7,9]
    int arr2[] = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    struct TreeNode* root2 = buildFromLevelOrder(arr2, n2);
    printf("Example 2 Inorder   : "); inorder(root2);     printf("\n");
    printf("Example 2 LevelOrder: "); levelOrder(root2);  printf("\n");

    return 0;
}