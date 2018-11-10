#include "Object.h"

//-------------------------------- Object() ------------------------------------
//  Description:
//    -Constructs object with default values
//  Return:
//    string, director
//------------------------------------------------------------------------------
Object::Object()
{
    mId = -1;
    mError = "Uninitialized object";
}

//-------------------------------- isValid() -----------------------------------
//  Description:
//    -Determines if object is valid
//  Return:
//    true, object is valid
//    false, object is invalid
//------------------------------------------------------------------------------
bool Object::isValid() const
{
    return mError.length() > 0;
}

//------------------------------ getError() ------------------------------------
//  Description:
//    -accessor for error
//  Return:
//    string, error message
//------------------------------------------------------------------------------
string Object::getError() const
{
    return mError;
}

//--------------------------------- getId() ------------------------------------
//  Description:
//    -accessor for object id
//  Return:
//    int, id number
//------------------------------------------------------------------------------
int Object::getId() const
{
    return mId;
}















