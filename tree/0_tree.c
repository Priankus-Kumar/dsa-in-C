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
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        printf("Duplicate value %d ignored.\n", value);
    }

    return root;
}

int main(void) {
    struct Node *root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        root = insertNode(root, values[i]);
    }

    return 0;
}
