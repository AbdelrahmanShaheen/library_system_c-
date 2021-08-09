#include<string>
#include <iostream>
#include <vector>

using namespace std;

struct book {
    //data :
    string bookName;
    int bookQuantity;
    int bookId;
    int borrowedCopies;
    vector<string> borrowers;
    //methods :
    book();//constructor.

    void print_book_info(); // ..\print_library_by_name() in library_system.h

    bool print_prefix(string prefix); // ..\search_books_by_prefix() in library_system.h
    //used in user_borrow_book() in in library_system.h
    void decrease_quantity_book();

    void increase_borrowed_book();

    void add_borrower(string);

    void print_borrowers(); //print those who borrowed this book
    //used in user_return_book() in library_system.h
    void remove_borrower(string);

    void decrease_borrowed_book();

    void increase_quantity_book();
};