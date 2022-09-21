#include <iostream>
#include <fstream>

using namespace std;

using std::cout;
using std::endl;

#include "head.h"

int main()
{
    bool PrintType = false;

    PrintType = InputBool("Ar norite teksta ivesti ranka? 1-taip, 0-ne ");

    string fileName;
    if (!PrintType)
    {
        bool badFile;
        cout << "Iveskite failo varda (pvz.: failas.txt): ";
        cin >> fileName;
        do
        {
            try
            {
                std::ifstream in(fileName);
                if (!in.good())
                    throw 404;
                else
                {
                    in.close();
                    badFile = false;
                }
            }
            catch (int exception)
            {
                badFile = true;
                cout << "Duomenu failas " << fileName << " neegzistuoja. Iveskite esamo failo varda: " << endl;
                cin >> fileName;
            }
        } while (badFile);
    }

    string input;

    if (PrintType == 0)
    {
        /*read from file......*/
    }
    else if (PrintType == 1)
    {
        cout << "Iveskite norima teksta: " << endl;
        cin >> input;
        cout << Hashing(input) << endl;
    }
}