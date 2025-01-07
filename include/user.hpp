#ifndef USERS_HPP
#define USERS_HPP

#include <string>

class User {
    private:
        int id;       
        std::string name;
        std::string surname;
        std::string email;
        std::string password;
        std::string status;
    
    public:
        User(int id, std::string name, std::string surname, std::string email, std::string password, std::string status="Aktywny");
        User();
        void getUserInfo(void) const;
        int getUserID(void) const;
        std::string getUserName(void) const;
        std::string getSurname(void) const;
        std::string getEmail(void) const;
        std::string getStatus(void) const;
        int pin(void);
        void setUser(int id, std::string name, std::string surname, std::string email, std::string status);
};

#endif // USERS_HPP
