#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <iostream>
using namespace std;

class Book{
    string title, author, genre, year_published;

    public:
    Book(const string& titleOf, const string& authorOf, const string& genreOf, const string& DOPof);  // Full constructor
    Book(const string& titleOf, const string& authorOf, const string& genreOf);//Initializes 3 paramters: Constructor w default DOP
    Book(const string& titleOf, const string& authorOf);               // Initialize Two Parameters: Constructor with default DOP, genre
    Book(const string& titleOf);                                 // Intialize One Parameter: Constructor with default author, genre and DOP
    Book();    //Default constructor


    string get_title() const;
    string get_author()const;
    string get_genre()const;
    string get_year_published()const;
    bool operator==(const Book& book)const;
    void print()const;
};
#endif// BOOK_HPP


