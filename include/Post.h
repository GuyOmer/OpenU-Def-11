#ifndef USOCIAL_POST_H
#define USOCIAL_POST_H

#include <string>
#include <optional>
#include <utility>

#include "Media.h"

class Post {
public:
    Post(std::string text, Media *media);
    explicit Post(std::string text) : Post(std::move(text), nullptr) {};
    ~Post();

    std::string getText();
    Media *getMedia();

private:
    std::string text;
    Media *media;

};

#endif //USOCIAL_POST_H
