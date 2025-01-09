#include <mysql.h>
#include "database.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <conio.h>
#include <user.hpp>
#include <book.hpp>

using std::cout, std::cin, std::endl;

namespace kd {
    MySQLWrapper::MySQLWrapper(std::string host, std::string user, std::string PASS, std::string DATABASE, int PORT) {
        if (host.empty() || user.empty() || PASS.empty() || DATABASE.empty() || PORT <= 0) {
            std::cout << "Invalid database connection parameters." << std::endl;
            conn = nullptr;
            return;
        }

        conn = mysql_init(0);
        if (conn) {
            conn = mysql_real_connect(conn, host.c_str(), user.c_str(), PASS.c_str(), DATABASE.c_str(), PORT, NULL, 0);
            if (conn) {
                std::cout << "Connection to database successful!" << std::endl;
            } else {
                std::cout << "Connection to database failed: " << mysql_error(conn) << std::endl;
            }
        } else {
            std::cout << "MySQL initialization failed!" << std::endl;
        }
    }

    MYSQL* MySQLWrapper::getConnection(void) const {
        return conn;
    }

    void MySQLWrapper::setLoggedUser(User user){
        if (user.getUserName().empty() || user.getUserName().size() < 3) {
            return;
        }
        loggedUser = user.getUserName();
    }

    std::string MySQLWrapper::getLoggedUser(void) const {
        return loggedUser;
    }

    bool MySQLWrapper::setPin(int pin) {
        if (pin < 4) {
            cout << "Invalid PIN." << endl;
            return false;
        }
        this->pin = pin;
        return true;
    }

    int MySQLWrapper::getPin(void) const {
        return pin;
    }

    void MySQLWrapper::setQuery(std::string query) {
        if (query.empty()) {
            cout << "\nQuery cannot be empty." << endl;
            return;
        }
        this->query = query;
    }

    MYSQL_RES* MySQLWrapper::executeQuery() {
        if (!conn) {
            cout << "Invalid database connection." << endl;
            return nullptr;
        }
        q = query.c_str();
        mysql_query(conn, q);
        res_set = mysql_store_result(conn);
        return res_set;
    }

    User MySQLWrapper::login(std::string name, std::string password) {
        if (name.empty() || password.empty()) {
            cout << "Name or password cannot be empty." << endl;
            return User();
        }
        std::string surname, email, status;
        setQuery("SELECT * FROM uzytkownicy;");
        MYSQL_ROW row{};
        res_set = executeQuery();
        while((row = mysql_fetch_row(res_set)) != NULL) {
            if(row[1] == name && row[4] == password) {
                surname = row[2];
                email = row[3];
                status = row[5];

                User user(std::stoi(row[0]), name, surname, email, password, status);
                return user;
            }
        }
        cout << endl;
        cout << "Podano błędne dane logowania" << endl;
        cout << "Spróbuj ponownie..." << endl;
        getch();
        std::cout << "Enter your user name:\n";
        std::cin >> name;
        std::cout << "Enter your password:\n";
        char ch;
        password = "";
        while((ch = _getch()) != '\r') {
            if(ch == '\b') { 
                if(!password.empty()) {
                    password.pop_back();
                    std::cout << "\b \b";
                }
                } else {
                    password += ch;
                    std::cout << '*';
                    }
                }
        system("cls");
        return login(name, password);
    }

    User MySQLWrapper::signup(std::string name, std::string surname, std::string email, std::string password) {
        if (name.empty() || surname.empty() || email.empty() || password.empty()) {
            cout << "All fields are required." << endl;
            return User();
        }
        setQuery("SELECT * FROM uzytkownicy;");
        MYSQL_ROW row{};
        res_set = executeQuery();
        while((row = mysql_fetch_row(res_set)) != NULL) {
            if(row[3] == email) {
                cout << "Użytkownik o podanym adresie email istnieje!" << endl;
                cout << "Spróbuj ponownie..." << endl;
                getch();
                system("cls");
                cout << "Enter your email:" << endl;
                std::cin >> email;
                return signup(name, surname, email, password);
            }
        }
        setQuery("INSERT INTO uzytkownicy (imie, nazwisko, email, haslo) VALUES ('" 
                        + name + "', '" 
                        + surname + "', '" 
                        + email + "', '" 
                        + password + "');");
        if (mysql_query(conn, query.c_str()) == 0) {
            cout << "Successfully signed up" << endl;
            setQuery("SELECT MAX(id_uzytkownika) AS max_id FROM uzytkownicy;");
            res_set = executeQuery();
            row = mysql_fetch_row(res_set);
            cout << row[0] << endl;
            User user(std::stoi(row[0]), name, surname, email, password);
            return user;
        } else {
            cout << "ERROR! Check db connection" << endl;
            getch();
            system("cls");
            return signup(name, surname, email, password);
        }
    }

    bool MySQLWrapper::checkPin(int pin){
        if (pin < 0) {
            cout << "Invalid PIN." << endl;
            return false;
        }
        return this->pin == pin;
    }

    void MySQLWrapper::displayAllBooks(void){
        system("cls");
        setQuery("SELECT * FROM ksiazki;");
        res_set = executeQuery();
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

    int MySQLWrapper::getNewBookID(void){
        setQuery("SELECT MAX(id_produktu) AS max_id FROM ksiazki;");
        res_set = executeQuery();
        row = mysql_fetch_row(res_set);
        return std::stoi(row[0]) + 1;
    }

    void MySQLWrapper::listOfBooks(void){
        system("cls");
        setQuery("SELECT * FROM ksiazki;");
        res_set = executeQuery();

        cout << "Current books in the database:" << endl;
        while ((row = mysql_fetch_row(res_set)) != NULL) {
            cout << "ID: " << row[0] << " - Title: " << row[1] << " - Series: "<< row[2] << " - Author: " << row[3] <<endl;
        }
        cout << "--------------------------------" << endl;
    }

    void MySQLWrapper::addBook(Book book){
        if (book.getTitle().empty() || book.getAuthor().empty()) {
            cout << "Book title and author cannot be empty." << endl;
            return;
        }
        setQuery("INSERT INTO ksiazki (tytul, seria, autor, wydawnictwo, liczba_stron, rok_wydania) VALUES ('" 
                        + book.getTitle() + "', '" 
                        + book.getSeries() + "', '" 
                        + book.getAuthor() + "', '" 
                        + book.getPublishingHouse() + "', " 
                        + std::to_string(book.getNumberOfPages()) + ", " 
                        + std::to_string(book.getYearOfIssue()) + ");");
        if (mysql_query(conn, query.c_str()) == 0) {
            cout << "Successfully added book" << endl;
        } else {
            cout << "ERROR! Check db connection" << endl;
        }
    }

    void MySQLWrapper::listOfUsers(void){
        system("cls");
        setQuery("SELECT * FROM uzytkownicy;");
        executeQuery();
        cout << "Current users in the database:" << endl;
        while ((row = mysql_fetch_row(res_set)) != NULL) {
            cout << "ID: " << row[0] << " - Name: " << row[1] << " - Surname: "<< row[2] << " - Email: " << row[3] <<endl;
        }
        cout << "--------------------------------" << endl;
    }

    void MySQLWrapper::updateBook(Book book){
        if (book.getId() < 0) {
            cout << "Invalid book ID." << endl;
            return;
        }
        std::string query = "UPDATE ksiazki SET ";
        if (!(book.getTitle()=="Unknown")) query += "tytul = '" + book.getTitle() + "', ";
        if (!(book.getSeries()=="Unknown")) query += "seria = '" + book.getSeries() + "', ";
        if (!(book.getAuthor()=="Unknown")) query += "autor = '" + book.getAuthor() + "', ";
        if (!(book.getPublishingHouse()=="Unknown")) query += "wydawnictwo = '" + book.getPublishingHouse() + "', ";
        if (book.getNumberOfPages() > 0) query += "liczba_stron = " + std::to_string(book.getNumberOfPages()) + ", ";
        if (book.getYearOfIssue() > 0) query += "rok_wydania = " + std::to_string(book.getYearOfIssue()) + ", ";
        query.pop_back();
        query.pop_back(); 
        query += " WHERE id_produktu = " + std::to_string(book.getId()) + ";";

        setQuery(query);
        res_set = executeQuery();

        if (!res_set) {
            cout << "Book updated successfully." << endl;
        } else {
            cout << "Error updating book. Check database connection." << endl;
        }
    }

    void MySQLWrapper::updateUser(User user){
        if (user.getUserID() < 0) {
            cout << "Invalid user ID." << endl;
            return;
        }
        std::string query = "UPDATE uzytkownicy SET ";
        if (!(user.getUserName()=="Unknown")) query += "imie = '" + user.getUserName() + "', ";
        if (!(user.getSurname()=="Unknown")) query += "nazwisko = '" + user.getSurname() + "', ";
        if (!(user.getEmail()=="Unknown")) query += "email = '" + user.getEmail() + "', ";
        if (!(user.getStatus()=="Unknown")) query += "status = '" + user.getStatus() + "', ";
        query.pop_back();
        query.pop_back();

        query += " WHERE id_uzytkownika = " + std::to_string(user.getUserID()) + ";";

        setQuery(query);
        res_set = executeQuery();

        if (!res_set) {
            cout << "User updated successfully." << endl;
        } else {
            cout << "Error updating user. Check database connection." << endl;
        }
    }

    void MySQLWrapper::borrowedBooks(void) {
        setQuery("SELECT ksiazki.tytul AS TytulKsiazki, uzytkownicy.imie AS Imie, uzytkownicy.nazwisko AS Nazwisko, wypozyczenia.id_produktu FROM  wypozyczenia JOIN ksiazki ON wypozyczenia.id_produktu = ksiazki.id_produktu JOIN uzytkownicy ON wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika WHERE wypozyczenia.status = 'wypożyczona';");
        res_set = executeQuery();
        cout << "Currently borrowed books:" << endl;
        while ((row = mysql_fetch_row(res_set)) != NULL) {
            cout <<row[3]<< " - Title: " << row[0] << " - Borrowed by: " << row[1] << " " << row[2] << endl;
        }
        cout << "--------------------------------" << endl;

        mysql_free_result(res_set);
    }

    void MySQLWrapper::borrowedBooks(User user) {
        if (user.getUserID() < 0) {
            cout << "Invalid user ID." << endl;
            return;
        }
        setQuery("SELECT ksiazki.tytul AS TytulKsiazki, uzytkownicy.imie AS Imie, uzytkownicy.nazwisko AS Nazwisko, wypozyczenia.id_produktu FROM  wypozyczenia JOIN ksiazki ON wypozyczenia.id_produktu = ksiazki.id_produktu JOIN uzytkownicy ON wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika WHERE wypozyczenia.status = 'wypożyczona' AND wypozyczenia.id_uzytkownika = " + std::to_string(user.getUserID()) + ";");
        res_set = executeQuery();
        cout << "Currently borrowed books:" << endl;
        while ((row = mysql_fetch_row(res_set)) != NULL) {
            cout <<row[3]<< " - Title: " << row[0] << " - Borrowed by: " << row[1] << " " << row[2] << endl;
        }
        cout << "--------------------------------" << endl;
        mysql_free_result(res_set);
    }

    void MySQLWrapper::updateBorrowedBooks(Book book){
        if (book.getId() < 0) {
            cout << "Invalid book ID." << endl;
            return;
        }
        setQuery("SELECT id_produktu FROM wypozyczenia WHERE status = 'wypożyczona';");
        res_set = executeQuery();
        while ((row = mysql_fetch_row(res_set))!=NULL){
            if(std::stoi(row[0])==book.getId()){
                query = "UPDATE wypozyczenia SET status = 'zwrócona' WHERE id_produktu = " + std::to_string(book.getId()) + ";";
                setQuery(query);
                res_set = executeQuery();
                if(!res_set){
                    cout << "Book returned successfully." << endl;
                    return;
                }else{
                    cout << "Error returning book. Check database connection." << endl;
                    return;
                }
            }
        }
        cout << "Book not found in borrowed books." << endl;
    }

    void MySQLWrapper::addBorrowedBook(Book book, User user){
        if (book.getId() < 0 || user.getUserID() < 0) {
            cout << "Invalid book or user ID." << endl;
            return;
        }
        query = "INSERT INTO wypozyczenia (id_uzytkownika, id_produktu, data_wypozyczenia, data_zwrotu, status)  VALUES ("+ std::to_string(user.getUserID()) +", "+ std::to_string(book.getId()) +", CURDATE(), NULL, 'wypożyczona');";
        setQuery(query);
        if (mysql_query(conn, query.c_str()) == 0) {
            cout << "Successfully borrowed book" << endl;
        } else {
            cout << "ERROR! Check db connection" << endl;
        }
    }

    MySQLWrapper::~MySQLWrapper() {
        if (conn) {
            mysql_close(conn);
        }
    }
} // namespace kd