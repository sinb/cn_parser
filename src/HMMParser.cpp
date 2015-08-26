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
HMMParser::~HMMParser()
{


}
