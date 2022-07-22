//
// Created by a on 15/07/2022.
//

#ifndef USOCIAL_MESSAGE_H
#define USOCIAL_MESSAGE_H

class Message {
public:
    Message(std::string msg);
    std::string getText();

private:
    std::string text;
};


#endif //USOCIAL_MESSAGE_H
