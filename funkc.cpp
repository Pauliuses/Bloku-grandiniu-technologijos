#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

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
string ReadFromFile(std::string fileName)
{
    static const string hex = "0123456789abcdef";
    string finalHex;
    unsigned int hash;
    const int code = 31;

    std::ifstream fd;
    fd.open(fileName);

    std::stringstream strStream;
    strStream << fd.rdbuf();
    std::string str = strStream.str();

    using hrClock = std::chrono::high_resolution_clock;
    hrClock::time_point start, end;
    std::chrono::duration<double> time;
    start = hrClock::now();
    if (fd.good())
    {

        for (int i = 0; i < str.length(); i++)
        {
            hash = (hash * code) + int(str[i]);
            if(str.length()-1 == i)
            cout << "simboliu kiekis: " << str.length() <<endl;
        }

        string hashString = to_string(hash);

        unsigned int hexSymbol = hash;

        int SizeOfHashString = hashString.size();

        for (int i = 0; i < 64; i++)
        {
            hexSymbol += int(hashString[i % SizeOfHashString]) + i; // pridedame i nes su tekstu "a" gaunasi blogas hash

            finalHex += hex[hexSymbol % 16];
        }
        end = hrClock::now();
        time = end - start;
        cout << "Hashavimo funkcijos veikimo laikas:  " << time.count() << endl;
        return finalHex;
    }
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