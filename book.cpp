#include "book.h"

using namespace std;

Book::Book() {}

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