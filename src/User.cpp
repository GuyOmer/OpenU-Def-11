#include "User.h"

#include <utility>
#include <iostream>

unsigned long User::getId() {
    return id;
}

std::string User::getName() {
    return name;
}

void User::addFriend(User *new_friend) {
    friends.push_back(new_friend->getId());
}

void User::removeFriend(User &friend_to_remove) {
    friends.remove(friend_to_remove.getId());
}

void User::post(std::string text) {
    post(new Post(std::move(text)));
}

void User::post(std::string text, Media &media) {
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

void User::sendMessage(User &to, Message *msg) {
    to.receivedMsgs.push_back(msg);
}

void User::viewReceivedMessages() {
    for (auto msg: receivedMsgs) {
        std::cout << msg->getText() << std::endl;
    }
}

User::~User() {

}

User::User() {

}
