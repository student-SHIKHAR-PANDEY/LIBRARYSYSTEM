#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <fstream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    Book();
    Book(std::string title, std::string author, std::string isbn);

    void display();
    void markBorrowed();
    void markReturned();
    bool available();

    // 📁 File I/O functions
    void saveToFile(std::ofstream &out) const;
    void loadFromFile(std::ifstream &in);
};

#endif
