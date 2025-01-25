#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    int publication_year;
    int identifier;
    int is_borrowed;
} Book;

typedef struct {
    char username[50];
    char password[50];
} User;

typedef struct {
    User user;
    int borrowed_books[MAX_BOOKS];
    int borrowed_count;
} Member;

typedef struct {
    User user;
    Member members[MAX_USERS];
    int member_count;
} Employee;

typedef struct {
    User user;
    Employee employees[MAX_USERS];
    Book books[MAX_BOOKS];
    int employee_count;
    int book_count;
} Admin;

Admin admin;

void init_admin() {
    strcpy(admin.user.username, "admin");
    strcpy(admin.user.password, "password");
    admin.employee_count = 0;
    admin.book_count = 0;
}

void add_employee(char *username, char *password) {
    Employee emp;
    strcpy(emp.user.username, username);
    strcpy(emp.user.password, password);
    emp.member_count = 0;
    admin.employees[admin.employee_count++] = emp;
}

void list_employees() {
    printf("Employees:\n");
    for (int i = 0; i < admin.employee_count; i++) {
        printf("- %s\n", admin.employees[i].user.username);
    }
}

void add_book(char *title, char *author, int publication_year, int identifier) {
    Book book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.publication_year = publication_year;
    book.identifier = identifier;
    book.is_borrowed = 0;
    admin.books[admin.book_count++] = book;
}

void list_books() {
    printf("Books:\n");
    for (int i = 0; i < admin.book_count; i++) {
        printf("- %s by %s (ID: %d)%s\n", admin.books[i].title, admin.books[i].author, admin.books[i].identifier, admin.books[i].is_borrowed ? " [Borrowed]" : "");
    }
}

int main() {
    init_admin();

    add_employee("employee1", "password");
    add_employee("employee2", "password");

    add_book("C Programming", "Author A", 2020, 1);
    add_book("Data Structures", "Author B", 2018, 2);

    printf("\nListing Employees:\n");
    list_employees();

    printf("\nListing Books:\n");
    list_books();

    return 0;
}

