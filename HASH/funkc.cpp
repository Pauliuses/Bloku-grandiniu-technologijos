#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

using std::cout;
using std::endl;

#include "head.h"

bool InputBool(string text)
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
string ReadFromFile(string fileName)
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

    if (fd.good())
    {

        for (int i = 0; i < str.length(); i++)
        {
            hash = (hash * code) + int(str[i]);
        }

        string hashString = to_string(hash);

        unsigned int hexSymbol = hash;

        int SizeOfHashString = hashString.size();

        for (int i = 0; i < 64; i++)
        {
            hexSymbol += int(hashString[i % SizeOfHashString]) + i; // pridedame i nes su tekstu "a" gaunasi blogas hash

            finalHex += hex[hexSymbol % 16];
        }
    }
    return finalHex;
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
string HexToBin(char x)
{
    switch (toupper(x))
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    }
    return "";
}
void AvalancheEffect(string fileName)
{
    std::ifstream fd;
    fd.open(fileName);
    string string1, string2;
    int maximumasHex = 0, minimumasHex = 64, vidurkisHex = 0;
    int maximumasBit = 0, minimumasBit = 256, vidurkisBit = 0;
    int HexSkirtumas = 0;
    string hashed1, hashed2;
    do
    {
        fd >> string1 >> string2;
        if (string1 != string2)
        {
            HexSkirtumas = 0;
            hashed1 = Hashing(string1);
            hashed2 = Hashing(string2);

            for (int i = 0; i < 64; i++)
            {
                if (hashed1[i] != hashed2[i])
                {
                    HexSkirtumas++;
                }
            }
        }
        if (HexSkirtumas < minimumasHex)
        {
            minimumasHex = HexSkirtumas;
        }
        if (HexSkirtumas > maximumasHex)
        {
            maximumasHex = HexSkirtumas;
        }
        vidurkisHex += HexSkirtumas;

        int BitSkirtumas = 0;
        string bit1, bit2;

        for (int i = 0; i < 64; i++)
        {
            bit1 += HexToBin(hashed1[i]);
            bit2 += HexToBin(hashed2[i]);
        }

        for (int i = 0; i < 256; i++)
        {
            if (bit1[i] != bit2[i])
                BitSkirtumas++;
        }
        if (BitSkirtumas < minimumasBit)
        {
            minimumasBit = BitSkirtumas;
        }
        if (BitSkirtumas > maximumasBit)
        {
            maximumasBit = BitSkirtumas;
        }
        vidurkisBit += BitSkirtumas;

    } while (!fd.eof());

    cout << "Minimalus Hex skirtingumas: " << minimumasHex * 100 / 64 << "%" << endl;
    cout << "Maximalus Hex skirtingumas: " << maximumasHex * 100 / 64 << "%" << endl;
    cout << "Vidutinis Hex skirtingumas: " << vidurkisHex * 100 / 200000 / 64 << "%" << endl;
    cout << "Minimalus bitu skirtingumas: " << minimumasBit * 100 / 256 << "%" << endl;
    cout << "Maximalus bitu skirtingumas: " << maximumasBit * 100 / 256 << "%" << endl;
    cout << "Vidutinis bitu skirtingumas: " << vidurkisBit * 100 / 200000 / 256 << "%" << endl;
    cout << endl;
}