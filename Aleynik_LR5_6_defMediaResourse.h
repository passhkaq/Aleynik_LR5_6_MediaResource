#ifndef _ALEYNIK_LR5_6_DEFMEDIARESOURCE_H_
#define _ALEYNIK_LR5_6_DEFMEDIARESOURCE_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// entr check
bool userInput(string input, const int& min, const int& max) {
    if (input.empty()) return false;

    try {
        int number = stoi(input);
        if (number < min) {
            cout << "Minimum valid number is " << min << endl;
            return false;
        } else if (number > max) {
            cout << "Maximum valid number is " << max << endl;
            return false;
        }
    } catch (const exception& e) {return false;};
    return true;
}

void enterInteger(int& variable, const string& prompt, const int& min = 0, const int& max = 10000000, istream& is = cin) {
    string input;
    cout << prompt;
    getline(is, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(is, input);
    }
    variable = stoi(input);
}

void enterFloat(double& variable, const string& prompt, const int& min, const int& max, istream& is = cin) {
    string input;
    cout << prompt;
    getline(is, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(is, input);
    }
    variable = stof(input);
}

void enterString(string& variable, const string& prompt, istream& is = cin) {
    cout << prompt;
    string input;
    getline(is, input);
    while (input.empty()) {
        cout << prompt;
        getline(is, input);
    }
    variable = input;
}


#endif //_ALEYNIK_LR5_6_DEFMEDIARESOURCE_H_
