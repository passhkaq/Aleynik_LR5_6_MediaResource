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
        DVD() {}
        DVD(const DVD& other) : director(other.director), duration(other.duration),
            isDamaged(other.isDamaged) {}
        DVD(const int& id) : MediaResource(id) {}
        ~DVD() {}

        //methods

};



#endif //_ALEYNIK_LR5_6_CHILD_DVD_H
