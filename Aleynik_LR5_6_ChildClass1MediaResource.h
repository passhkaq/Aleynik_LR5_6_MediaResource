#ifndef _ALEYNIK_LR5_6_CHILDCLASS1MEDIARESOURCE_H_
#define _ALEYNIK_LR5_6_CHILDCLASS1MEDIARESOURCE_H_
#include "Aleynik_LR5_6_AbstractClassMediaResource.h"

class Book : virtual public MediaResource {
    private:
        string author;
        int pages;
        string dueDate;
    public:
        Book() {}

};




#endif //_ALEYNIK_LR5_6_CHILDCLASS1MEDIARESOURCE_H_
