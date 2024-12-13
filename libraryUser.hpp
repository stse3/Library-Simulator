#ifndef LIBRARYUSER_HPP
#define LIBRARYUSER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "library.hpp"


using namespace std;

class Library;  // Forward declaration to avoid circular dependency
class Book;

class LibraryUser{
    private:
        string name;
        string user_id;
        int borrowed_count;//number of borrows

    public:
        LibraryUser();//default constructor
        LibraryUser(const string& user, const string& user_id, const int& borrowed_count);//paramterized constructor to initiate all the attributes
        string get_name();//returns full name of the user 
        string get_user_id();//returns user_id
        int get_borrowed_count();//returns number of books borrowed by the user
        void borrow();//increments borrowed_count
        void returnBook();//derements borrowed_count
        // ^note: the document says to call this function return() but that would conflict with C++ keyword return
       
        void print_user();//print current value for user attributes

};

class Student: public LibraryUser{
    private:
        bool graduated;//only student class has this attribute
        const int borrow_limit;//constant value of 3 for student, less than teachers 

        
    public:
        Student();//default constructor
        Student(const string& name, const string&user_id, int borrowed_count,bool graduated, int borrow_limit);//parametric constructor
        
        int get_borrow_limit();//returns the borrow_limit
        void print();//print that it is Student, all user attributes and attributes inherited to the users


};

class Teacher: public LibraryUser{
    private:
        const int borrow_limit;//constant value for borrow limit that is greater than the students
        //note that teacher class does not have valid genres 
        
    public:
        Teacher();//default constructor
        Teacher(const string& name, const string&user_id, int borrowed_count, int borrow_limit);//parametric constructor
        int get_borrow_limit();//returns the borrow_limit
        void print();//print that it is Student, all user attributes and attributes inherited to the users
        void add_book_to_library(Library& library, Book* newBook);//only implemented for Teacher class --> teacher can add books to library
};



#endif // LIBRARYUSER_HPP
