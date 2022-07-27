#include "User.h"

#include <utility>
#include <algorithm>
#include <iostream>

unsigned long User::getId() const {
    return id;
}

std::string User::getName() {
    return name;
}

void User::addFriend(User *new_friend) {
    if(new_friend == nullptr) {
        throw std::invalid_argument("Friend to add cannot be null");
    }

    // assert not already friends
    if(std::find(friends.begin(), friends.end(), new_friend->getId()) != friends.end()) {
        throw std::invalid_argument(new_friend->getName() + std::string(" is already a friend"));
    }

    if (new_friend == this) {
        throw std::invalid_argument("Cannot friend myself");
    }

    friends.push_back(new_friend->getId());
}

void User::removeFriend(User &friend_to_remove) {
    if(std::find(friends.begin(), friends.end(), friend_to_remove.getId()) == friends.end()) {
        throw std::invalid_argument("Cannot unfriend non-friends");
    }

    friends.remove(friend_to_remove.getId());
}

void User::post(std::string text) {

    post(new Post(std::move(text)));
}

void User::post(std::string text, Media *media) {
    post(new Post(std::move(text), media));
}

void User::post(Post *post) {
    posts.push_back(post);
}

std::list<Post *> User::getPosts() {
    return posts;
}

void User::viewFriendsPosts() {
    User *friend_user = nullptr;

    for (auto frd_id: friends) {
        friend_user = us->getUserById(frd_id);

        (void) printf("%s (%lu) Posts:\n", friend_user->getName().c_str(), friend_user->getId());

        for (auto post: friend_user->posts) {
            std::cout << "\t'" << post->getText() << "'";
            if (post->getMedia() != nullptr) {
                std::cout << ", With Media: " << post->getMedia()->getMediaType()  << std::endl;
            } else {
                std::cout << ", Without media" << std::endl;
            }
        }
    }
}

void User::receiveMessage(Message *&msg) {
    if (receivedMsgs.empty()) {
        throw std::runtime_error("Messages list is empty");
    }
    *msg = *receivedMsgs.front();
    receivedMsgs.pop_front();
}

void User::sendMessage(User *to, Message *msg) { // NOLINT(readability-convert-member-functions-to-static)
    to->receivedMsgs.push_back(msg);
}

void User::viewReceivedMessages() {
    for (auto msg: receivedMsgs) {
        std::cout << msg->getText() << std::endl;
    }
}

User::~User() {
    while(!posts.empty()) delete posts.front(), posts.pop_front();
    while(!receivedMsgs.empty()) delete receivedMsgs.front(), receivedMsgs.pop_front();
}
