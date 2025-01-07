#ifndef BOOKS_HPP
#define BOOKS_HPP

#include <string>

class Book {
    private:
        int id;       
        std::string title;
        std::string series;
        std::string author;
        std::string publishingHouse;
        int numberOfPages;
        int yearOfIssue;
    
    public:
        Book();
        Book(int id, std::string title, std::string series, std::string author, std::string publishingHouse, int numberOfPages, int yearOfIssue);
        int getId(void) const;
        std::string getTitle(void) const;
        std::string getSeries(void) const;
        std::string getAuthor(void) const;
        std::string getPublishingHouse(void) const;
        int getNumberOfPages(void) const;
        int getYearOfIssue(void) const;
};

#endif // BOOKS_HPP
