#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DictionaryParser.hpp"
using namespace std;

int main()
{
    locale::global(locale(""));
    wcout.imbue(locale(""));
    DictionaryParser dicparser;
    vector<wstring> output;

//    wstring input;
//    getline(wcin, input);
//
//    dicparser.parse(input, output);
    //
    while(!wcin.eof())
    {
      wstring input;
      getline(wcin, input);
      dicparser.parse(input, output);
    }
    //
    for (int i = 0; i < output.size(); i++)
        wcout << output[i] << " ";
    wcout << endl;

    return 0;
}
