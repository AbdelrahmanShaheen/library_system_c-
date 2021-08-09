#include "..\include\user.h"
#include <algorithm>
#include <iostream>

void user::print_user_info() {
    cout << "user " << userName << " id " << userId << " borrowed books ids :";
    if (booksBorrowed.empty())
        cout << "the user did not borrow any book right now\n";
    else
    {
        for (int i = 0; i < booksBorrowed.size(); i++)
        {
            cout << booksBorrowed[i] << " ";
        }
        cout << endl;
    }
}

void user::add_borrowed_book(int bookId) {
    booksBorrowed.push_back(bookId);
}

void user::remove_borrowed_book(int bookId) {
    auto position = find(booksBorrowed.begin(), booksBorrowed.end(), bookId);
    if (position != booksBorrowed.end())
        booksBorrowed.erase(position);
}
