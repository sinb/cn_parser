
#ifndef HMMPARSER_H
#define HMMPARSER_H
#include <iostream>
#include <map>
using namespace std;
class HMMParser
{
private:
  int m_length_states;
  int m_length_obs;
  string *m_states;
  wstring m_observations;
  map<string, double> m_start_probability;
  map<string, map<string, double>> m_transition_probability;
  map<string, map<wstring, double>> m_emission_probability;  
  map<string, double*> weight;
  map<string, string*> path;
public:
HMMParser();
~HMMParser();
void getEmitProb();
void setInput(wstring input);
string Viterbi();
};

#endif // HMMPARSER_H
