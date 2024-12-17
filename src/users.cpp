#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "../include/users.hpp"
#include <string>
#include <iostream>
#include <conio.h>

using std::cout, std::cin, std::endl;

std::string users::getUserInfo(void) const{
    return "ID: " + std::to_string(id) + "\n" +
               "Name: " + name + "\n" +
               "Surname: " + surname + "\n" +
               "Email: " + email + "\n" +
               "Password: " + password + "\n";
}

std::string users::login(MYSQL* conn){
    cout << "--------------------------------" << endl;
    cout << "           LOG IN" << endl;
    cout << "--------------------------------" << endl;
        
    std::cout << "Enter your user name:\n";
    std::cin >> name;
    std::cout << "Enter your password:\n";
    std::cin >> password;

    std::string query = "Select * from uzytkownicy;";
    const char * q = query.c_str();
    mysql_query(conn,q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};
    while( (row = mysql_fetch_row(res_set)) != NULL){
        if(row[1]==name && row[4]==password){
            cout << "Pomyślne logowanie" << endl;
            return name;
        }
    }
    cout << "Podano błędne dane logowania";
    return "error";
}

std::string users::singup(MYSQL* conn){
    cout << "--------------------------------" << endl;
    cout << "           SING UP" << endl;
    cout << "--------------------------------" << endl;

    std::string name{}, surname{}, email{}, password{};
    
    std::cout << "Enter your user name:\n";
    std::cin >> name;
    std::cout << "Enter your surrname:\n";
    std::cin >> surname;
    std::cout << "Enter your email:\n";
    std::cin >> email;
    std::cout << "Enter your password:\n";
    std::cin >> password;

    std::string query = "Select * from uzytkownicy;";
    const char * q = query.c_str();
	mysql_query(conn,q);
	MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};
	while( (row = mysql_fetch_row(res_set)) != NULL)
	{
		if(row[3]==email){
            cout << "Użytkownik o podanym adresie email istnieje!" << endl;
            cout << "Spróbuj ponownie...";
            getch();
            system("cls");
            singup(conn);
        }
	}
    query = "INSERT INTO uzytkownicy (imie, nazwisko, email, haslo) VALUES ('" 
                    + name + "', '" 
                    + surname + "', '" 
                    + email + "', '" 
                    + password + "');";
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
	if (!(res_set))
        cout <<"Successfully" <<endl;
    else
        cout <<"ERROR!"<< endl;
    return name;
}
