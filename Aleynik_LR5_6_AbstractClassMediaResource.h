#ifndef _ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
#define _ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
#include "Aleynik_LR5_6_defMediaResourse.h"


class MediaResource {
    private:
        int id;
        string title;
        bool isAvailable;
    public:
        //constructors
        MediaResource() {}
        MediaResource(const MediaResource& other) : id(other.id), title(other.title),
            isAvailable(other.isAvailable) {}
        MediaResource(const int& id) : id(id) {}
        virtual ~MediaResource() {}

        //getters-setters
        const int& getId() const { return id; }
        const string& getTitle() const { return title; }
        const bool& getIsAvailable() const { return isAvailable; }
        void setId(int id) { this->id = id; }
        void setTitle(string title) { this->title = title; }
        void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }

        //methods
        virtual void rent();
        virtual void returnResource();
        const MediaResource& operator = (const MediaResource& other);
        friend ostream& operator << (ostream& os, const MediaResource& MediaResource) {
            return MediaResource.display(os);
        }
        friend istream& operator >> (istream& is, MediaResource& MediaResource) {
            return MediaResource.input(is);
        }

    protected:
        virtual ostream& display(ostream& os) const = 0;
        virtual istream& input(istream& is);
};


#endif //_ALEYNIK_LR5_6_ABSTRACTCLASSMEDIARESOURCE_H_
