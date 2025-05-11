#ifndef _ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
#define _ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
#include "Aleynik_LR5_6_defMediaResource.h"


class MediaResource {
    public:
        //constructors
        MediaResource()
        : title(""), id(0), isAvailable(true) {}
        MediaResource(string title)
        : title(title), id(0), isAvailable(true) {}
        MediaResource(const MediaResource& other) : id(other.id), title(other.title),
            isAvailable(other.isAvailable) {}
        MediaResource(int id, string title) : id(id), title(std::move(title)), isAvailable(true) {}
        MediaResource(const int& id) : id(id) {}
        virtual ~MediaResource() = default;

        //getters-setters
        const int& getId() const { return id; }
        const string& getTitle() const { return title; }
        const bool& getIsAvailable() const { return isAvailable; }
        void setId(int id) { this->id = id; }
        void setTitle(string title) { this->title = title; }
        void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }

        //methods
        virtual void rent() = 0;
        virtual void returnResource() = 0;
        virtual MediaResource* clone() const = 0;
        const MediaResource& operator = (const MediaResource& other);
        friend ostream& operator << (ostream& os, const MediaResource& MediaResource) {
            return MediaResource.display(os);
        }
        friend istream& operator >> (istream& is, MediaResource& MediaResource) {
            return MediaResource.input(is);
        }

    protected:
        string title;
        int id;
        bool isAvailable;
        virtual ostream& display(ostream& os) const = 0;
        virtual istream& input(istream& is) = 0;
};


#endif //_ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
