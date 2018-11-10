#include "StringHelper.h"
#include <sstream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

//------------------------------ split() ---------------------------------------
//  Description:
//    -parses string according to delimeter, putting each substring into elems
//    vector
//------------------------------------------------------------------------------
void StringHelper::split(const string& s, char delim, vector<string>& elems)
{
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}

//------------------------------ split() ---------------------------------------
//  Description:
//    -parses string according to delimeter, putting each substring into elems
//    vector
//  Return:
//    vector of substrings
//------------------------------------------------------------------------------
vector<string> StringHelper::split(const string& s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

//------------------------------ split() ---------------------------------------
//  Description:
//    -parses string according to white space
//  Return:
//    vector of substrings
//------------------------------------------------------------------------------
vector<string> StringHelper::split(const string& s)
{
    return split(s, ' ');
}

//------------------------------ splitAndTrim() --------------------------------
//  Description:
//    -trims string according to delimiter
//  Return:
//    vector of substrings
//------------------------------------------------------------------------------
std::vector<std::string> StringHelper::splitAndTrim(const std::string& s, char delim)
{
    vector<std::string> splits = split(s, delim);
   
    for (int i = 0; i < splits.size(); i++)
    {
        StringHelper::trim(splits[i]);
    }
    
    return splits;
}

//--------------------------------- ltrim() ------------------------------------
//  Description:
//    -helper method to trim whitespace from left side of string
//  Return:
//    string reference
//------------------------------------------------------------------------------
string& StringHelper::ltrim(string &s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

//--------------------------------- rtrim() ------------------------------------
//  Description:
//    -helper method to trim whitespace from right side of string
//  Return:
//    string reference
//------------------------------------------------------------------------------
string& StringHelper::rtrim(string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

//--------------------------------- ltrim() ------------------------------------
//  Description:
//    -trims whitespace surrounding string
//  Return:
//    string reference
//------------------------------------------------------------------------------
string& StringHelper::trim(string &s)
{
    return ltrim(rtrim(s));
}

//--------------------------------- concat() -----------------------------------
//  Description:
//    -concatenates substring vector from inputted start and end with inputted
//    delimiter between substrings
//  Return:
//    string of concatenated substrings
//------------------------------------------------------------------------------
string StringHelper::concat(const vector<string>& strs, size_t start, size_t end, const string& delim)
{
    string result = strs[start];
    for (size_t i = start + 1; i <= end; i++)
    {
        if (i <= end)
        {
            result += delim;
        }
        result += strs[i];
    }
    return result;
}

//--------------------------------- concat() -----------------------------------
//  Description:
//    -concatenates substring vector from inputted start and end
//  Return:
//    string of concatenated substrings
//------------------------------------------------------------------------------
string StringHelper::concat(const vector<string>& strs, size_t start, size_t end)
{
    return concat(strs, start, end, " ");
}
