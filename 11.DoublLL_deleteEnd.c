  #include<stdio.h>
  #include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void deleteEnd(struct node **head){
    struct node *ptr;
    ptr=*head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
}

  void main(){
    int n;
    printf("Enter the number of node:");
    scanf("%d",&n);

    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *current;

    for(int a=0;a<n;a++){
        current=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element:");
        scanf("%d",&current->data);

        current->next=NULL;
        current->prev=NULL;

        if(head==NULL){
            head=current;
        }else{
            temp->next=current;
            current->prev=temp;
        }
        temp=current;
    }
    deleteEnd(&head);
    traverse(head);
  }