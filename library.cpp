#include "library.hpp"
#include "libraryUser.hpp"
#include "book.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <cctype>


using namespace std;
//defines a to_lowercase function

std::string to_lowercase(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));  // Convert each char to lowercase
    }
    return result;
}

Library::Library(){};//default constructor 
//will implicitly intialize empty vectors

Library::Library(vector <Book*>& books):books(books){
    //initialize is_borrowed to match the size of the books 
    for (int i=0; books.size();i++){
        is_borrowed.push_back(false);
    }
}


bool Library:: insert(Book* book_p){
    if (book_p == nullptr) {
        return false;
    }

    //iterate through books to see if there is exisitng book
    for (Book* existing_book:books){
        if (*existing_book==*book_p){
            return false;
        }
    }
    books.push_back(book_p);
    is_borrowed.push_back(false);
    return true;

}
//OPTIONAL: Implement an insertion where title, authors, genre and year published are provdied as string values, and adjusts is_borrowed 
bool Library:: insert (const string& title, const string& author, const string& genre, const string&year_published){
    //creates a dynamic new book object
    Book* newBook = new Book(title, author, genre, year_published);

    for (Book* existing_book:books){
        if (*existing_book == *newBook){
            return false;//book already exists
        }

    }
    //adds new book and sets the borrow status to false 
    books.push_back(newBook);
    is_borrowed.push_back(false);
    return true;

}


bool Library:: remove(Book* book_p){

    for (int i =0; i <books.size();i++){
        if (*books[i]==*book_p){
            books.erase(books.begin()+i);//erases the pointer from the vector
            is_borrowed.erase(is_borrowed.begin()+i);
            return true;
        }
    }
    return false;
}

//OPTIONAL: removal where title, authors, genre and year published are inputted

bool Library:: remove(const string& title, const string& author, const string& genre, const string&year_published){
        for (int i =0; i <books.size();i++){
        if (*books[i]==Book(title,author,genre,year_published)){//creates Book object on stack, so no need to delete
            books.erase(books.begin()+i);//erases the pointer from the vector
            is_borrowed.erase(is_borrowed.begin()+i);
            return true;
        }
    }
    return false;
}


//search a book based on substrings of attributes: inputs title, author, genre and OPTIONAL: allowed for case-insensitive string comparison
void Library::advanced_search(const string& title, const string& author, const string& genre){
    bool match = false;
    for (Book* book: books){
        if (to_lowercase(book->get_author()).find(to_lowercase(author))!=std::string::npos//includes case sensitivy
        && to_lowercase(book->get_genre()).find(to_lowercase(genre))!=std::string::npos
        && to_lowercase(book->get_title()).find(to_lowercase(title))!=std::string::npos){
            book->print();
            match = true;// book exists in the library
        }
    }
    if (!match){
        cout<< "That book is not in the library"<<endl;
    }
}

void Library:: return_book(LibraryUser person, const string& title){
    
    bool returned = false;
    for (int i =0; i <books.size();i++){
        if (books[i]->get_title()==title){
            is_borrowed[i]=false;//returns is_borrowed back to false
            person.returnBook();//decrements the borrowed_book count for LibraryUser object
            //prints message indicating name of user and title of book being returned
            cout << title << " was succesfully returned by " << person.get_name()<< "!" << endl; 
            returned = true;
            break;
        
        }
    }
    if (!returned){//prints message since book is not properly returned
        cout<< title <<" was not successfully returned."<<endl;
    }
}
void Library:: borrow_book(Student& person, const string&title){
    bool borrowed = false;
    for (int i=0;i<books.size();i++){
        if (books[i]->get_title()==title &&!is_borrowed[i]&&person.get_borrowed_count()<person.get_borrow_limit()){
            is_borrowed[i]=true;
            person.borrow();
            cout<< title << " is sucessfully borrowed by "<< person.get_name()<<endl;
            borrowed =true;
            break;

        }
    }
    if (!borrowed){
        cout<< title << " was not sucesfully borrowed by" << person.get_name()<<"!"<<endl;
    }
}

void Library:: borrow_book(Teacher& person, const string&title){
    bool borrowed = false;
    for (int i=0;i<books.size();i++){
        if (books[i]->get_title()==title &&!is_borrowed[i]&&person.get_borrowed_count()<person.get_borrow_limit()){
            is_borrowed[i]=true;
            person.borrow();
            cout<< title << " is sucessfully borrowed by "<< person.get_name()<<endl;
            borrowed =true;
            break;

        }
    }
    if (!borrowed){
        cout<< title << " was not sucesfully borrowed by" << person.get_name()<<"!"<<endl;
    }
}

void Library::borrow_book(LibraryUser& person,const string& title){
    bool borrowed = false;
    for (int i=0;i<books.size();i++){
        if (books[i]->get_title()==title &&!is_borrowed[i]){
            is_borrowed[i]=true;
            person.borrow();
            cout<< title << " is sucessfully borrowed by "<< person.get_name()<<endl;
            borrowed =true;
            break;

        }
    }
    if (!borrowed){
        cout<< title << " was not sucesfully borrowed by" << person.get_name()<<"!"<<endl;
    }
}
void Library:: print(){
    for (Book* book: books){
        book->print();
    }

}