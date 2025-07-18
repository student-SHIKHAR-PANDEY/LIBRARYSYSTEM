#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    int userId;
    std::string role;
    std::string username;
    std::string password;

public:
    User();
    User(std::string name, int userId, std::string role, std::string username, std::string password);
    void display();
    int getId();
    std::string getRole();
    bool verifyLogin(const std::string &inputUsername, const std::string &inputPassword);
};

#endif
