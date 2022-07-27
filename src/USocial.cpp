//
// Created by a on 15/07/2022.
//

#include <stdexcept>

#include "USocial.h"
#include "Buisness_User.h"

User *USocial::registerUser(std::string name, bool is_business_user) {
    User *new_user = is_business_user ? reinterpret_cast<User *>(new BusinessUser) : new User();

    if(name.length() == 0) {
        throw std::invalid_argument("Name cannot be of length zero");
    }

    new_user->us = this;
    new_user->id = ids_index++;
    new_user->name = std::move(name);

    users[new_user->getId()] = new_user;

    return new_user;
}

void USocial::removeUser(User *user) {
    if (user == nullptr) {
        throw std::invalid_argument("User to remove must be valid");
    }

    auto users_deleted = users.erase(user->getId());

    if (users_deleted == 0) {
        throw std::invalid_argument("Cannot remove non-existent user");
    }
    // Shouldn't ever happen
    else if (users_deleted > 1) {
        throw std::runtime_error("Multiple users with the same ID were deleted");
    }
}

User *USocial::getUserById(unsigned long id) {
    auto lookedup_user =  users[id];
    if(lookedup_user == nullptr) {
        throw std::invalid_argument("Couldn't find user with given ID");
    }

    return lookedup_user;
}

USocial::~USocial() {
    for (auto const &u : users) {
        delete u.second;
    }
    users.clear();
}
