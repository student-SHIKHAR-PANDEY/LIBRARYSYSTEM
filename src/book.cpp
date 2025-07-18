#include "book.h"
#include <iostream>

Book::Book() {}

Book::Book(std::string t, std::string a, std::string i) {
    title = t;
    author = a;
    isbn = i;
    isAvailable = true;
}

void Book::display() {
    std::cout << "Title: " << title
              << ", Author: " << author
              << ", ISBN: " << isbn
              << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
}

void Book::markBorrowed() {
    isAvailable = false;
}

void Book::markReturned() {
    isAvailable = true;
}

bool Book::available() {
    return isAvailable;
}
#include "book.h"
#include <iostream>

// Already existing methods should be here

void Book::saveToFile(std::ofstream &out) const  {
    out << title << '\n'
        << author << '\n'
        << isbn << '\n'
        << (isAvailable ? 1 : 0) << '\n';
}

void Book::loadFromFile(std::ifstream &in) {
    std::getline(in, title);
    std::getline(in, author);
    std::getline(in, isbn);
    
    int availableFlag;
    in >> availableFlag;
    isAvailable = (availableFlag == 1);

    in.ignore(); // to consume the leftover newline character
}
