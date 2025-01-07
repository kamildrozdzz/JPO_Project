#include <mysql.h>
#include <user.hpp>
#include <string>
#include <iostream>
#include <conio.h>

using std::cout, std::cin, std::endl;

User::User(int id, std::string name, std::string surname, std::string email, std::string password, std::string status) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->password = password;
    this->status = status;
}

User::User() {
    this->id = 0;
    this->name = "Unknown";
    this->surname = "Unknown";
    this->email = "Unknown";
    this->password = "Unknown";
    this->status = "Aktywny";
}

int User::getUserID(void) const {
    return id;
}

std::string User::getUserName(void) const {
    return name;
}

std::string User::getSurname(void) const {
    return surname;
}

std::string User::getEmail(void) const {
    return email;
}

std::string User::getStatus(void) const {
    return status;
}

void User::getUserInfo(void) const{
    cout<< "ID: " + std::to_string(id) + "\n" +
               "Name: " + name + "\n" +
               "Surname: " + surname + "\n" +
               "Email: " + email + "\n" +
               "Password: " + password + "\n" +
               "Status: " + status + "\n";
}

void User::setUser(int id, std::string name, std::string surname, std::string email, std::string status) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->status = status;
}
