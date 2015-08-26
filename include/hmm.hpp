#ifndef HMM_H
#define HMM_H

#include <map>
#include <string>
#include <vector>
#include <deque>

using namespace std;
class HMM
{
private:
  int length_states;
  int length_obs;
  string *states;
  string *observations;
  map<string, double> start_probability;
  map<string, map<string, double>> transition_probability;
  map<string, map<string, double>> emission_probability;
public:
  HMM(int length_states, int length_obs, string *states, string *observations, 
      map<string, double> start_probability, map<string, map<string, double>> transition_probability,
	map<string, map<string, double>> emission_probability);
  string Viterbi(map<string, double*> &weight, map<string, string*> &path);
  void backtrack(string end_state, map<string, string*> &path, deque<string> &viterbi_path);

  HMM();
  ~HMM();
};

#endif // HMM_H
