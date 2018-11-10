// --------------------------------- Drama -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Initializes drama movie object and provides accessors for protected
//    information.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "Movie.h"

class Drama : public Movie
{
public:
    Drama(const string& descriptor);
    
    virtual MovieType getMovieType() const override;
    virtual string getKey() const override;
};
