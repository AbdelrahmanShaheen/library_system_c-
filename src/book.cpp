#include "..\include\book.h"
#include <algorithm>

book::book() {
   borrowedCopies = 0;
}

void book::print_book_info() {
    cout<<"id = "<<bookId<<" name = "<<bookName<<" total_quantity = "<<bookQuantity<<" total_borrowed = "<<borrowedCopies<<endl;
}

bool book::print_prefix(string prefix) {
    if(prefix.size() > bookName.size())
        return false;
    for (int i = 0; i < prefix.size(); i++) {
          if(bookName[i] != prefix[i])
          {
              return false;
          }
    }
    cout<<bookName<<endl;
    return true;
}

void book::decrease_quantity_book() {
    bookQuantity--;
}

void book::increase_borrowed_book() {
   borrowedCopies++;
}

void book::add_borrower(string borrower) {
 borrowers.push_back(borrower);
}

void book::print_borrowers() {

  if(borrowers.empty())
  {
      cout<<"There are no borrowers to this book yet\n";
      return;
  }
  for(int i = 0 ;i<borrowedCopies ;i++)
  {
      cout<<borrowers[i]<<endl;
  }
}

void book::remove_borrower(string borrower) {
    auto position = find(borrowers.begin() ,borrowers.end() ,borrower);
    if(position != borrowers.end())
    borrowers.erase(position);
}

void book::decrease_borrowed_book() {
    borrowedCopies--;
}

void book::increase_quantity_book() {
    bookQuantity++;
}
