// -------------------------------- Classic ------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Initializes classic movie object and provides accessors for private/protected
//    information.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
//    All actors have only one first and one last name.
// -----------------------------------------------------------------------------
#pragma once
#include "Movie.h"
#include <vector>

class Classic : public Movie
{
public:
    Classic(const string& descriptor);

    virtual MovieType getMovieType() const override;
    virtual string getKey() const override;
    string getActor() const override;

private:
    string mActor;
    int mMonth;
};
