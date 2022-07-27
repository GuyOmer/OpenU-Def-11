#ifndef USOCIAL_MEDIA_H
#define USOCIAL_MEDIA_H

class Media {
public:
    Media() = default;
    virtual ~Media() = default;

    void display();
    virtual std::string getMediaType() = 0;
};

class Photo : public Media {
    std::string getMediaType() override;
};

class Audio : public Media {
    std::string getMediaType() override;
};

class Video : public Media {
    std::string getMediaType() override;
};

#endif //USOCIAL_MEDIA_H
