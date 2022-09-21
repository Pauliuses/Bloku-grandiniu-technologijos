#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::cout;
using std::endl;

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
string Hashing(string key)
{
    static const string hex = "0123456789abcdef";
    string finalHex;
    unsigned int hash;
    const int code = 31;

    for (int i = 0; i < key.length(); i++)
    {
        hash = (hash * code) + int(key[i]);
    }

    string hashString = to_string(hash);

    unsigned int hexSymbol = hash;

    int SizeOfHashString = hashString.size();

    for (int i = 0; i < 64; i++)
    {
        hexSymbol += int(hashString[i % SizeOfHashString]) + i; // pridedame i nes su tekstu "a" gaunasi blogas hash

        finalHex += hex[hexSymbol % 16];
    }
    return finalHex;
}