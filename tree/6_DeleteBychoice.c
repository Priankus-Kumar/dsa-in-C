struct Node *findMin(struct Node *root) {
    struct Node *current = root;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Node *deleteNode(struct Node *root, int value) {

    // Agar value nahi mila toh root return karo
    if (root == NULL) {
        return root;
    }

    // Agar value chhoti hai toh left subtree mein dhundho
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    // Agar value badi hai toh right subtree mein dhundho
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    // Node mil gaya - ab delete karo
    else {
        // Case 1: Koi child nahi hai (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Sirf right child hai
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Sirf left child hai
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Dono children hain
        else {
            struct Node *temp = findMin(root->right);

            // Successor ka value copy karo
            root->data = temp->data;

            // Successor ko delete karo
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}
