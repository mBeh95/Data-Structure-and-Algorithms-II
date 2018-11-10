// -------------------------------- Comedy -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Initializes comedy movie object and provides accessors for protected
//    information.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "Movie.h"

class Comedy : public Movie
{
public:
    Comedy(const string& descriptor);

    virtual MovieType getMovieType() const override;
    virtual string getKey() const override;
};
