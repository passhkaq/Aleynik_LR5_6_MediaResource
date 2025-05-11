#ifndef _ALEYNIK_LR5_6_CHILD_DVD_H
#define _ALEYNIK_LR5_6_CHILD_DVD_H
#include "Aleynik_LR5_6_AbstractMediaResource.h"


class DVD final : virtual public MediaResource {
    private:
        string director;
        int duration;
        bool isDamaged;
    public:
        //constructors
        DVD()
        : MediaResource(), director(""), duration(0), isDamaged(false) {}
        DVD(string title)
        : MediaResource(title), director(""), duration(0), isDamaged(false) {}
        DVD(int id, string title, string director, int duration, bool isDamaged)
        : MediaResource(id, title),
            director(std::move(director)),
            duration(duration),
            isDamaged(isDamaged) {}
        DVD(const int& id) : MediaResource(id) {}
        ~DVD() override {}

        //methods
        void rent() override {
            if (isDamaged == false && validate() == true) {
                isAvailable = false;
                cout << "You've successfully rented " << this->getTitle() << " by " << this->director << endl;
            } else { cout << "It is temporarily impossible to rent"; }
        }
        bool validate() const {
            return duration > 0;
        }
        void returnResource() override {
            int randomNum = rand() % 5;
            if (randomNum == 2) {
                isDamaged = true;
            }
            setIsAvailable(true);
            cout << this->getTitle() << " by " << this->director << " is no longer rented" << endl;
        }
        void markAsDamaged() {
            isDamaged = true;
        }
        DVD* clone() const override { return new DVD(*this); }
        DVD operator+(const DVD& other) const {
            DVD result(*this);
            if (result.director == other.director) {
                string newTitle = result.getTitle() + " & " + other.getTitle();
                int randomID = rand() % 100 + 200;
                result.setTitle(newTitle);
                result.setId(randomID);
                result.setIsAvailable(true);
            } else {
                std::cout << "Cannot combine DVDs with different directors.\n";
            }
            return result;
        }
    protected:
        ostream& display(ostream& os) const override {
            os << "DVD[ID: " << getId()
            << ", Title: " << getTitle()
            << ", Director: " << director
            << ", duration: "  << duration
            << ", Damaged: " << (isDamaged ? "Yes" : "No")
            << ", Availability: " << (getIsAvailable() ? "Available" : "Unavailable")
            << "]";
            return os;
        }

        istream& input(istream& is) override {
            // MediaResource::input(is);
            enterString(director, "Enter the author: ", is);
            enterString(title, "Enter the title: ", is);
            enterInteger(duration, "Enter the duration: ", 1, 99999, is);
            return is;
        }
};



#endif //_ALEYNIK_LR5_6_CHILD_DVD_H
