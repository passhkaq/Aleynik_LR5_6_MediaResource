#include "Aleynik_LR5_6_defMediaResourse.h"

struct menuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, menuItem> menu = {
        {1, {"", }},
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
