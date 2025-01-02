#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "../include/books.hpp"
#include <string>
#include <iostream>
#include <conio.h>
#include <limits>

using std::cout, std::cin, std::endl;

void books::displayAll(MYSQL* conn) const{
    system("cls");
    std::string query = "Select * from ksiazki;";
    const char* q = query.c_str();
    mysql_query(conn,q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};
    int count = 0;
    while((row = mysql_fetch_row(res_set)) != NULL)
    {
        if(count==0 || count%2==0){
            cout << "--------------------------------" << endl;
            cout << "             BOOKS " << endl;
            cout << "--------------------------------" << endl;
        }
        cout << "Books ID: "<< row[0] << endl;
        cout << "Name for book: "<< row[1] << endl;
        cout << "Book series: " << row[2] << endl;
        cout << "Author: " << row[3] << endl;
        cout << "Publishing house: " << row[4] << endl;
        cout << "Number of pages: " << row[5] << endl;
        cout << "Year of issue: " << row[6] << endl << endl;
        cout << "--------------------------------" << endl;

        count++;
        if (count%2==0){
            system("pause");
            system("cls");
        }
    }
}

void books::addBook(MYSQL* conn){
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "           ADD BOOK" << endl;
    cout << "--------------------------------" << endl;

    std::cin.ignore(10000, '\n');
    std::cout << "Enter the name of the book: " << std::endl;
    std::getline(std::cin, title);

    while (title.empty()) {
        std::cout << "Enter the name of the book (Title cannot be empty): " << std::endl;
        std::getline(std::cin, title);
    }


    std::cout << "Enter the series: "<< endl;
    std::getline(std::cin, series);

    std::cout << "Enter the name of the author: "<< endl;
    std::getline(std::cin, author);
    while (author.empty()) {
        std::cout << "Author cannot be empty. Please re-enter author: "<< endl;
        std::getline(std::cin, author);
    }

    std::cout << "Enter the publishing house: "<< endl;
    std::getline(std::cin, publishingHouse);
    while (publishingHouse.empty()) {
        std::cout << "Publishing house cannot be empty. Please re-enter publishing house: "<< endl;
        std::getline(std::cin, publishingHouse);
    }

    std::cout << "Enter the number of pages: " << endl;
    while (!(std::cin >> numberOfPages) || numberOfPages <= 0) {
        std::cout << "Number of pages must be a positive number. Please re-enter number of pages: " << endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }


    std::cout << "Enter the year of issue: " << endl;
    while (!(std::cin >> yearOfIssue) || yearOfIssue <= 0) {
        std::cout << "Year of issue cannot be empty. Please re-enter Year of issue: "<< endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::string query = "INSERT INTO ksiazki (tytul, seria, autor, wydawnictwo, liczba_stron, rok_wydania) VALUES ('" 
                    + title + "', '" 
                    + series + "', '" 
                    + author + "', '" 
                    + publishingHouse + "', '"
                    + std::to_string(numberOfPages) + "', '"
                    + std::to_string(yearOfIssue) + "');";
    const char * q = query.c_str();
	mysql_query(conn,q);
	MYSQL_RES* res_set = mysql_store_result(conn);

    system("cls");
    cout << "--------------------------------" << endl;
    cout << "           ADD BOOK" << endl;
    cout << "--------------------------------" << endl;

    if (!(res_set)){
        cout <<"Successfully" <<endl;
    }else{
        cout <<"ERROR! Check db conn"<< endl;
    }

    cout << "\nWprowadzone dane:\n";
    cout << "Tytuł: " << title << "\n";
    cout << "Seria: " << series << "\n";
    cout << "Autor: " << author << "\n";
    cout << "Wydawnictwo: " << publishingHouse << "\n";
    cout << "Liczba stron: " << numberOfPages << "\n";
    cout << "Rok wydania: " << yearOfIssue << "\n";

}

void books::updateBook(MYSQL* conn) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         UPDATE BOOK" << endl;
    cout << "--------------------------------" << endl;

    std::string query = "SELECT * FROM ksiazki;;";
    const char* q = query.c_str();
    mysql_query(conn, q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};

    cout << "Current books in the database:" << endl;
    while ((row = mysql_fetch_row(res_set)) != NULL) {
        cout << "ID: " << row[0] << " - Title: " << row[1] << " - Series: "<< row[2] << " - Author: " << row[3] <<endl;
    }
    cout << "--------------------------------" << endl;

    int bookId;
    cout << "Enter the ID of the book to update: ";
    cin >> bookId;

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
        numberOfPages = std::stoi(pagesInput);
    }

    cout << "Enter the new year of issue (leave empty to keep current): ";
    std::string yearInput;
    std::getline(cin, yearInput);
    if (!yearInput.empty()) {
        yearOfIssue = std::stoi(yearInput);
    }

    query = "UPDATE ksiazki SET ";
    if (!title.empty()) query += "tytul = '" + title + "', ";
    if (!series.empty()) query += "seria = '" + series + "', ";
    if (!author.empty()) query += "autor = '" + author + "', ";
    if (!publishingHouse.empty()) query += "wydawnictwo = '" + publishingHouse + "', ";
    if (!pagesInput.empty()) query += "liczba_stron = " + std::to_string(numberOfPages) + ", ";
    if (!yearInput.empty()) query += "rok_wydania = " + std::to_string(yearOfIssue) + ", ";
    query.pop_back();
    query.pop_back(); 
    query += " WHERE id_produktu = " + std::to_string(bookId) + ";";

    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if (!res_set) {
        cout << "Book updated successfully." << endl;
    } else {
        cout << "Error updating book. Check database connection." << endl;
    }
}

void books::borrowedBooks(MYSQL* conn) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "       BORROWED BOOKS" << endl;
    cout << "--------------------------------" << endl;

    std::string query = "SELECT ksiazki.tytul AS TytulKsiazki, uzytkownicy.imie AS Imie, uzytkownicy.nazwisko AS Nazwisko FROM  wypozyczenia JOIN ksiazki ON wypozyczenia.id_produktu = ksiazki.id_produktu JOIN uzytkownicy ON wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika WHERE wypozyczenia.status = 'wypożyczona';";
    const char* q = query.c_str();
    mysql_query(conn, q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};

    cout << "Currently borrowed books:" << endl;
    while ((row = mysql_fetch_row(res_set)) != NULL) {
        cout << " - Title: " << row[0] << " - Borrowed by: " << row[1] << " " << row[2] << endl;
    }
    cout << "--------------------------------" << endl;

    mysql_free_result(res_set);
}

