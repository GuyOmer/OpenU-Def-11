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

    ~USocial();
private:
    std::map<unsigned long, User *> users;

    // Population is hopefully less than 2^64
    unsigned long ids_index = 1;
};


#endif //USOCIAL_USOCIAL_H
