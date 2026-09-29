#include <sstream>

#include "book.h"

using namespace std;

Book::Book() {}

// Getters
string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

string Book::getISBN() const{
    return isbn;
}

bool Book::getAvailability() const{
    return isAvailable;
}

string Book::getBorrowerId() const{
    return borrowerId;
}

//Setters
void Book::setTitle(const string& title){
    this->title=title;
}

void Book::setAuthor(const string& author){
    this->author=author;
}

void Book::setISBN(const string& isbn){
    this->isbn=isbn;
}

void Book::setAvailability(bool available){
    this->isAvailable=available;
}

void Book::setBorrowerId(const string& id){
    this->borrowerId=id;
}

// Methods
void Book::checkOut(const string& borrowerId){
    setAvailability(false);
    setBorrowerId(borrowerId);
}

void Book::returnBook(){
    setAvailability(true);
    setBorrowerId("");
}

string Book::toString() const{
    string result = getTitle() + " | " 
        + getAuthor() + " | " 
        + getISBN() + " | ";

    if(getAvailability()){
        result += "1 |";
    }else{
        result += "0 | " + getBorrowerId();
    }

    return result;
}

string Book::toFileFormat() const{
    return toString();
}

void Book::fromFileFormat(const string& line){
    stringstream bookInfo(line);

    string available;

    getline(bookInfo, this->title, '|');
    getline(bookInfo, this->author, '|');
    getline(bookInfo, this->isbn, '|');
    getline(bookInfo, available, '|');
    getline(bookInfo, this->borrowerId, '|');

    setAvailability(available == "1");
}