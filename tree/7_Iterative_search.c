#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

struct node *searchIter(struct node *root,int data){
    while(root!=NULL){
        if(data==root->data){
            return root;
        }else if(data<root->data){
           root=root->left;
        }else{
            root=root->right;
        }
    }
    return NULL;
}

int main(){
    printf("Iterative search in binary tree\n");
    struct node *root = createNode(50);
    struct node *n1 = createNode(30);
    struct node *n2 = createNode(70);
    struct node *n3 = createNode(20);
    struct node *n4 = createNode(40);
    struct node *n5 = createNode(60);
    struct node *n6 = createNode(80);

    // Connecting nodes to form BST
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    inorder(root);
    printf("\n");
    int data;
    printf("Enter the data to search: ");
    scanf("%d", &data);

      if(searchIter(root, data)){
        printf("%d found in the tree.\n", data);
    }
    else{
        printf("%d not found in the tree.\n", data);
    }
    return 0;
}