/*
 * Copyright 2015 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include "HMMParser.hpp"
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cfloat>
#include <deque>
HMMParser::HMMParser()
{
  m_length_states = 4;
  m_states = new string[4] {"B", "M", "E", "S"};
  // start_probability
  m_start_probability["B"] = -0.26268660809250016;
  m_start_probability["M"] = -3.14e+100;
  m_start_probability["E"] = -3.14e+100;
  m_start_probability["S"] = -1.4652633398537678;
  // transition_probability, 4*4
  m_transition_probability["B"].insert(make_pair("B", -3.14e+100));
  m_transition_probability["B"].insert(make_pair("M", -0.916290731874155));
  m_transition_probability["B"].insert(make_pair("E", -0.510825623765990));
  m_transition_probability["B"].insert(make_pair("S", -3.14e+100));
 
  m_transition_probability["M"].insert(make_pair("B", -3.14e+100));
  m_transition_probability["M"].insert(make_pair("M", -1.2603623820268226));
  m_transition_probability["M"].insert(make_pair("E", -0.33344856811948514));
  m_transition_probability["M"].insert(make_pair("S", -3.14e+100));
 
  m_transition_probability["E"].insert(make_pair("B", -0.5897149736854513));
  m_transition_probability["E"].insert(make_pair("M", -3.14e+100));
  m_transition_probability["E"].insert(make_pair("E", -3.14e+100));
  m_transition_probability["E"].insert(make_pair("S", -0.8085250474669937));
 
  m_transition_probability["S"].insert(make_pair("B", -0.7211965654669841));
  m_transition_probability["S"].insert(make_pair("M", -3.14e+100));
  m_transition_probability["S"].insert(make_pair("E", -3.14e+100));
  m_transition_probability["S"].insert(make_pair("S", -0.6658631448798212));
  //
  
  
}
void HMMParser::getEmitProb()
{
    wifstream fin("../lexicon/emit_prob_bems", ios::in);
    wstring a;
    // B
    getline(fin, a);
    replace(a.begin(), a.end(), ':', ' ');
    replace(a.begin(), a.end(), ',', ' ');
    wstring buf;
    wstring buf2;
    wstringstream ss(a);
    while (ss >> buf)
    {
      ss >> buf2;
      double logp = stod(buf2);
      m_emission_probability["B"].insert(make_pair(buf, logp));
    }
    // E
    getline(fin, a);
    replace(a.begin(), a.end(), ':', ' ');
    replace(a.begin(), a.end(), ',', ' ');    
    ss.clear();
    ss.str(a);
    while (ss >> buf)
    {
      ss >> buf2;
      double logp = stod(buf2);
      m_emission_probability["E"].insert(make_pair(buf, logp));
    }   
    // M
    getline(fin, a);
    replace(a.begin(), a.end(), ':', ' ');
    replace(a.begin(), a.end(), ',', ' ');    
    ss.clear();
    ss.str(a);
    while (ss >> buf)
    {
      ss >> buf2;
      double logp = stod(buf2);
      m_emission_probability["M"].insert(make_pair(buf, logp));
    }
    // S
    getline(fin, a);
    replace(a.begin(), a.end(), ':', ' ');
    replace(a.begin(), a.end(), ',', ' ');    
    ss.clear();
    ss.str(a);
    while (ss >> buf)
    {
      ss >> buf2;
      double logp = stod(buf2);
      m_emission_probability["S"].insert(make_pair(buf, logp));
    }    
}
void HMMParser::setInput(wstring input)
{
    weight.clear();
    path.clear();
    m_observations.assign(input);
    m_length_obs = m_observations.size();
    for (size_t t = 0; t < m_length_states; t++)
    {
      weight.insert(make_pair(m_states[t], new double[m_length_obs]));
      path.insert(make_pair(m_states[t], new string[m_length_obs]));
    }  
}
string HMMParser::Viterbi()
{
    // init
    // need to convert wchar to wstring
    wstringstream ss;
    wstring obs_char;
    ss << m_observations[0]; ss >> obs_char;
    for (size_t t = 0; t < m_length_states; t++)
    {
      weight[m_states[t]][0] = m_start_probability[m_states[t]] + 
	    m_emission_probability[m_states[t]][obs_char];
    }
    for (size_t t = 1; t < m_length_obs; t++)
    {
      ss.clear();
      ss << m_observations[t];
      ss >> obs_char;
      for (size_t i = 0; i < m_length_states; i++)
      { 
	string key = m_states[i];
	weight[key][t] = -3.14e+100;
	for (size_t j = 0; j < m_length_states; j++) 
	{
	  string prev_key = m_states[j];

	  double tmp = weight[prev_key][t-1] + m_transition_probability[prev_key][key] +
	    m_emission_probability[key][obs_char];
	  if (tmp > weight[key][t])
	  {
	    weight[key][t] = tmp;
	    path[key][t] = prev_key;
	  }
	  else
	  {
	  }
	  
	}
      } 
    }
    size_t end_state = 2;
    double max = -3.14e+100;
    size_t t;
    // 结束字只能从E 或者 S里出来,所以之比较这两个
    for ( t = 2; t < m_length_states; t++)
    {
      if (weight[m_states[t]][m_length_obs-1] > max)
      {
	max = weight[m_states[t]][m_length_obs-1];
	end_state = t;
      }
    }    
    deque<string> viterbi_path;
    string state = m_states[end_state];
    viterbi_path.push_front(state);
    for (size_t time = m_length_obs - 1; time > 0; time--)
    {
      state = path[state][time];
      viterbi_path.push_front(state);
    }    
    for (size_t i = 0; i < m_length_obs; i++)
    {
      if (viterbi_path[i] == "E" || viterbi_path[i] == "S" )
      {
	wcout << m_observations[i] << " ";
      }
      else
      {
	wcout << m_observations[i];
      }
    }
//     for (auto it = viterbi_path.begin(); it != viterbi_path.end(); it++)
//       cout << *it;

    
}

HMMParser::~HMMParser()
{


}
