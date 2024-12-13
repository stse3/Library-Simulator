#ifndef LIBRARY_HPP// Check if the macro LIB_HPP is not defined.
#define LIBRARY_HPP //if the macro is not defined, define it.


#include <vector>
#include "libraryUser.hpp"
#include "library.hpp"

using namespace std;


class Book;//forward declaration
class LibraryUser;
class Teacher;
class Student;

class Library{
    private:
        vector<Book*> books;//a vector of book pointers
        vector<bool> is_borrowed;// a vector of boolean values
        
    public:
    Library();//default constructor
    Library (vector<Book*>& books);//one parametric constructor that takes input of Book objects poitner vector
    bool insert( Book* book_p);//inserts inputted Book object pointer, returns true if insertion 
    //suceeds, false if other
    bool insert(const string& title, const string& author, const string& genre, const string&year_published); //Optional Parameter: inputs title, authors, genre and date publsihed as strings 
    bool remove( Book* book_p);
    bool remove(const string& title, const string& author, const string& genre, const string&year_published);
    void advanced_search(const string& title, const string& author, const string& genre);
    void return_book(LibraryUser person, const string& title);
    void borrow_book(LibraryUser& person,const string& title);
    void borrow_book(Student& person, const string&title);
    void borrow_book(Teacher& person, const string&title);
    void print();//prints library
};

#endif //LIBRARY_HPP closes the #ifndef block