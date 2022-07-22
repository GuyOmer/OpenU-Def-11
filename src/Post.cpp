#include "Post.h"

Post::Post(std::string msg) {
    text = std::move(msg);
    media = nullptr;
}

Post::Post(std::string msg, Media &post_media) {
    text = std::move(msg);
    media = *post_media;
}

std::string Post::getText() {
    return text;
}

Media *Post::getMedia() {
    return media;
}
