//
// Created by a on 15/07/2022.
//

#include <stdexcept>

#include "USocial.h"
#include "Buisness_User.h"

User *USocial::registerUser(std::string name, bool is_business_user) {
    User * new_user = is_business_user ? reinterpret_cast<User *>(new BusinessUser) : new User();
    std::hash<std::string> nameHash;

    new_user->us = this;
    new_user->id = nameHash(name);
    new_user->name = std::move(name);

    users[new_user->getId()] = new_user;

    return new_user;
}

void USocial::removeUser(User *user) {
    if (!users.erase(user->getId())) {
        throw std::invalid_argument("Cannot remove non-existent user");
    }
}

User *USocial::getUserById(unsigned long id) {
    return users[id];
}
