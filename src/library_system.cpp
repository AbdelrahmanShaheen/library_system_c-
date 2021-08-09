#include "..\include\library_system.h"
#include <algorithm>
int library_system::menu() {
   cout<<"Library Menu :\n";
   cout<<"1) add book\n";
   cout<<"2) search_books_by_prefix\n";
   cout<<"3) print_who_borrowed_book_by_name\n";
   cout<<"4) print_library_by_id\n";
   cout<<"5) print_library_by_name\n";
   cout<<"6) add_user\n";
   cout<<"7) user_borrow_book\n";
   cout<<"8) user_return_book\n";
   cout<<"9) print_users\n";
   cout<<"10) Exit\n";
   cout<<"\nEnter your menu choice [1 - 10] :";
   int choice;
   cin>>choice;
   while (choice > 10 || choice < 1) //check validation of choice.
   {
       cout<<"Invalid choice\n";
       cout<<"\nEnter your menu choice [1 - 10] :";
       cin>>choice;
   }
   return choice;
}

void library_system::run() {

    while (true)
    {
       int choice = menu();
        //run your choice.
       if(choice == 1)
       {
           add_book();
       }
       else if(choice == 2)
       {
           search_books_by_prefix();
       }
       else if(choice == 3)
       {
           print_who_borrowed_book_by_name();
       }
       else if(choice == 4)
       {
           print_library_by_id();
       }
       else if(choice == 5)
       {
           print_library_by_name();
       }
       else if(choice == 6)
       {
           add_user();
       }
       else if(choice == 7)
       {
           user_borrow_book();
       }
       else if(choice == 8)
       {
           user_return_book();
       }
       else if(choice == 9)
       {
           print_users();
       }
       else if(choice == 10)
       {
           break;
       }
   }
}

void library_system::add_book() {
    cout<<"Enter book info: id & name & total quantity: ";
    book book;
    cin>>book.bookId>>book.bookName>>book.bookQuantity;
    books.push_back(book);
}
struct {
    bool operator()(book &a, book &b) const { return a.bookId < b.bookId; }
} compare_id;

void library_system::print_library_by_id() {
    sort(books.begin() ,books.end() ,compare_id);
    for (int i = 0; i < books.size(); i++) {
        books[i].print_book_info();
    }
}

struct {
    bool operator()(book &a, book &b) const { return a.bookName < b.bookName; }
} compare_name;

void library_system::print_library_by_name() {

    sort(books.begin() ,books.end() ,compare_name);
    for (int i = 0; i < books.size(); i++) {
        books[i].print_book_info();
    }
}

void library_system::search_books_by_prefix() {
    cout<<"Enter book name prefix:";
    string prefix;
    cin>>prefix;
    int cnt = 0;
    for(int i = 0 ;i<books.size() ;i++)
    {
        if(books[i].print_prefix(prefix))
        {
            cnt++;
        }
    }
    if(cnt == 0)
    cout<<"No books with such prefix\n";
}

void library_system::add_user() {
  cout<<"Enter user name & national id\n";
  user user;
  cin>>user.userName>>user.userId;
  users.push_back(user);
}

void library_system::print_users() {
    for (int i = 0; i < users.size(); i++) {
       users[i].print_user_info();
    }
}

void library_system::user_borrow_book() {
  cout<<"Enter user name and book name:";
  string userName ,bookName;
  cin>>userName>>bookName;
  //searching for a book and a user in the library...
  int bookAddress = search_book(bookName);
  int userAddress = search_user(userName);
  if(books[bookAddress].bookQuantity) //admin can lend a book.
  {
      //update book info..
      books[bookAddress].decrease_quantity_book();
      books[bookAddress].increase_borrowed_book();
      books[bookAddress].add_borrower(userName);
      //update user info..
      int bookId = books[bookAddress].bookId;
      users[userAddress].add_borrowed_book(bookId);
  }
  else  //all the books were borrowed --> admin cannot lend a book.
  {
       cout<<"All the books were borrowed\n";
  }
}

int library_system::search_book(string bookName) {
     for(int index = 0 ;index<books.size() ;index++)
     {
         if(books[index].bookName == bookName)
         {
             return index;
         }
     }
    return -1; //the book is not in the library.
}

int library_system::search_user(string userName) {
    for(int index = 0 ;index<users.size() ;index++)
    {
        if(users[index].userName == userName)
        {
            return index;
        }
    }
    return -1; //the user is not in the library.
}

void library_system::print_who_borrowed_book_by_name() {
   cout<<"Enter book name :";
   string bookName;
   cin>>bookName;
   int bookAddress = search_book(bookName);
   if(bookAddress == -1) //a book is not in the library.
   {
       cout<<"Invalid book name.\n";
       return;
   }
   books[bookAddress].print_borrowers();
}

void library_system::user_return_book() {
   cout<<"Enter user name and book name:";
   string userName ,bookName;
   cin>>userName>>bookName;
   //searching for a book and a user in the library...
   int bookAddress = search_book(bookName);
   int userAddress = search_user(userName);
   //update book info..
   books[bookAddress].remove_borrower(userName);
   books[bookAddress].decrease_borrowed_book();
   books[bookAddress].increase_quantity_book();
   //update user info..
    int bookId = books[bookAddress].bookId;
    users[userAddress].remove_borrowed_book(bookId);
}

//bool library_system::compare_id(const book &a,const book &b) {
  // return (a.bookId < b.bookId);
//}
