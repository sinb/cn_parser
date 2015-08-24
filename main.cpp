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
    wstring input;
    wcin >> input;
    //wcout << L"的请问的2 3 阿斯顿" << endl;
    dicparser.parse(input, output);
    //wcout << input.substr(2, 0);
    for (int i = 0; i < output.size(); i++)
        wcout << output[i] << " ";
    wcout << endl;
    return 0;
}
