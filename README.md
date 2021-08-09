# This is a **classical library system project** using `structs` for encapsulation.
*  Many libraries have a library system.
   * Helps adding books and searching for them.
   * Maintains information about the borrowed books.
   
* The main user for the system is an admin(he can do all operations in the system).
## operations :
there are two main operation applied in the system.
* ```Book Operations``` :
  * Adding a book : Every system needs data and the admin needs to be able to add books to the library.
  * Searching for a book : admin will search the system using book name.
  * Listing books : 
    * List books in sorted order by id.
    * List books in sorted order by name.
  * Listing users borrowed a book : Given that several users may borrow a book, the admins may want to know 
                                    who borrowed what.
* ```User Operations``` :
  * Add a user : admin can add user to a library system.
  * Borrow a book : user can borrow a book and admin update the data in the system.
  * Return a book : user also can return a book and admin update the data in the system.                               
  * Admin can list the users in the system by name.

## Technologies used:
* only c++ , its a console app for learning purpose.

