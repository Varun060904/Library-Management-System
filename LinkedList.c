#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct book {
    char title[100];
    char author[100];
    char genre[100];
};

// Structure to represent a linked list node
struct node {
    struct book book;
    struct node *next;
};

// Function to create a new node
struct node *create_node(struct book book) {
    struct node *node = malloc(sizeof(struct node));
    node->book = book;
    node->next = NULL;
    return node;
}

// Function to insert a book at the beginning of a linked list
void insert_at_beginning(struct node **head, struct book book) {
    struct node *new_node = create_node(book);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the contents of a linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%s by %s (%s)\n", head->book.title, head->book.author, head->book.genre);
        head = head->next;
    }
}

// Function to search for a book in a linked list
struct node *search(struct node *head, char *title) {
    while (head != NULL) {
        if (strcmp(head->book.title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to delete a book from a linked list
void delete(struct node **head, char *title) {
    struct node *prev = NULL;
    struct node *current = *head;
    while (current != NULL) {
        if (strcmp(current->book.title, title) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    // Create a linked list
    struct node *head = NULL;

    while (1) {
        printf("Options:\n");
        printf("1. Insert a book\n");
        printf("2. Search for a book\n");
        printf("3. Delete a book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct book new_book;
                printf("Enter book title: ");
                scanf(" %99s", new_book.title);
                printf("Enter book author: ");
                scanf(" %99s", new_book.author);
                printf("Enter book genre: ");
                scanf(" %99s", new_book.genre);
                insert_at_beginning(&head, new_book);
                break;
            }
            case 2: {
                char title[100];
                printf("Enter the title to search for: ");
                scanf(" %99s", title);
                struct node *found = search(head, title);
                if (found != NULL) {
                    printf("Found \"%s\" by %s (%s)\n", found->book.title, found->book.author, found->book.genre);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 3: {
                char title[100];
                printf("Enter the title to delete: ");
                scanf(" %99s", title);
                delete(&head, title);
                break;
            }
            case 4: {
                // Display all books
                printf("\nBook List:\n");
                print_list(head);
                printf("\n");
                break;
            }
            case 5:
                // Free the memory and exit the program
                while (head != NULL) {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
