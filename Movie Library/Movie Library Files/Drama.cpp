#include <vector>
#include <string>
#include "StringHelper.h"
#include "Drama.h"

//--------------------------------- Drama() -----------------------------------
//  Description:
//    -Constructs a comedy movie object by parsing and validating the incoming
//    descriptor
//    -Will early out and leave movie in an invalid state if descriptor is invalid
//  Args:
//    descriptor (string&): description of movie
//------------------------------------------------------------------------------
Drama::Drama(const string& descriptor) : Movie(descriptor)
{
    initFromDefaultDescriptor(descriptor, "D");
}

//------------------------------ getMovieType() --------------------------------
//  Description:
//    -Accessor for movie type
//  Return:
//    MovieType, drama
//------------------------------------------------------------------------------
MovieType Drama::getMovieType() const
{
    return MovieType::Drama;
}

//---------------------------------- getKey() ----------------------------------
//  Description:
//    -Accessor for movie key; by month, year, actor
//  Return:
//    string, the key value
//------------------------------------------------------------------------------
string Drama::getKey() const
{
    return mDirector + "_" + mTitle;
}