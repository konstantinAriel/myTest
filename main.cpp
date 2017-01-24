#include "myLib/simpleini-master/SimpleIni.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
using  namespace std;

int main( int argc, char** argv)
{
    CSimpleIniA ini;

    SI_Error rc =  ini.LoadFile(
            "/home/kosta/CLionProjects/myTest/test.ini");
if (rc<0){
    cout << ("ERROR");
}
    else {
    CSimpleIniA::TNamesDepend sections;
    ini.GetAllSections(sections);
    CSimpleIniA::TNamesDepend::const_iterator s;
    CSimpleIniA::TNamesDepend::const_iterator k;
    CSimpleIniA::TNamesDepend::const_iterator v;
    int j = 0;
    for (s = sections.begin(); s != sections.end(); ++s) { // Get Section

        cout << s -> pItem << ":\n";
                CSimpleIniA::TNamesDepend keys;
        auto sec = s -> pItem;


        stringstream strSection;
        strSection << sec;

        unsigned int intValue;
        strSection >> intValue;
        switch (intValue) {
            case 1:cout << "section 1" << "\n";
                break;
            case 2: cout << "section 2" << "\n";
                break;
            case 3: cout << "section 3" << "\n";
                break;
         }

        ini.GetAllKeys(s->pItem, keys);
        for (k = keys.begin(); k != keys.end(); ++k) {      // Get key
            CSimpleIniA::TNamesDepend value;
            CSimpleIniA::TNamesDepend values;
            ini.GetAllValues(s->pItem, k->pItem, values);

            for (v = values.begin(); v != values.end(); ++v) {  // Get value
                cout << k->pItem << " = " << v -> pItem << ";\n";
            }
        }
        j++;
    }
    cout << "j= " << j << "\n";
}
    return 0;
}