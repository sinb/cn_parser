#ifndef DICTIONARYPARSER_HPP_INCLUDED
#define DICTIONARYPARSER_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class DictionaryParser
{
private:
public:
    vector<wstring> dic;
    int max_word_length = 0;

    DictionaryParser();
    void printDic();
    int get_max_word_length();
    void parse(wstring input, vector<wstring> &output);
  
};



#endif // DICTIONARYPARSER_HPP_INCLUDED
