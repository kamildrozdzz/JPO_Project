#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

using std::cout, std::cin, std::endl, std::string;

#define HOST "127.0.0.1"    //db parameters
#define USER "root"
#define PASS "root"
#define DATABASE "libraryonline"
#define PORT 3306

string user_name{};

MYSQL* conn;
MYSQL_RES* res_set;
MYSQL_ROW row;
std::stringstream stmt;
const char * q;
std::string query;

#endif // GLOBALS_HPP
