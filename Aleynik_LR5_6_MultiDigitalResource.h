#ifndef _DIGITAL_RESOURCE_H_
#define _DIGITAL_RESOURCE_H_

#include "Aleynik_LR5_6_AbstractMediaResource.h"
#include "Aleynik_LR5_6_ParentLicenseValidator.h"

class DigitalResource : virtual public MediaResource, virtual public LicenseValidator {
    private:
        string licenseKey;
        string format;

    public:
        //constructors
        DigitalResource()
            : MediaResource(), licenseKey(""), format("") {}
        DigitalResource(int id, const string& title, const string& licenseKey, const string& format)
            : MediaResource(id, title), licenseKey(licenseKey), format(format) {}
        ~DigitalResource() override = default;

        //methods
        bool isLicenseValid(const string& key) const override {
            return !key.empty() && key.size() >= 10;
        }
        bool isFormatSupported(const string& format) const override {
            return format == "PDF" || format == "EPUB" || format == "MP4";
        }
        void rent() override {
            if (isLicenseValid(licenseKey) && isFormatSupported(format)) {
                setIsAvailable(false);
                cout << "You've successfully rented " << this->getTitle() << " license " << this->licenseKey << endl;
            } else { cout << "It is temporarily impossible to rent"; }
        }
        void returnResource() override {
            setIsAvailable(true);
            cout << this->getTitle() << " license " << this->licenseKey << " is no longer rented" << endl;
        }
        MediaResource* clone() const override { return new DigitalResource(*this); }
    protected:
        ostream& display(ostream& os) const override {
            os << "Digital Resource[ID: " << getId()
            << ", Title: " << getTitle()
            << ", Format: " << format
            << ", License: "  << licenseKey
            << ", Availability: " << (getIsAvailable() ? "Available" : "Unavailable")
            << "]";
            return os;
        }

        istream& input(istream& is) override {
            enterString(licenseKey, "Enter the license: ", is);
            enterString(title, "Enter the title: ", is);
            enterString(format, "Enter the amount of pages: ", is);
            return is;
        }

};

#endif // _DIGITAL_RESOURCE_H_
