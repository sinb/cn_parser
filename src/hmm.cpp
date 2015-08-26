#include "hmm.hpp"
#include <iostream>
// 观测的顺序就是observations输入的顺序
HMM::HMM(int length_states, int length_obs, string *states, string *observations,
	 map<string, double> start_probability, map<string, map<string, double>> transition_probability,
	  map<string, map<string, double>> emission_probability)
{
    // new
    this->states = new string[length_states];
    this->observations = new string[length_obs];
    
    // init
    this->length_obs = length_obs;
    this->length_states = length_states;
    for (size_t t = 0; t < length_states; t++)
      this->states[t] = states[t];
    for (size_t t = 0; t < length_obs; t++)
      this->observations[t] = observations[t];    
    this->start_probability.insert(start_probability.begin(), start_probability.end());
    this->transition_probability.insert(transition_probability.begin(), transition_probability.end());
    this->emission_probability.insert(emission_probability.begin(), emission_probability.end());
}

string HMM::Viterbi(map<string, double*> &weight, map<string, string*> &path)
{
    for (size_t t = 0; t < this->length_states; t++)
    {
      weight.insert(make_pair(this->states[t], new double[this->length_obs]));
      path.insert(make_pair(this->states[t], new string[this->length_obs]));
    }
    // init
    for (size_t t = 0; t < this->length_states; t++)
    {
      weight[this->states[t]][0] = this->start_probability[this->states[t]] * 
	    this->emission_probability[this->states[t]][this->observations[0]];
    }
    for (size_t t = 1; t < this->length_obs; t++)
    {
      for (size_t i = 0; i < this->length_states; i++)
      { 
	string key = this->states[i];
	for (size_t j = 0; j < this->length_states; j++) 
	{
	  string prev_key = this->states[j];

	  double tmp = weight[prev_key][t-1] * this->transition_probability[prev_key][key] *
	    this->emission_probability[key][observations[t]];
	  if (tmp > weight[key][t])
	  {
	    weight[key][t] = tmp;
	    path[key][t] = prev_key;
	  }
	}
      } 
    }
    size_t end_state = 0;
    double max = 0;
    size_t t;
    for ( t = 0; t < this->length_states; t++)
    {
      if (weight[this->states[t]][this->length_obs-1] > max)
      {
	max = weight[this->states[t]][this->length_obs-1];
	end_state = t;
      }
    }
    return this->states[end_state];
}
void HMM::backtrack(string end_state, map<string, string*> &path, deque<string> &viterbi_path)
{
  string state = end_state;
  viterbi_path.push_front(state);
  for (size_t time = this->length_obs - 1; time > 0; time--)
  {
    state = path[state][time];
    viterbi_path.push_front(state);
  }
}
HMM::HMM()
{
  
}
HMM::~HMM()
{

}
