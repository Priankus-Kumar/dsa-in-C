#include <stdio.h>
#include <stdlib.h>


// ========================================================================
// create the double linked list
// ========================================================================
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// ========================================================================
// Display Forward
// ========================================================================
void displayForward(struct Node *head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
// ========================================================================
// Display Backward
// ========================================================================
void displayBackward(struct Node *head) {
    if (head == NULL)
        return;

    while (head->next != NULL)
        head = head->next;

    printf("Backward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
	struct Node *head = NULL;

	// insertAtBeginning(&head, 20);
	// insertAtBeginning(&head, 10);
	// insertAtEnd(&head, 30);
	// insertAtEnd(&head, 40);

	displayForward(head);
// 	displayBackward(head);

	return 0;
}