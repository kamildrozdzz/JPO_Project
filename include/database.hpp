#include <mysql.h>
#include <string>
#include <iostream>
#include <sstream>
#include <user.hpp>
#include "book.hpp"

namespace kd {
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
        bool setPin(int pin);
        int getPin(void) const;
        bool checkPin(int pin);
        User login(std::string name, std::string password);
        User signup(std::string name, std::string surname, std::string email, std::string password);
        void setQuery(std::string query);
        void displayAllBooks(void);
        void listOfBooks(void);
        void listOfUsers(void);
        int getNewBookID(void);
        void addBook(Book book);
        void updateBook(Book book);
        void updateUser(User user);
        void borrowedBooks(void);
        void borrowedBooks(User user);
        void updateBorrowedBooks(Book book);
        void addBorrowedBook(Book book, User user);
        MYSQL_RES* executeQuery();
        ~MySQLWrapper();
    };
} // namespace kd