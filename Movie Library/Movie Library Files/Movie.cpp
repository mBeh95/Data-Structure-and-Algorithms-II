#include <cstdio>
#include <vector>
#include "StringHelper.h"
#include "Movie.h"

namespace
{
    int sGeneratedId = 1;
}

//---------------------------------- Movie() -----------------------------------
//  Description:
//    -Constructs a movie object with default values
//------------------------------------------------------------------------------
Movie::Movie() : Object()
{
    mId = -1;
    mStock = 0;
    mYear = 0;
}

Movie::Movie(const string& descriptor)
{
}

//--------------------------------- isValid() ----------------------------------
//  Description:
//    -Determines if movie type/descriptor is valid
//  Return:
//    true, if movie is valid
//    false, if movie is not valid
//------------------------------------------------------------------------------
bool Movie::isValid() const
{
    if (getId() == -1)
    {
        return false;
    }
    return getMovieType() != MovieType::Invalid;
}

//------------------------------- getError() -----------------------------------
//  Description:
//    -Determines validity of movie and returns appropriate error message if invalid
//  Return:
//    string, nothing if movie is valid or appropriate error message if invalid
//------------------------------------------------------------------------------
string Movie::getError() const
{
    if (isValid())
    {
        return "";
    }
    if (getMovieType() == MovieType::Invalid)
    {
        return "Invalid movie type specified.";
    }
    if (getId() == -1)
    {
        return "Invalid movie descriptor";
    }
    return "Unspecified movie error.";
}

//----------------------------- getMovieType() ---------------------------------
//  Description:
//    -accessor for movie type
//  Return:
//    MovieType, returns movie type
//------------------------------------------------------------------------------
MovieType Movie::getMovieType() const
{
    return MovieType::Invalid;
}

//-------------------------------- getKey() ------------------------------------
//  Description:
//    -accessor for movie key, set to default value
//  Return:
//    string, key value
//------------------------------------------------------------------------------
string Movie::getKey() const
{
    return "";
}

//-------------------------------- getTitle() ----------------------------------
//  Description:
//    -accessor for movie title
//  Return:
//    string, movie title
//------------------------------------------------------------------------------
string Movie::getTitle() const
{
    return mTitle;
}

//------------------------------ getDirector() ---------------------------------
//  Description:
//    -accessor for director
//  Return:
//    string, director
//------------------------------------------------------------------------------
string Movie::getDirector() const
{
    return mDirector;
}

//-------------------------------- getActor() ----------------------------------
//  Description:
//    -accessor for actor, set to default
//  Return:
//    string, actor name
//------------------------------------------------------------------------------
string Movie::getActor() const
{
    return "";
}

//------------------------------ getStock() ------------------------------------
//  Description:
//    -accessor for stock
//  Return:
//    int, current stock
//------------------------------------------------------------------------------
int Movie::getStock() const
{
    return mStock;
}

//------------------------------ changeStock() ---------------------------------
//  Description:
//    -modifies movie stock
//  Args:
//    delta (string): change stock number (-1 for borrow, +1 for return)
//  Return:
//    true, if successful
//    false, if unsuccessful/invalid delta
//------------------------------------------------------------------------------
bool Movie::changeStock(int delta)
{
    if(mStock + delta < 0)
    {
        return false;
    }

    mStock += delta;

    return true;
}

//------------------------------ generateId() ---------------------------------
//  Description:
//    -generates Id number
//  Return:
//    int, Id number
//------------------------------------------------------------------------------
int Movie::generateId()
{
    int newId = sGeneratedId;
    sGeneratedId++;
    return newId;
}

//------------------------------ currentYear() ---------------------------------
//  Description:
//    -outputs current year
//  Return:
//    int, current year
//------------------------------------------------------------------------------
int Movie::currentYear()
{
    time_t absTime = time(nullptr);
    tm* locTime = localtime(&absTime);
    return locTime->tm_year + 1900;
}

//---------------------------- movieTypeName() ---------------------------------
//  Description:
//    -Outputs movie type by name
//  Return:
//    string, movie type
//------------------------------------------------------------------------------
string Movie::movieTypeName(MovieType movieType)
{
    switch (movieType)
    {
        case MovieType::Comedy: return "Comedy";
        case MovieType::Drama: return "Drama";
        case MovieType::Classic: return "Classic";
        default: return "Invalid";
    }
}

//------------------------- initFromDefaultDescriptor() ------------------------
//  Description:
//    -Parses and validates inputed data
//    -Sets member variables
//  Args:
//    descriptor (string&): reference to descriptor string
//    typeId (string&): movie type id
//  Return:
//    true, if valid inputted data and successful
//    false, if invalid inputted data
//------------------------------------------------------------------------------
//parses and validates descriptor, then sets object state
bool Movie::initFromDefaultDescriptor(const string& descriptor, const string& typeId)
{
    std::vector<string> splits = StringHelper::splitAndTrim(descriptor, ',');
    if(splits.size() != 5)
    {
        return false;
    }
    
    if (splits[0] != typeId)
    {
        return false;
    }
    
    int stock = stoi(splits[1]);
    if (stock < 0)
    {
        return false;
    }
    
    int year = stoi(splits[4]);
    if (year < 1888 || year > currentYear())
    {
        return false;
    }
    
    mStock = stock;
    mDirector = splits[2];
    mTitle = splits[3];
    mYear = year;
    mId = generateId();
    return true;
}









