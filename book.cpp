#include "book.hpp"
#include <string>
#include <iostream>
using namespace std;

Book::Book(const string& titleOf, const string& authorOf, const string& genreOf, const string& DOPof)
    :title(titleOf),author(authorOf),genre(genreOf), year_published(DOPof){}  // Full constructor
Book::Book(const string& titleOf, const string& authorOf, const string& genreOf)
    :title(titleOf),author(authorOf),genre(genreOf),year_published("n/a"){}//Initializes 3 paramters: Constructor w default DOP
Book::Book(const string& titleOf, const string& authorOf)
    :title(titleOf),author(authorOf),genre("n/a"),year_published("n/a"){}              // Initialize Two Parameters: Constructor with default DOP, genre
Book::Book(const string& titleOf)
    :title(titleOf),author("n/a"),genre("n/a"),year_published("n/a"){}                              // Intialize One Parameter: Constructor with default author, genre and DOP
Book::Book()
    :title("n/a"),author("n/a"),genre("n/a"),year_published("n/a"){}    //Default constructor


string Book::get_title()const{
    return title;
}
string Book::get_author()const{
    return author;
}
string Book::get_genre()const{
    return genre;
}
string Book::get_year_published()const{
    return year_published;
}
bool Book::operator==(const Book& book) const {//uses const because book should not be modified, and function is labeled const 
    //returns true if the  if they are considered equal based on their attributes or not
    return title == book.get_title()
     && author == book.get_author() 
     && genre == book.get_genre()
     && year_published == book.get_year_published();

}
void Book::print() const{
     cout << title << ", " << author << ", " << genre << ", " << year_published << endl;

}