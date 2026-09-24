struct Node *findMin(struct Node *root) {
    struct Node *current = root;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Node *deleteNode(struct Node *root, int value) {

    // Value not found
    if (root == NULL) {
        return root;
    }

    // Search in left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    // Node found
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node *temp = findMin(root->right);

            // Copy successor's value
            root->data = temp->data;

            // Delete successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}
