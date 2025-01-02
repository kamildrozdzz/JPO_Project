#ifndef USERS_HPP
#define USERS_HPP

#include <string>

class users {
    private:
        int id;       
        std::string name;
        std::string surname;
        std::string email;
        std::string password;
        std::string status;
    
    public:
        void getUserInfo(void) const;
        std::string login(MYSQL* conn);
        std::string singup(MYSQL* conn);
        int pin(void);
        void updateUser(MYSQL* conn);
};

#endif // USERS_HPP
