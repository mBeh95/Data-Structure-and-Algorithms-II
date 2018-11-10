#include "MovieFactory.h"
#include "StringHelper.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

//------------------------------- makeMovie() ----------------------------------
//  Description:
//    -Constructs movie object by parsing inputted string
//  Args:
//    str (string): descriptor of movie
//  Return:
//    Movie*, pointer to the movie object
//------------------------------------------------------------------------------
Movie* MovieFactory::MakeMovie(const string& str) const
{
    vector<string> splits = StringHelper::splitAndTrim(str, ',');
    if(splits.size() == 0)
    {
        return new Movie();
    }

    string movieType = splits[0];
    if (movieType == "C")
    {
        return new Classic(str);
    }
    else if (movieType == "F")
    {
        return new Comedy(str);
    }
    else if (movieType == "D")
    {
        return new Drama(str);
    }

    return new Movie();
}
