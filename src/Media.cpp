#include <iostream>

#include "Media.h"

std::string Photo::getMediaType() {
    return "Photo";
};

std::string Video::getMediaType() {
    return "Video";
};

std::string Audio::getMediaType() {
    return "Audio";
};

void Media::display() {
    std::cout << getMediaType() << std::endl;
}
