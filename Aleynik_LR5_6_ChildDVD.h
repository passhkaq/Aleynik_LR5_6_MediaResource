#ifndef _ALEYNIK_LR5_6_CHILD_DVD_H
#define _ALEYNIK_LR5_6_CHILD_DVD_H

#include "Aleynik_LR5_6_AbstractMediaResource.h"

class DVD final : virtual public MediaResource {
    private:
        string director;
        int duration;
        bool isDamaged;
        map<string, vector<string>> collection;
    public:
        //constructors
        DVD()
        : MediaResource(), director(), duration(0), isDamaged() {}
        DVD(int id, string title, string director, int duration, bool isDamaged)
        : MediaResource(id, title),
            director(move(director)),
            duration(duration),
            isDamaged(isDamaged) {}
        DVD(const int& id) : MediaResource(id) {}
        ~DVD() override {}

        //methods
        void rent() override {
            if (isDamaged == false && validate() == true) {
                isAvailable = false;
            }
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
        }
        void markAsDamaged() {
            isDamaged = true;
        }
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
        ostream& display(ostream& os) const override {
            os << "Title: " << getTitle()
            << ", Director: " << director
            << ", Duration: " << duration
            << ", ID: " << getId()
            << ", Damaged: " << (isDamaged ? "Yes" : "No")
            << ", Availability=" << (getIsAvailable() ? "Available" : "Unavailable");
            return os;
        }
    protected:
        ostream& display(ostream& os) const override {
            os << "Book[ID=" << getId()
            << ", Title=" << getTitle()
            << ", Director=" << director
            << ", duration="  << duration
            << ", Damaged: " << (isDamaged ? "Yes" : "No")
            << ", Availability=" << (getIsAvailable() ? "Available" : "Unavailable")
            << "]";
            return os;
        }

        istream& input(istream& is) override {
            is >> id >> title >> director >> duration;
            return is;
        }
};



#endif //_ALEYNIK_LR5_6_CHILD_DVD_H
