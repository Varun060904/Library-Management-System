#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct book {
    char title[100];
    char author[100];
    char genre[100];
};

// Function to print the contents of a book
void print_book(struct book *book) {
    printf("%s by %s (%s)\n", book->title, book->author, book->genre);
}

int main() {
    // Create an array to store books
    struct book library[100]; // Assuming a maximum of 100 books

    int num_books = 0; // Keep track of the number of books in the library

    while (1) {
        printf("Options:\n");
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Display all books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_books < 100) { // Check if there is room to add a new book
                    struct book new_book;
                    printf("Enter book title: ");
                    scanf(" %99s", new_book.title);
                    printf("Enter book author: ");
                    scanf(" %99s", new_book.author);
                    printf("Enter book genre: ");
                    scanf(" %99s", new_book.genre);
                    library[num_books] = new_book;
                    num_books++;
                } else {
                    printf("Library is full. Cannot add more books.\n");
                }
                break;
            }
            case 2: {
                char title[100];
                printf("Enter the title to search for: ");
                scanf(" %99s", title);
                int found = 0;
                for (int i = 0; i < num_books; i++) {
                    if (strcmp(library[i].title, title) == 0) {
                        print_book(&library[i]);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;
            }
            case 3: {
                // Display all books
                printf("\nBook List:\n");
                for (int i = 0; i < num_books; i++) {
                    print_book(&library[i]);
                }
                printf("\n");
                break;
            }
            case 4:
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
