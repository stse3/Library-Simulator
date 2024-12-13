#include <iostream>
#include "libraryUser.hpp"
#include "library.hpp"
#include "book.hpp"

using namespace std;

int main() {
    // Creating book instances
    Book book1("1984", "George Orwell", "Dystopian", "1949");
    Book book2("To Kill a Mockingbird", "Harper Lee", "Fiction", "1960");
    Book book3("The Hobbit", "J.R.R. Tolkien", "Fantasy", "1937");
    Book book4("Sapiens", "Yuval Noah Harari", "Non-fiction", "2011");
    Book book5("Brave New World", "Aldous Huxley", "Dystopian", "1932"); // Fifth book added
    Book book6;//default constructor, teacher will add this to the library

    // Creating library instance
    Library library;

    // Inserting books into the library (at least 5 books)
    library.insert(&book1);
    library.insert(&book2);
    library.insert(&book3);
    library.insert(&book4);
    library.insert(&book5);
    library.print();
    
    // Print the books in the library (advanced search)
    cout << "\nSearch for Dystopian books:" << endl;
    library.advanced_search("", "", "Dystopian");

    // Creating LibraryUser instances
    LibraryUser user1("John Doe", "U001", 0);
    user1.print_user();

    LibraryUser user2("Jane Smith", "U002", 1);
    user2.print_user();

    // Creating Student and Teacher instances
    Student student1("Alice Johnson", "S001", 0, false, 3);  // Student with a borrow limit of 3
    Teacher teacher1("Prof. Michael Brown", "T001", 0, 10);  // Teacher with a borrow limit of 10

    // Borrowing books for Student and Teacher
    cout << "\nStudent borrows a book:" << endl;
    library.borrow_book(student1, "1984");
    cout << "Borrowed count (Student): " << student1.get_borrowed_count() << endl;

    cout << "\nTeacher borrows a book:" << endl;
    library.borrow_book(teacher1, "To Kill a Mockingbird");
    cout << "Borrowed count (Teacher): " << teacher1.get_borrowed_count() << endl;

    // Try borrowing more books than the allowed limit for a student
    cout << "\nStudent tries to borrow more books than the limit:" << endl;
    library.borrow_book(student1, "The Hobbit");
    library.borrow_book(student1, "Sapiens");
    library.borrow_book(student1, "Brave New World");  // Exceeds the borrow limit
    cout << "Borrowed count (Student): " << student1.get_borrowed_count() << endl;


    // Returning books
    cout << "\nReturning books:" << endl;
    library.return_book(student1, "1984");  // Returning 1 book
    cout << "Borrowed count (Student) after return: " << student1.get_borrowed_count() << endl;

    library.return_book(teacher1, "To Kill a Mockingbird");  // Returning 1 book
    cout << "Borrowed count (Teacher) after return: " << teacher1.get_borrowed_count() << endl;

    cout <<"\nTeacher, Michael Brown adds default constructor book to library: "<<endl;
    teacher1.add_book_to_library(library, &book6);
    cout<<"Removing default constructor book from library: "<<endl;
    library.remove(&book6);
    

    // Removing a book from the library
    cout << "\nRemoving '1984' book from the library:" << endl;
    library.remove(&book1);  // Removing the book from the library
    library.print();

    // Trying to perform a search again after removal
    cout << "\nSearch for Dystopian books after removal:" << endl;
    library.advanced_search("", "", "Dystopian");

    // Remove a book using string parameters (title, author, genre, and year)
    cout << "\nRemoving 'The Hobbit' book using string parameters:" << endl;
    library.remove("The Hobbit", "J.R.R. Tolkien", "Fantasy", "1937");

    // Print updated library
    cout << "\nLibrary after removing books:" << endl;
    library.print();

    return 0;
}
