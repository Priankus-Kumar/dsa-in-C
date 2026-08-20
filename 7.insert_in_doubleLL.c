// =============================================================
// insert and begining
// =============================================================
void insertAtBeginning(struct Node **head, int data) {   
    //**head ->> means change the actual head pointer when inserting the new node
    struct Node *newNode = createNode(data);

    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// =============================================================
// insert and end
// =============================================================
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


int main() {
	struct Node *head = NULL;

	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 10);
	insertAtEnd(&head, 30);
	insertAtEnd(&head, 40);

	displayForward(head);
	displayBackward(head);

	return 0;
}