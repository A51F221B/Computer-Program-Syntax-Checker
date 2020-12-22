#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include"Stack.h"
#include"SyntaxCheck.h"


using namespace std;

void checkBegin(string filename) {
    vector<string> begin;

}
int main()
{
    cout << "[>] Developed By " << endl;
    cout << "Ozair Malik (190798)" << endl;
    cout << "Asif Masood (190794) " << endl;
    SyntaxCheck check1;
    fstream file;
    cout << "[>] Enter the name of file you want to check " << endl;
    string fileName;
    getline(cin, fileName);
    file.open(fileName, ios::in);
    string readExprs;
    if (!file.good())
    {
        cout << "[!] File not found or isn't accessible" << endl;
        cin.get();
        return -1;
    }

    int fileLen = 0;
    while (!file.eof())
    {
        std::getline(file, readExprs);
        fileLen++;
    }
    file.seekg(0, ios::beg); // Takes the file pointer to the beginning of the file so that we can read it again.

    string* data = new string[fileLen];
    int loop = 0;
    while (!file.eof())
        while (getline(file, data[loop++]));


    cout << "[>] Printing File output  : " << endl;
    for (int i = 0; i < fileLen; i++) {
        cout << data[i] << endl;
    }

    cout << "[!] Parantheses are " << (check1.check_brackets(data, fileLen) ? " balanced" : " not balanced") << endl;;
    cout << "[!] Keywords are " << (check1.keywords(data, fileLen) ? " balanced " : " not balanced ") << endl;;



    cin.get();
}