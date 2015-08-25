#include "DictionaryParser.hpp"

DictionaryParser :: DictionaryParser ()
{
    wifstream fin("../lexicon/lexcion", ios::in);
    while(fin)
    {
        wstring a;
        getline(fin, a);
        dic.push_back(a);
        if (a.size() > max_word_length)
            max_word_length = a.size();
    }
    dic.pop_back();
}
void DictionaryParser :: printDic()
{
    for (int i = 0; i < dic.size(); i++)
        wcout << dic[i] << endl;
}
int DictionaryParser :: get_max_word_length()
{
    return max_word_length;
}
void DictionaryParser :: parse(wstring input, vector<wstring> &output)
{

    int parse_loc_begin = 0;
    int parse_loc_end = (parse_loc_begin+max_word_length) < input.size() ? (parse_loc_begin+max_word_length) : input.size();
    while (input.substr(parse_loc_begin, parse_loc_end - parse_loc_begin).size() != 0 && (parse_loc_end <= input.size()))
    {
        bool found = false;
        if (input.substr(parse_loc_begin, parse_loc_end - parse_loc_begin).size() == 1)
        {
            output.push_back(input.substr(parse_loc_begin, parse_loc_end - parse_loc_begin));
            parse_loc_begin = parse_loc_end;
            parse_loc_end = (parse_loc_begin+max_word_length) < input.size() ? (parse_loc_begin+max_word_length) : input.size();
            continue;
        }

        for (int j = 0; j < dic.size(); j++) // for all the lexicon word of this size
        {
            if (dic[j].size() != input.substr(parse_loc_begin, parse_loc_end - parse_loc_begin).size())
                continue;
            else if (!dic[j].compare(0, dic[j].size(), input, parse_loc_begin, parse_loc_end - parse_loc_begin)) // find the lexicon word
            {
                output.push_back(input.substr(parse_loc_begin, parse_loc_end - parse_loc_begin));
                parse_loc_begin = parse_loc_end;
                parse_loc_end = (parse_loc_begin+max_word_length) < input.size() ? (parse_loc_begin+max_word_length) : input.size();
                found = true;
                break;
            }
            else // didn't find the lexicon word
            {
            }
        }
        if(!found && (parse_loc_end - parse_loc_begin) > 1)
            parse_loc_end -= 1;
    }

}
