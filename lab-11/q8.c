#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "books.txt"

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);

    fwrite(&book, sizeof(book), 1, file);
    fclose(file);
    printf("Book added successfully.\n");
}

void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    printf("ID\tTitle\t\tAuthor\t\tQuantity\tPrice\n");
    while (fread(&book, sizeof(book), 1, file)) {
        printf("%d\t%s\t\t%s\t\t%d\t\t%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    int searchID;
    char searchTitle[100];
    printf("Enter Book ID or Title to search (Enter 0 to skip ID): ");
    scanf("%d", &searchID);
    if (searchID == 0) {
        printf("Enter Title: ");
        scanf(" %[^\n]", searchTitle);
    }

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.id == searchID || (searchID == 0 && strcmp(book.title, searchTitle) == 0)) {
            printf("Book found: ID=%d, Title=%s, Author=%s, Quantity=%d, Price=%.2f\n",
                   book.id, book.title, book.author, book.quantity, book.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void updateBook() {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    int updateID;
    printf("Enter Book ID to update: ");
    scanf("%d", &updateID);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.id == updateID) {
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new Price: ");
            scanf("%f", &book.price);
            found = 1;
        }
        fwrite(&book, sizeof(book), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Book updated successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void deleteBook() {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    int deleteID;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteID);

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(book), 1, file)) {
        if (book.id == deleteID) {
            found = 1;
        } else {
            fwrite(&book, sizeof(book), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void calculateInventoryValue() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    float totalValue = 0;

    while (fread(&book, sizeof(book), 1, file)) {
        totalValue += book.quantity * book.price;
    }

    fclose(file);
    printf("Total inventory value: %.2f\n", totalValue);
}

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Calculate Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: calculateInventoryValue(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
