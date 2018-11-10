// ---------------------------- StringHelper -----------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Helper class used to split, concatenate, and trim strings.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#include <string>
#include <vector>

class StringHelper
{
public:

    static void split(const std::string& s, char delim, std::vector<std::string>& elems);
    static std::vector<std::string> split(const std::string& s, char delim);
    static std::vector<std::string> split(const std::string& s);

    static std::vector<std::string> splitAndTrim(const std::string& s, char delim);
    
    static std::string& ltrim(std::string &s);
    static std::string& rtrim(std::string &s);
    static std::string& trim(std::string &s);

    static std::string concat(const std::vector<std::string>& strs, size_t start,
                              size_t end, const std::string& delim);
    static std::string concat(const std::vector<std::string>& strs, size_t start, size_t end);
};