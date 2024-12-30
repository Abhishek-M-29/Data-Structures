#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insertNode(struct Node *root, int data){
    struct Node *newNode = createNode(data);
    if (root == NULL){
        root = newNode;
        return root;
    }
    if (data > root->data){
        root->left = insertNode(root->left, data);
    }
    else if (data < root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

int inorder(struct Node *root){
    if (root == NULL){
        return 0;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

int preorder(struct Node *root){
    if (root == NULL){
        return 0;
    }
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int postorder(struct Node *root){
    if (root == NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}


int main(){
    int choice, n, i, elem;
    struct Node *root = NULL;
    while (1){
        printf("\n1. Create MBST\n2. Traverse\n3. Exit"); 
        printf("\nEnter your choice:"); scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the number of elements: "); scanf("%d", &n);
                for(i=1; i<=n; i++){
                    printf("Enter element %d:", i); scanf("%d", &elem);
                    root = insertNode(root, elem);
                }
                break;
            case 2:
                printf("\nInorder Traversal :"); inorder(root);
                printf("\nPreorder Traversal 2:"); preorder(root);
                printf("\nPostorder Traversal 3:"); postorder(root);
                break;
            case 3:
                printf("\nExiting the program!");
                return 0;
            default: 
                printf("\nEnter valid input!");
                break;
        }

    }
}