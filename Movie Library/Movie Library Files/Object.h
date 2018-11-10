// -------------------------------- Object -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Base class for every transaction, customer and movie.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <string>

using namespace std;

class Object
{
public:
    Object();

    virtual bool isValid() const;
    virtual string getError() const;

    virtual int getId() const;

protected:
    int mId;
    string mError;
};
