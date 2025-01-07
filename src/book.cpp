#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
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

void Book::updateBook(void) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         UPDATE BOOK" << endl;
    cout << "--------------------------------" << endl;

    cout << "Enter the ID of the book to update: ";
    cin >> id;

    std::cin.ignore(10000, '\n');

    cout << "Enter the new title (leave empty to keep current): ";
    std::getline(cin, title);

    cout << "Enter the new series (leave empty to keep current): ";
    std::getline(cin, series);

    cout << "Enter the new author (leave empty to keep current): ";
    std::getline(cin, author);

    cout << "Enter the new publishing house (leave empty to keep current): ";
    std::getline(cin, publishingHouse);

    cout << "Enter the new number of pages (leave empty to keep current): ";
    std::string pagesInput;
    std::getline(cin, pagesInput);
    if (!pagesInput.empty()) {
        try {
            numberOfPages = std::stoi(pagesInput);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid input for number of pages. Keeping current value." << endl;
        }
    }

    cout << "Enter the new year of issue (leave empty to keep current): ";
    std::string yearInput;
    std::getline(cin, yearInput);
    if (!yearInput.empty()) {
        try {
            yearOfIssue = std::stoi(yearInput);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid input for year of issue. Keeping current value." << endl;
        }
    }
}