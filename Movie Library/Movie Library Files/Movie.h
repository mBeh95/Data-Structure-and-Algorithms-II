
// -------------------------------- Movie --------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    This is the base class for movie types. 
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "Object.h"

enum class MovieType
{
    Invalid,
    First,
    Comedy = First,
    Drama,
    Classic,
    Count
};

class Movie : public Object
{
public:
    Movie();
    Movie(const string& descriptor);
    
    virtual bool isValid() const override;
    virtual string getError() const override;
    
    virtual MovieType getMovieType() const;
    virtual string getKey() const;
    string getTitle() const;
    string getDirector() const;
    virtual string getActor() const;

    int getStock() const;
    bool changeStock(int delta);
    
    static int generateId();
    
    static int currentYear();
    
    static string movieTypeName(MovieType movieType);
    
protected:
    bool initFromDefaultDescriptor(const string& descriptor, const string& typeId);

protected:
    string mTitle;
    string mDirector;
    int mStock;
    int mYear;
};
