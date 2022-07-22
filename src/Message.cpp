#include <string>
#include <utility>

#include "Message.h"

Message::Message(std::string msg) {
    text = std::move(msg);
}

std::string Message::getText() {
    return text;
}
