#include <mysql.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <database.hpp>
#include <book.hpp>

using std::cout, std::cin, std::endl, std::string;

User user;

int main() {

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);       
    #endif
    MySQLWrapper mySQLobject("127.0.0.1", "root", "root", "libraryonline", 3306);
    mySQLobject.setLoggedUser(user);
    mySQLobject.setPin(1234);
    
    if(mySQLobject.getConnection()) {
        while (1) {
            system("cls");
            char choice;
            while (true) {
                if(mySQLobject.getLoggedUser() == "Unknown") {
                    system("cls");
                    cout << "--------------------------------" << endl;
                    cout << "       LIBRARY ONLINE" << endl;
                    cout << "--------------------------------" << endl;
                    cout << " 1. LOG IN" << endl;
                    cout << " 2. SIGN UP" << endl;
                    cout << " 0. EXIT" << endl;
                    cout << "Enter Your Choice: ";

                    choice = getch();
                    switch (choice) {
                        case '1': 
                            {
                                system("cls");
                                std::string name, password;
                                cout << "--------------------------------" << endl;
                                cout << "           LOG IN" << endl;
                                cout << "--------------------------------" << endl;
                                    
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
                                user = mySQLobject.login(name, password);
                                mySQLobject.setLoggedUser(user);
                                break;
                            }
                        case '2': 
                            {
                                system("cls");
                                std::string name, surname, email, password;
                                cout << "--------------------------------" << endl;
                                cout << "           SIGN UP" << endl;
                                cout << "--------------------------------" << endl;
                                
                                std::cout << "Enter your user name:\n";
                                std::cin >> name;
                                std::cout << "Enter your surname:\n";
                                std::cin >> surname;
                                std::cout << "Enter your email:\n";
                                std::cin >> email;
                                std::cout << "Enter your password:\n";
                                std::cin >> password;

                                user = mySQLobject.signup(name, surname, email, password);
                                mySQLobject.setLoggedUser(user);
                                break;
                            }
                        case '0':
                            cout << "\nExiting..." << endl;
                            exit(1);
                        default:
                            cout << "\nInvalid option! Try again." << endl;
                            break;
                    }
                    cout << "\nPress any key to continue...";
                    getch();
                } else {
                    system("cls");
                    cout << "--------------------------------" << endl;
                    cout << "       WELCOME " << user.getUserName() << "!" << endl;
                    cout << "--------------------------------" << endl;
                    cout << " 1. DISPLAY BOOKS" << endl;
                    cout << " 2. BORROW BOOK" << endl;
                    cout << " 3. YOUR BOOKS" << endl;
                    cout << " 4. USER INFO" << endl;
                    cout << " 5. ADMIN PANEL" << endl;
                    cout << " 0. EXIT" << endl;
                    cout << "Enter Your Choice: " << endl;

                    choice = getch();

                    switch (choice) {
                        case '1': 
                            {
                                mySQLobject.displayAllBooks();
                                break;
                            }
                        case '2':
                            {
                                system("cls");
                                cout << "--------------------------------" << endl;
                                cout << "       BORROW BOOK" << endl;
                                cout << "--------------------------------" << endl;
                                mySQLobject.listOfBooks();
                                cout << "Enter the ID of the book to borrow: ";
                                int bookId;
                                cin >> bookId;
                                Book book(bookId);
                                mySQLobject.addBorrowedBook(book, user);
                                break;
                            }
                        case '3':
                            {
                                system("cls");
                                cout << "--------------------------------" << endl;
                                cout << "           YOUR BOOKS." << endl;
                                cout << "--------------------------------" << endl;
                                mySQLobject.borrowedBooks(user);
                            }
                            break;
                        case '4':
                            {
                                system("cls");
                                cout << "--------------------------------" << endl;
                                cout << "           YOUR ACC." << endl;
                                cout << "--------------------------------" << endl;
                                user.getUserInfo();
                                break;
                            }
                        case '5': {
                            int num = 0;
                            system("cls");
                            cout << "--------------------------------" << endl;
                            cout << "       ENTER YOUR PIN" << endl;
                            cout << "--------------------------------" << endl;
                            cout << "Enter password: ";
                            for(int i = 0; i < 4; i++) {
                                num = num * 10 + (getch() - 48);
                                cout << "*";
                            }
                            if(mySQLobject.checkPin(num)) {
                                cout << "\nCorrect pin!" << endl;
                                cout << "\nPress any key to continue...";
                                getch();
                                while (true){
                                    system("cls");
                                    cout << "--------------------------------" << endl;
                                    cout << "       ADMIN PANEL"<< endl;
                                    cout << "--------------------------------" << endl;
                                    cout << " 1. ADD BOOK" << endl;
                                    cout << " 2. UPDATE BOOK" << endl;
                                    cout << " 3. UPDATE USER" << endl;
                                    cout << " 4. BORROWED BOOKS" << endl;
                                    cout << " 5. EDIT BORROWED BOOKS" << endl;
                                    cout << " 0. RETURN TO MAIN MENU" << endl;
                                    cout << "Enter Your Choice: ";

                                    choice = getch();
                                            
                                    switch (choice){
                                        case '1':
                                            {   
                                                system("cls");
                                                cout << "--------------------------------" << endl;
                                                cout << "           ADD BOOK" << endl;
                                                cout << "--------------------------------" << endl;

                                                std::string title, series, author, publishingHouse;
                                                int numberOfPages, yearOfIssue;

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
                                                Book book(mySQLobject.getNewBookID(), title, series, author, publishingHouse, numberOfPages, yearOfIssue);
                                                mySQLobject.addBook(book);
                                            }
                                            break;
                                        case '2':
                                            {
                                                mySQLobject.listOfBooks();
                                                cout << "\nPress any key to continue...";
                                                getch();
                                                system("cls");
                                                cout << "--------------------------------" << endl;
                                                cout << "         UPDATE BOOK" << endl;
                                                cout << "--------------------------------" << endl;
                                                int id, numberOfPages, yearOfIssue;
                                                std::string title, series, author, publishingHouse;
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
                                                Book book(id, title, series, author, publishingHouse, numberOfPages, yearOfIssue);
                                                mySQLobject.updateBook(book);
                                            }
                                            break;
                                        case '3':
                                            {
                                                mySQLobject.listOfUsers();
                                                cout << "\nPress any key to continue...";
                                                getch();
                                                system("cls");
                                                int userId;
                                                cout << "Enter the ID of the user to update: ";
                                                cin >> userId;
                                                std::cin.ignore(10000, '\n');
                                                system("cls");
                                                cout << "--------------------------------" << endl;
                                                cout << "         UPDATE USER" << endl;
                                                cout << "--------------------------------" << endl;
        
                                                std::string name, surname, email, status;                               

                                                cout << "Enter the new name (leave empty to keep current): ";
                                                std::getline(cin, name);

                                                cout << "Enter the new surname (leave empty to keep current): ";
                                                std::getline(cin, surname);

                                                cout << "Enter the new email (leave empty to keep current): ";
                                                std::getline(cin, email);

                                                cout << "Enter the new status (leave empty to keep current): ";
                                                std::getline(cin, status);

                                                User updateUser(userId, name, surname, email, status);
                                                mySQLobject.updateUser(updateUser);

                                            }
                                            break;
                                        case '4':
                                            {
                                                system("cls");
                                                cout << "--------------------------------" << endl;
                                                cout << "       BORROWED BOOKS" << endl;
                                                cout << "--------------------------------" << endl;
                                                mySQLobject.borrowedBooks();
                                            }
                                            break;
                                        case '5':
                                            {
                                                system("cls");
                                                cout << "--------------------------------" << endl;
                                                cout << "       BORROWED BOOKS" << endl;
                                                cout << "--------------------------------" << endl;
                                                mySQLobject.borrowedBooks();
                                                cout << "Enter the ID of the book to update: ";
                                                int bookId;
                                                cin >> bookId;
                                                mySQLobject.updateBorrowedBooks(bookId);
                                            }
                                            break;
                                        case '0':
                                            main();
                                            break;
                                        default:
                                            cout << "\nInvalid option! Try again." << endl;
                                            break;
                                    }
                                    cout << "\nPress any key to continue...";
                                    getch();
                                } 
                            } else {
                                cout << "\nWRONG PIN!" << endl;
                            }
                            break;
                        }
                        case '0':
                            cout << "\nExiting..." << endl;
                            exit(1);
                        default:
                            cout << "\nInvalid option! Try again." << endl;
                            break;
                    }
                    cout << "\nPress any key to continue...";
                    getch();
                }
            }
        }
    } else {
        system("cls");
        cout << "Error connecting to database. Please contact your administrator..." << endl;
        getch();
    }
}
