//
// Created by a on 15/07/2022.
//

#ifndef USOCIAL_USOCIAL_H
#define USOCIAL_USOCIAL_H

#include <map>

#include "User.h"

class User;

class USocial {
public:
    User *registerUser(std::string, bool = false);
    void removeUser(User *);
    User *getUserById(unsigned long);
private:
    std::map<unsigned long, User *> users;
};


#endif //USOCIAL_USOCIAL_H
