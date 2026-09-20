#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void deleteTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main(void) {
    struct Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    printf("Tree is ready to be deleted.\n");
    deleteTree(root);
    printf("Tree deleted successfully.\n");

    return 0;
}


