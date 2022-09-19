#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;

#include "head.h"

bool InputBool(std::string text)
{
    std::string temp;
    cout << text;
    std::cin >> temp;
    while (temp != "0" && temp != "1")
    {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        std::cin >> temp;
    }
    return temp == "1";
}
unsigned int Hashing(string key)
{
    static const string hex = "0123456789abcdef";
    unsigned int hashed = 111;
    const int hx = 31;
    for (int i = 0; i < key.length(); i++)
    {
        cout << "key " << int(key[i]) << endl;
        cout << hashed * hx << endl;
        hashed = (hashed * hx) + int(key[i]);
        cout << "current " << hashed << endl;
        cout << endl;
    }
    return hashed;
}