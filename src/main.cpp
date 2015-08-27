#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DictionaryParser.hpp"
#include "HMMParser.hpp"
#include <float.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
    locale::global(locale(""));
    wcout.imbue(locale(""));  
      DictionaryParser dicparser;
      vector<wstring> output;      
      while(!wcin.eof())
      {
	wstring input;
	getline(wcin, input);
 	dicparser.parse(input, output);
      }
      for (int i = 0; i < output.size(); i++)
	  wcout << output[i] << " ";    

    return 0;
}
