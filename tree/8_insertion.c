#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct node *insert(struct node *root, int data) {
    // If tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }
    // If data is smaller, insert in left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is larger, insert in right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder traversal
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = createNode(50);
    struct node *n1 = createNode(30);
    struct node *n2 = createNode(70);
    struct node *n3 = createNode(20);
    struct node *n4 = createNode(40);
    struct node *n5 = createNode(60);
    struct node *n6 = createNode(80);

    // Connecting existing nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;
    inorder(root);
    printf("\n");
    // Insert NEW elements into the existing BST
    root = insert(root, 10);
    root = insert(root, 35);
    root = insert(root, 65);
    root = insert(root, 90);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
