#ifndef BOOKS_HPP
#define BOOKS_HPP

#include <string>

class books {
    private:
        int id;       
        std::string title;
        std::string series;
        std::string author;
        std::string publishingHouse;
        int numberOfPages;
        int yearOfIssue;
    
    public:
        void displayAll(MYSQL* conn) const;
};

#endif // BOOKS_HPP
