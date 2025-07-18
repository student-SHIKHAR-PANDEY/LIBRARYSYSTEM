#include "user.h"
#include <iostream>

User::User() {}

User::User(std::string name, int userId, std::string role, std::string username, std::string password)
    : name(name), userId(userId), role(role), username(username), password(password) {}

void User::display() {
    std::cout << "Name: " << name << ", Role: " << role << "\n";
}

int User::getId() {
    return userId;
}

std::string User::getRole() {
    return role;
}

bool User::verifyLogin(const std::string &inputUsername, const std::string &inputPassword) {
    return (username == inputUsername && password == inputPassword);
}
