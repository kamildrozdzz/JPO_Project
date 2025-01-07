#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include <string>
#include <iostream>
#include <sstream>
#include <user.hpp>
#include "book.hpp"

class MySQLWrapper {
private:
    MYSQL* conn;
    std::string host;
    std::string user;
    std::string PASS;
    std::string DATABASE;
    int PORT;
    std::string loggedUser;
    int pin;

    MYSQL_RES* res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    const char * q;
    std::string query;

public:
    MySQLWrapper(std::string host, std::string user, std::string PASS, std::string DATABASE, int PORT);
    MYSQL* getConnection(void) const;
    void setLoggedUser(User user);
    std::string getLoggedUser(void) const;
    void setPin(int pin);
    int getPin(void) const;
    bool checkPin(int pin);
    User login(MYSQL* conn, std::string name, std::string password);
    User signup(MYSQL* conn, std::string name, std::string surname, std::string email, std::string password);
    void setQuery(std::string query);
    void displayAllBooks(MYSQL* conn);
    void listOfBooks(MYSQL* conn);
    void listOfUsers(MYSQL* conn);
    int getNewBookID(MYSQL* conn);
    void addBook(MYSQL* conn, Book book);
    void updateBook(MYSQL* conn, Book book);
    void updateUser(MYSQL* conn, User user);
    void borrowedBooks(MYSQL* conn);
    void borrowedBooks(MYSQL* conn, int userID);
    void updateBorrowedBooks(MYSQL* conn, int bookID);
    void addBorrowedBook(MYSQL* conn, int bookID, int userID);
    MYSQL_RES* executeQuery(MYSQL* conn);
    ~MySQLWrapper();
};