#include <iostream>
#include <conio.h>
#include "users.hpp"
#include "books.hpp"

using std::cout, std::endl;

namespace libraryonline{
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
                        cout << "\nSIGN UP selected" << endl;
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

