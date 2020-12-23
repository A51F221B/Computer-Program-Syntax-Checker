#include<fstream>
#include"SyntaxCheck.h"

using namespace std;

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
    //checks if file is accesible or not
    while (!file.good())
    {
        cout << "[!] File not found or isn't accessible" << endl;
        cout << "[*] Enter a correct name of the file you want to open: ";
        getline(cin, fileName);
        file.open(fileName, ios::in);
    }

    int fileLen = 0;
    //reads file as a string line
    while (!file.eof())
    {
        std::getline(file, readExprs);
        fileLen++;
    }

    file.close();
    file.open(fileName, ios::in);

  

    string* data = new string[fileLen];
    int loop = 0;
    //copy file into a string array
    while (!file.eof())
        while (getline(file, data[loop++]));

   //displaying contents of file 
    cout << "[>] Printing File output  : " << endl;
    for (int i = 0; i < fileLen; i++)
    {
        cout << data[i] << endl;
    }

    cout << "[!] Parantheses are " << (check1.check_brackets(data, fileLen) ? " balanced" : " not balanced") << endl;;
    cout << "[!] Keywords are " << (check1.keywords(data, fileLen) ? " balanced " : " not balanced ") << endl;;



    cin.get();
}
