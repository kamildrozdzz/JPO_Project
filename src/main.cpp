#include "../include/globals.hpp"
#include "../include/menu.hpp"

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);       
    #endif

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0); 

    if(conn){
        while (1)
        {
            system("cls");
            libraryonline::main_menu(conn);
        }
    }else{
        system("cls");
        cout << "Error connecting to database. Please contact your administrator..." << endl;
        getch();
    }
}