/*
* Ben DeJong
* CS220-02
* P:03, Text Message Decoder
* This program takes a user-defined sentence, 
* identifies commonly used acronyms,
* and decodes their meaning to plain English.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "*** P03: Text Message Decoder ***" << endl << endl;
    string userString;
    cout << "Enter a text message: ";
    getline(cin, userString);
    cout << endl;

    if(userString.find("BFF") != string::npos)
    {
        cout << "BFF: best friend forever" << endl;
    }
    if(userString.find("IDK") != string::npos)
    {
        cout << "IDK: I don't know" << endl;
    }
    if(userString.find("JK") != string::npos)
    {
        cout << "JK: just kidding" << endl;
    }
    if(userString.find("TMI") != string::npos)
    {
        cout << "TMI: too much information" << endl;
    }
    if(userString.find("TTYL") != string::npos)
    {
        cout << "TTYL: talk to you later" << endl;
    }

    return 0;
}
