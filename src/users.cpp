#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "../include/users.hpp"
#include <string>
#include <iostream>
#include <conio.h>

using std::cout, std::cin, std::endl;

void users::getUserInfo(void) const{
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "           YOUR ACC." << endl;
    cout << "--------------------------------" << endl;
    cout<< "ID: " + std::to_string(id) + "\n" +
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
    
    char ch;
    password = "";
    while((ch = _getch()) != '\r'){
        if(ch == '\b'){ 
            if(!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << std::endl;

    std::string query = "Select * from uzytkownicy;";
    const char * q = query.c_str();
    mysql_query(conn,q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};
    while( (row = mysql_fetch_row(res_set)) != NULL){
        if(row[1]==name && row[4]==password){
            surname = row[2];
            email = row[3];
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

int users::pin(void){
    int num = 0 ;
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "       ENTER YOUR PIN" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter password : ";
    for(int i = 0; i < 4; i++){
        num=num*10+(getch()-48);
        cout<<"*";
    }
    cout << endl;
    return num;
}

void users::updateUser(MYSQL* conn) {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         UPDATE USER" << endl;
    cout << "--------------------------------" << endl;

    // Display current users
    std::string query = "SELECT id_uzytkownika, imie, nazwisko, email, status FROM uzytkownicy;";
    const char* q = query.c_str();
    mysql_query(conn, q);
    MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};

    cout << "Current users in the database:" << endl;
    while ((row = mysql_fetch_row(res_set)) != NULL) {
        cout << "ID: " << row[0] << " - Name: " << row[1] << " - Surname: " << row[2] << " - Email: " << row[3] << " - Status: "<< row[4] << endl;
    }
    cout << "--------------------------------" << endl;

    int userId;
    cout << "Enter the ID of the user to update: ";
    cin >> userId;

    std::cin.ignore(10000, '\n');

    cout << "Enter the new name (leave empty to keep current): ";
    std::getline(cin, name);

    cout << "Enter the new surname (leave empty to keep current): ";
    std::getline(cin, surname);

    cout << "Enter the new email (leave empty to keep current): ";
    std::getline(cin, email);

    cout << "Enter the new status (leave empty to keep current): ";
    std::getline(cin, status);

    query = "UPDATE uzytkownicy SET ";
    if (!name.empty()) query += "imie = '" + name + "', ";
    if (!surname.empty()) query += "nazwisko = '" + surname + "', ";
    if (!email.empty()) query += "email = '" + email + "', ";
    if (!status.empty()) query += "status = '" + status + "', ";
    query.pop_back();
    query.pop_back();
    query += " WHERE id_uzytkownika = " + std::to_string(userId) + ";";

    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if (!res_set) {
        cout << "User updated successfully." << endl;
    } else {
        cout << "Error updating user. Check database connection." << endl;
    }
}
