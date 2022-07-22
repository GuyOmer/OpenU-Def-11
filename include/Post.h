#ifndef USOCIAL_POST_H
#define USOCIAL_POST_H

#include <string>
#include <optional>

#include "Media.h"

class Post {
public:
    explicit Post(std::string);
    Post(std::string, Media *);

    std::string getText();
    Media *getMedia();

private:
    std::string text;
    Media *media;

};

#endif //USOCIAL_POST_H
