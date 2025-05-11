#include "Aleynik_LR5_6_AbstractMediaResource.h"
#include "Aleynik_LR5_6_ChildBook.h"
#include "Aleynik_LR5_6_ChildDVD.h"
#include "Aleynik_LR5_6_MultiDigitalResource.h"

vector<unique_ptr<MediaResource>> vectorMediaResource;


void showMediaResource() {
    if (vectorMediaResource.size() > 0) {
        for (auto it = vectorMediaResource.begin(); it != vectorMediaResource.end(); ++it) {
            cout << (it - vectorMediaResource.begin()) << ": ";
            cout << **it;
        }
    }
}
MediaResource* vspom(const string& mes) {
    showMediaResource();
    int number = 0;
    enterInteger(number, "Enter the number of " + mes, 0, vectorMediaResource.size());
    MediaResource* basePtr = vectorMediaResource[number].get();
    return basePtr;
}
void createNewBook() {
    Book *objBook = new Book;
    cin >> *objBook;
    vectorMediaResource.emplace_back(objBook);
}
void createCopyBook() {
    Book* source = dynamic_cast<Book*>(vspom("Book"));
    if (!source) {
        cerr << "ERROR! This is not Book\n";
        return;
    }
    Book* copy = new Book(*source);
    vectorMediaResource.emplace_back(copy);
}
void createModifyBook() {
    string nameBook = "";
    enterString(nameBook, "Enter the name of book: ");
    vectorMediaResource.emplace_back(make_unique<Book>(nameBook));
}
void createNewDVD() {
    DVD *objDVD = new DVD;
    cin >> *objDVD;
    vectorMediaResource.emplace_back(objDVD);
}
void createModifyDVD() {
    string nameDVD = "";
    enterString(nameDVD, "Enter the name of book: ");
    vectorMediaResource.emplace_back(make_unique<DVD>(nameDVD));
}
void createCopyDVD() {
    DVD* source = dynamic_cast<DVD*>(vspom("DVD"));
    if (!source) {
        cerr << "ERROR! This is not Book\n";
        return;
    }
    DVD* copy = new DVD(*source);
    vectorMediaResource.emplace_back(copy);
}
void demonstratePolymorphism() {
    for (const auto& MediaResource : vectorMediaResource) {
        cout << *MediaResource;
        cout << "Rent: "; MediaResource->rent(); cout << endl;
        cout << "Return: "; MediaResource->returnResource(); cout << endl;
        cout << "==========================" << endl;
    }
}
void demonstrateAdd() {
    Book* sourceB = dynamic_cast<Book*>(vspom("Book"));
    if (!sourceB) {
        cerr << "ERROR! This is not Book\n";
        return;
    }
    auto combinedBook = *sourceB + *sourceB;
    vectorMediaResource.emplace_back(combinedBook);

    DVD* sourceD = dynamic_cast<DVD*>(vspom("DVD"));
    if (!sourceD) {
        cerr << "ERROR! This is not DVD\n";
        return;
    }
    auto combinedDVD = *sourceD + *sourceD;
    vectorMediaResource.emplace_back(combinedDVD);
}

void createDigitalResource() {
    DigitalResource* objDigitalResource = new DigitalResource;
    cin >> *objDigitalResource;
    vectorMediaResource.emplace_back(objDigitalResource);
}
