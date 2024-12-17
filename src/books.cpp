#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "../include/books.hpp"
#include <string>
#include <iostream>
#include <conio.h>

using std::cout, std::cin, std::endl;

void books::displayAll(MYSQL* conn) const{
    system("cls");
	std::string query = "Select * from ksiazki;";   //sneding query to db
	const char* q = query.c_str();
	mysql_query(conn,q);
	MYSQL_RES* res_set = mysql_store_result(conn);
    MYSQL_ROW row{};
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
        cout << "Publishing house: " << row[5] << endl;
        cout << "Number of pages: " << row[7] << endl;
        cout << "Year of issue: " << row[8] << endl << endl;
        cout << "--------------------------------" << endl;

        count++;
        if (count%2==0){
            system("pause");
            system("cls");
        }
	}
}