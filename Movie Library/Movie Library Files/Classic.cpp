#include "Classic.h"
#include "StringHelper.h"

//--------------------------------- Comedy() -----------------------------------
//  Description:
//    -Constructs a comedy movie object by parsing and validating the incoming
//    descriptor
//    -Will early out and leave movie in an invalid state if descriptor is invalid
//  Args:
//    descriptor (string&): description of movie
//------------------------------------------------------------------------------
Classic::Classic(const string& descriptor) : Movie(descriptor)
{
    std::vector<string> splits = StringHelper::splitAndTrim(descriptor, ',');
    if(splits.size() != 5)
    {
        return;
    }
    std::vector<string> splits2 = StringHelper::split(splits[4]);
    if(splits2.size() != 4)
    {
        return;
    }
    
    if (splits[0] != "C")
    {
        return;
    }
    
    int stock = stoi(splits[1]);
    if (stock < 0)
    {
        return;
    }
    
    int month = stoi(splits2[2]);
    if (month > 12 || month < 1)
    {
        return;
    }
    
    int year = stoi(splits2[3]);
    if (year < 1888 || year > currentYear())
    {
        return;
    }
    
    mStock = stock;
    mDirector = splits[2];
    mTitle = splits[3];
    mActor = splits2[0] + " " + splits2[1];
    mMonth = month;
    mYear = year;
    mId = generateId();
}

//------------------------------ getMovieType() --------------------------------
//  Description:
//    -Accessor for movie type
//  Return:
//    MovieType, classic
//------------------------------------------------------------------------------
MovieType Classic::getMovieType() const
{
    return MovieType::Classic;
}

//---------------------------------- getKey() ----------------------------------
//  Description:
//    -Accessor for movie key; by month, year, actor
//  Return:
//    string, the key value
//------------------------------------------------------------------------------
string Classic::getKey() const
{
    return to_string(mMonth) + "_" + to_string(mYear) + "_" + mActor;
}

//---------------------------------- getActor() --------------------------------
//  Description:
//    -Accessor for major movie actor
//  Return:
//    string, the actor's name
//------------------------------------------------------------------------------
string Classic::getActor() const
{
    return mActor;
}
