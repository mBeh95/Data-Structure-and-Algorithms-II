#include <stdio.h>
#include "Transaction.h"

//------------------------------ Transaction() ---------------------------------
//  Description:
//    -Constructs a transaction object, setting default values
//------------------------------------------------------------------------------
Transaction::Transaction() : Object()
{
    mDescriptor = "";
    mCustomerId = -1;
}

//------------------------------ Transaction() ---------------------------------
//  Description:
//    -Constructs a transaction object from a descriptor string
//  Args:
//    descriptor (string&): description of transaction
//------------------------------------------------------------------------------
Transaction::Transaction(const string& descriptor) : Transaction()
{
    mDescriptor = descriptor;
}

//------------------------------ isValid() ------------------------------------
//  Description:
//    -Determins if transaction is valid based on customer id
//  Return:
//    True if valid
//    False if unvalid
//------------------------------------------------------------------------------
bool Transaction::isValid() const
{
    return getCustomerId() != -1;
}


//-------------------------------- Transact() ----------------------------------
//  Description:
//    -default implementation
//  Return:
//    false, default return
// -----------------------------------------------------------------------------
bool Transaction::Transact(StoreState& state)
{
    return false;
}

//------------------------------ getCustomerId() -------------------------------
//  Description:
//    -Accessore for customer id
//  Return:
//    int, customer 4 digit id number
// -----------------------------------------------------------------------------
int Transaction::getCustomerId() const
{
    return mCustomerId;
}
