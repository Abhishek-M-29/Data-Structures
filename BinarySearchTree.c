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
    if (root->data > data){
        root->left = insertNode(root->left, data);
    }
    else if (root->data < data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

int inorder(struct Node *root){
    if (root == NULL){
        //printf("\nTree not exist!");
        return 0;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
    //printf("%d", root->data);
}

int preorder(struct Node *root){
    if (root == NULL){
        return 0;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

int postorder(struct Node *root){
    if (root == NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

int searchNode(struct Node *root, int key){
    if (root == NULL){
        return 0;
    }
    if (root->data == key){
        return 1;
    }
    if (root->data > key){
        return searchNode(root->left, key);
    }
    if (root->data < key){ 
        return searchNode(root->right, key);
    }
}

int main(){
    int choice, n, i, val, key;
    struct Node *root = NULL;
    while (1)
    {
        printf("\nProgram of -> Abhishek M (1AY23CS006)");
        printf("\n1.Create BST\n2. Traverse BST (inorder/ preorder/ postorder)\n3. Search KEY\n4. Exit");
        printf("\n\nEnter your choice:"); scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter no. of elements you want to enter:"); scanf("%d", &n);
                for (i=1; i<=n; i++){
                    printf("\nEnter element %d:", i); scanf("%d", &val);
                    root = insertNode(root, val);
                }
                break;
            case 2:
                printf("\nInorder : "); inorder(root);
                printf("\nPreorder : "); preorder(root);
                printf("\nPostorder : "); postorder(root);
                break;
            case 3:
                printf("\nEnter value which you want to search = "); scanf("%d", &key);
                if (searchNode(root, key)){
                    printf("\nKey is found!");
                    break;
                }
                printf("\nKey not found!");
                break;
            case 4:
                printf("\nExiting the program!");
                return 0;
        }
    }
    


    /*struct Node *root = NULL;
    int data;
    root = insertNode(root, data);*/

}