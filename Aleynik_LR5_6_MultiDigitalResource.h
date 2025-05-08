#ifndef _DIGITAL_RESOURCE_H_
#define _DIGITAL_RESOURCE_H_

#include "Aleynik_LR5_6_AbstractMediaResource.h"
#include "Aleynik_LR5_6_ParentLicenseValidator.h"

class DigitalResource : public MediaResource, public LicenseValidator {
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
        } else {
            std::cout << "Rent failed: invalid license or unsupported format.\n";
        }
    }
    void displayInfo() const {
        std::cout << "DigitalResource ID: " << getId()
                << ", Title: " << getTitle()
                << ", Format: " << format
                << ", License: " << licenseKey
                << ", Available: " << (isAvailable ? "Yes" : "No") << "\n";
    }
};

#endif // _DIGITAL_RESOURCE_H_
