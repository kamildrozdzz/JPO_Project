#include <iostream>
#include <conio.h>
#include "users.hpp"
#include "books.hpp"

using std::cout, std::endl;

namespace libraryonline{

    void admin_menu(MYSQL* conn, users user) {
        char choice;
        while (true){
            system("cls");
            cout << "--------------------------------" << endl;
            cout << "       ADMIN PANEL"<< endl;
            cout << "--------------------------------" << endl;
            cout << " 1. ADD BOOK" << endl;
            cout << " 2. UPDATE BOOK" << endl;
            cout << " 3. UPDATE USER" << endl;
            cout << " 4. BORROWED BOOKS" << endl;
            cout << " 0. RETURN TO MAIN MENU" << endl;
            cout << "Enter Your Choice: ";

            choice = getch();
                    
            switch (choice) {
                case '1':
                    {
                        books book;
                        book.addBook(conn);
                    }
                    break;
                case '2':
                    {
                        books book;
                        book.updateBook(conn);
                    }
                    break;
                case '3':
                    user.updateUser(conn);
                    break;
                case '4':
                    {
                        books book;
                        book.borrowedBooks(conn);
                    }
                    break;
                case '0':
                    return;
                    break;
                default:
                    cout << "\nInvalid option! Try again." << endl;
                    break;
                }
                cout << "\nPress any key to continue...";
                getch();
            } 
        }
    
    void main_menu(MYSQL* conn) {
        char choice;
        users user;
        while (true) {
            if(user_name==""){
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
                        system("cls");
                        user_name = user.login(conn);
                        break;
                    case '2':
                        system("cls");
                        user_name = user.singup(conn);
                        break;
                    case '0':
                        cout << "\nExiting..." << endl;
                        exit(1);
                    default:
                        cout << "\nInvalid option! Try again." << endl;
                        break;
                }
                cout << "\nPress any key to continue...";
                getch();
            }else{
                system("cls");
                cout << "--------------------------------" << endl;
                cout << "       WELCOME "<< user_name<<"!"<< endl;
                cout << "--------------------------------" << endl;
                cout << " 1. DISPLAY BOOKS" << endl;
                cout << " 2. USER INFO" << endl;
                cout << " 3. ADMIN PANEL" << endl;
                cout << " 0. EXIT" << endl;
                cout << "Enter Your Choice: " << endl;

                choice = getch();

                switch (choice) {
                    case '1':
                        {
                        books book;
                        book.displayAll(conn);
                        }
                        break;
                    case '2':
                        user.getUserInfo();
                        break;
                    case '3':
                        if(user.pin()==PIN){
                            libraryonline::admin_menu(conn, user);
                        }else{
                            cout << "Incorrect Password" << endl;
                        }
                        break;
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

    
}

