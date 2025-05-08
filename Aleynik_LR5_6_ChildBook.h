#ifndef _ALEYNIK_LR5_6_CHILDBOOK_H_
#define _ALEYNIK_LR5_6_CHILDBOOK_H_
#include "Aleynik_LR5_6_AbstractMediaResource.h"

class Book : virtual public MediaResource {
    private:
        string author;
        int pages;
        string dueDate;
    public:
        //constructors
        Book() {}
        Book(const Book& other) : author(other.author), pages(other.pages),
            dueDate(other.dueDate) {}
        Book(const int& id) : MediaResource(id) {}
        ~Book() {}

        //methods
        void rent() override { dueDate = 30; }
        bool validate() const { if (pages > 0) { return true; } else { return false; } }
        void displayinfo() {}
        void extendRental();
        const Book& operator + (const Book& other);
};

#endif //_ALEYNIK_LR5_6_CHILDBOOK_H_
