#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create(){
    int x;
    struct Node *temp;
    temp = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter value for node(-1 for no node): "); scanf("%d", &x);
    if (x==-1){
        return NULL;
    }
    temp->data = x;
    printf("Enter left child of %d node: ", x);
    temp->left = create();
    printf("Enter right child of %d node: ", x);
    temp->right = create();

    return temp;
}

int inorder(struct Node* root){ // left - root - right
    if (root == NULL){
        //printf("No Tree exists!");
        return 0;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
    printf("%d", root->data);

}

int preorder(struct Ndde* root){ // root - left - right
    if (root == NULL){
        return 0;
    }
}

int main(){

    struct Node *root;
    root = create();
}
