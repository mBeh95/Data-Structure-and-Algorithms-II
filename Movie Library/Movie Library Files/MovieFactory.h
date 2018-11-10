// ----------------------------- MovieFactory ----------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Creates movie type objects based on inputed data.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <string>
#include "Movie.h"
using namespace std;

class MovieFactory
{
public:
    
    Movie* MakeMovie(const string& str) const;
};
