#include "libraryUser.hpp"
#include <iostream>

LibraryUser::LibraryUser():name("n/a"),user_id("n/a"),borrowed_count(0){}//default constructor

LibraryUser:: LibraryUser(const string& name, const string& user_id, const int& borrowed_count): name(name),user_id(user_id),borrowed_count(borrowed_count){}//paramterized constructor to initiate all the attributes

//returns full name of the user 
string LibraryUser:: get_name(){
    return name;

}
//returns user_id
string LibraryUser::get_user_id(){
    return user_id;

}
//returns number of books borrowed by the user
int LibraryUser:: get_borrowed_count(){
    return borrowed_count;
}
//increments borrowed_count
void LibraryUser:: borrow(){
    borrowed_count++;
}
//derements borrowed_count
void LibraryUser:: returnBook(){
    borrowed_count--;
}
//print current value for user attributes
void LibraryUser::print_user(){
    cout<< name <<" , " << user_id << " , "<< borrowed_count<<endl;
}


Student:: Student():
    LibraryUser(),graduated(false),borrow_limit(3){}

Student:: Student(const string& name, const string&user_id, int borrowed_count,bool graduated, int borrow_limit)
    :LibraryUser(name,user_id,borrowed_count),borrow_limit(borrow_limit){}


int Student:: get_borrow_limit(){
    return borrow_limit;
}

void Student:: print(){
    cout << "User Type: Student , ";
    print_user();  // Call the print_user method directly
    cout << "Graduated: " << graduated << " Borrow Limit: " << borrow_limit << endl;
}

Teacher:: Teacher():
    LibraryUser(),borrow_limit(5){}

Teacher:: Teacher(const string& name, const string&user_id, int borrowed_count, int borrow_limit)
    :LibraryUser(name,user_id,borrowed_count),borrow_limit(borrow_limit){}

int Teacher:: get_borrow_limit(){
    return borrow_limit;
}

void Teacher:: print(){
    cout << "User Type: Teacher , ";
    print_user();  // Call the print_user method directly
    cout << "Borrow Limit: " << borrow_limit << endl;
}

void Teacher:: add_book_to_library(Library& library, Book* newBook){//fucnction inputs a Library object and a Book object pointer, and inserts the book to the library
    library.insert(newBook);
}
