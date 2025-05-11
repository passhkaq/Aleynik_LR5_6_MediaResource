#ifndef _ALEYNIK_LR5_6_CHILDBOOK_H_
#define _ALEYNIK_LR5_6_CHILDBOOK_H_
#include "Aleynik_LR5_6_AbstractMediaResource.h"


class Book : virtual public MediaResource {
    private:
        string author;
        int pages;
        int dueDate;
    public:
        //constructors
        Book()
        : MediaResource(), author(""), pages(0), dueDate(0) {}
        Book(string title)
        : MediaResource(title), author(""), pages(0), dueDate(0) {}
        Book(int id, string title, string author, int pages, int due)
        : MediaResource(id, title),
            author(std::move(author)),
            pages(pages),
            dueDate(due) {}
        Book(const int& id) : MediaResource(id) {}
        ~Book() override {}

        //methods
        void rent() override {
            if (validate()) {
                dueDate = 30;
                setIsAvailable(false);
                cout << "You've successfully rented " << this->getTitle() << " by " << this->author << endl;
            } else { cout << "It is temporarily impossible to rent"; }
        }
        bool validate() const {
            return pages > 0;
        }
        void extendRental() {
            dueDate = 45;
            cout << "You've successfully extended rental on 15 days" << endl;
        }
        void returnResource() override {
            dueDate = 0;
            setIsAvailable(true);
            cout << this->getTitle() << " by " << this->author << " is no longer rented" << endl;
        }
        Book* clone() const override { return new Book(*this); }
        Book operator+(const Book& other) const {
            Book result(*this);
            if (result.author == other.author) {
                string newTitle = result.getTitle() + " & " + other.getTitle();
                int randomID = rand() % 100 + 100;
                result.setTitle(newTitle);
                result.setId(randomID);
                result.setIsAvailable(true);
                result.pages += other.pages;
            }
            return result;
        }
    protected:
        ostream& display(ostream& os) const override {
            os << "Book[ID: " << getId()
            << ", Title: " << getTitle()
            << ", Author: " << author
            << ", Pages: "  << pages
            << ", Availability: " << (getIsAvailable() ? "Available" : "Unavailable")
            << "]";
            return os;
        }

        istream& input(istream& is) override {
            // MediaResource::input(is);
            enterString(author, "Enter the author: ", is);
            enterString(title, "Enter the title: ", is);
            enterInteger(pages, "Enter the amount of pages: ", 1, 99999, is);
            return is;
        }
};


#endif //_ALEYNIK_LR5_6_CHILDBOOK_H_
