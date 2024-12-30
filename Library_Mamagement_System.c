#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    char title[100];
    char author[50];
    int isbn;
    struct Book *next;
};

void addBook(struct Book **head){
    struct Book *new = (struct Book *) malloc(sizeof(struct Book));
    if (!new){
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter book title: "); scanf(" %[^\n]s", new->title);
    printf("Enter book author: "); scanf(" %[^\n]s", new->author);
    printf("Enter book ISBN: "); scanf("%d", &new->isbn);
    new->next = *head;
    *head = new;
    printf("The book '%s' is added to the library!", new->title);
}

void deleteBook(struct Book **head, int isbn) {
    struct Book *temp = *head, *prev = NULL;
    while (temp != NULL && temp->isbn != isbn) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("No book found with ISBN %d.\n", isbn);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } 
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Book with ISBN %d has been removed from the library.\n", isbn);
}

void searchByTitle(struct Book *head, const char *title) {
    struct Book *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(title, temp->title) == 0) {
            printf("Found book: '%s' by '%s' (ISBN: %d)\n", temp->title, temp->author, temp->isbn);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No book found with the title '%s'.\n", title);
    }
}

void displayBooks(struct Book *head) {
    if (head == NULL) {
        printf("The library is empty.\n");
        return;
    }
    struct Book *temp = head;
    printf("Books in the library:\n");
    while (temp != NULL) {
        printf("\nTitle: %s\nAuthor: %s\nISBN: %d\n", temp->title, temp->author, temp->isbn);
        temp = temp->next;
    }
}

int main(){
    struct Book *library = NULL;
    int choice, isbn;
    char title[100];

    while (1){
        printf("\n\t\tLIBRARY MANAGEMENT SYSTEM\n");
        printf("\n1. Add a book\n2. Delete a book\n3. Search book\
        \n4. Display all books\n5. Exit\n Enter your choice:");
        scanf("%d", &choice);

        switch (choice){
            case 1: addBook(&library); break;
            case 2: printf("Enter ISBN of the book to delete: ");
            scanf("%d", &isbn);
            deleteBook(&library, isbn);
            break;
            case 3: printf("Enter the book title to search:");
            scanf(" %[^\n]s", title);
            searchByTitle(library, title);
            break;
            case 4: displayBooks(library); break;
            case 5: printf("Exiting the system. All the datas will be cleared.\n");
            exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}