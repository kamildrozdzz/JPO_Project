#ifndef BOOKS_HPP
#define BOOKS_HPP

#include <string>

namespace kd {
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
        Book(int id = 0, std::string title = "Unknown", std::string series = "Unknown", std::string author = "Unknown", std::string publishingHouse = "Unknown", int numberOfPages = 0, int yearOfIssue = 0);
        int getId(void) const;
        std::string getTitle(void) const;
        std::string getSeries(void) const;
        std::string getAuthor(void) const;
        std::string getPublishingHouse(void) const;
        int getNumberOfPages(void) const;
        int getYearOfIssue(void) const;
    };
} // namespace kd

#endif // BOOKS_HPP
