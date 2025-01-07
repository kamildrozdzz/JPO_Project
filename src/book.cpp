#include <mysql.h>
#include <book.hpp>
#include <string>
#include <iostream>
#include <conio.h>
#include <limits>
#include <database.hpp>

using std::cout, std::cin, std::endl;

Book::Book() {
    this->id = 0;
    this->title = "Unknown";
    this->series = "Unknown";
    this->author = "Unknown";
    this->publishingHouse = "Unknown";
    this->numberOfPages = 0;
    this->yearOfIssue = 0;
}

Book::Book(int id, std::string title, std::string series, std::string author, std::string publishingHouse, int numberOfPages, int yearOfIssue) {
    this->id = id;
    this->title = title;
    this->series = series;
    this->author = author;
    this->publishingHouse = publishingHouse;
    this->numberOfPages = numberOfPages;
    this->yearOfIssue = yearOfIssue;
}

int Book::getId(void) const {
    return id;
}

std::string Book::getTitle(void) const {
    return title;
}

std::string Book::getSeries(void) const {
    return series;
}

std::string Book::getAuthor(void) const {
    return author;
}

std::string Book::getPublishingHouse(void) const {
    return publishingHouse;
}

int Book::getNumberOfPages(void) const {
    return numberOfPages;
}

int Book::getYearOfIssue(void) const {
    return yearOfIssue;
}
