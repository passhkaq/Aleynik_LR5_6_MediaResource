#ifndef _ALEYNIK_LR5_6_PARENTLECENSEVALIDATOR_H
#define _ALEYNIK_LR5_6_PARENTLECENSEVALIDATOR_H

#include "Aleynik_LR5_6_defMediaResource.h"

class LicenseValidator {
    protected:
        virtual ~LicenseValidator() = default;

        virtual bool isLicenseValid(const string& licenseKey) const = 0;

        virtual bool isFormatSupported(const string& format) const = 0;
};

#endif //_ALEYNIK_LR5_6_PARENTLECENSEVALIDATOR_H
