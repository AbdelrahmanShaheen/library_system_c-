#include <string>
#include <vector>

using namespace std;

struct user {
    //data :
    string userName;
    int userId;
    vector<int> booksBorrowed;
    //methods :
    void print_user_info(); // ..\print_users() in library_system.h

    void add_borrowed_book(int);//used in user_borrow_book() in in library_system.h.

    void remove_borrowed_book(int);//used in user_return_book() in library_system.h when return a book to library.
};