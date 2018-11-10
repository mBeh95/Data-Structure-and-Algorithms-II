#include "Comedy.h"

//--------------------------------- Comedy() -----------------------------------
//  Description:
//    -Constructs a comedy movie object by parsing and validating the incoming
//    descriptor
//    -Will early out and leave movie in an invalid state if descriptor is invalid
//  Args:
//    descriptor (string&): description of movie
//------------------------------------------------------------------------------
Comedy::Comedy(const string& descriptor) : Movie(descriptor)
{
    initFromDefaultDescriptor(descriptor, "F");
}

//------------------------------ getMovieType() --------------------------------
//  Description:
//    -Accessor for movie type
//  Return:
//    MovieType, comedy
//------------------------------------------------------------------------------
MovieType Comedy::getMovieType() const
{
    return MovieType::Comedy;
}

//---------------------------------- getKey() ----------------------------------
//  Description:
//    -Accessor for movie key; by month, year, actor
//  Return:
//    string, the key value
//------------------------------------------------------------------------------
string Comedy::getKey() const
{
    return mTitle + "_" + to_string(mYear);
}