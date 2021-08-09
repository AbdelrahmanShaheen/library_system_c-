#include <iostream>
#include "book.h"
#include "user.h"

struct library_system {
    //data :
    vector<user> users;
    vector<book> books;
    //methods :
    int menu();

    void run();

    void add_book();

    void print_library_by_id();

    void print_library_by_name();

    void search_books_by_prefix();

    void add_user();

    void print_users();

    void user_borrow_book();

    int search_book(string);

    int search_user(string);

    void print_who_borrowed_book_by_name();

    void user_return_book();
    //bool compare_id(const book &a ,const book &b);
};