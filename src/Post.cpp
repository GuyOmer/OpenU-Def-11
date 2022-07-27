#include "Post.h"

#include <utility>

Post::Post(std::string msg, Media *post_media) {
    if (msg.length() == 0 && post_media != nullptr) {
        throw std::runtime_error("Posts cannot be empty");
    }
    text = std::move(msg);
    media = post_media;
}

std::string Post::getText() {
    return text;
}

Media *Post::getMedia() {
    return media;
}

Post::~Post() {
    delete media;
}
