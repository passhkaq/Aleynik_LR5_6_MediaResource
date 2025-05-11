#include "Aleynik_LR5_6_defMediaResource.h"
#include "Aleynik_LR5_6_MethodsMediaResource.cpp"

struct menuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, menuItem> menu = {
        {1, {"Show media Resource", showMediaResource}},
        {2, {"Create new book", createNewBook}},
        {3, {"Create copy book", createCopyBook}},
        {4, {"Create modify book", createModifyBook}},
        {5, {"Create new DVD", createNewDVD}},
        {6, {"Create copy DVD", createCopyDVD}},
        {7, {"Create modify DVD", createModifyDVD}},
        {8, {"Demonstrate polymorphism", demonstratePolymorphism}},
        {9, {"Demonstrate add", demonstrateAdd}},
        {10, {"Create Digital Resource", createDigitalResource}},
    };

    int choice = 0;

    while (true) {
        cout << "Menu: " << endl;

        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;

        enterInteger(choice, "Enter your choice: ", 0, 10);

        if (choice == 0) {
            cout << "Poka Poka" << endl;
            break;
        } else {
            menu[choice].action();
        }

        cout << endl << endl;
    }

    return 0;
}
