#include "Return.h"
#include "StringHelper.h"


//-------------------------------- Borrow() ------------------------------------
//  Description:
//    -Constructs a return transaction
//  Args:
//    descriptor (string): description of transaction
//------------------------------------------------------------------------------
Return::Return(const string& descriptor) : InventoryTransaction()
{
    initFromDescriptor(descriptor, "R");
}

//------------------------------ Transact() ------------------------------------
//  Description:
//    -Performs return transaction, if successful, movie stock incremented by 1.
//  Args:
//    state (StoreState&): current state of the movie store
//  Return:
//    True if movie successfully returned
//    False if movie not returned
//------------------------------------------------------------------------------
bool Return::Transact(StoreState& state)
{
    return changeStockOfMovie(state, 1);
}


