#ifndef USOCIAL_USER_H
#define USOCIAL_USER_H


#include <string>
#include <list>

#include "Message.h"
#include "Post.h"
#include "USocial.h"

class USocial;

class User {
protected:
    USocial *us;
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMsgs;

    User()  = default;
    ~User() = default;

    friend class USocial;
public:
    unsigned long getId() const;
    std::string getName();
    void addFriend(User *);
    void removeFriend(User &);
    void post(std::string);
    void post(std::string, Media *);
    void post(Post *);
    std::list<Post *> getPosts();
    void viewFriendsPosts();
    void receiveMessage(Message *&);
    static void sendMessage(User *, Message *);
    void viewReceivedMessages();
};


#endif //USOCIAL_USER_H
