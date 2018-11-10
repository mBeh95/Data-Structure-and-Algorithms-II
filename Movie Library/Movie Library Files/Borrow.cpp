#include "Borrow.h"

//-------------------------------- Borrow() ------------------------------------
//  Description:
//    -Constructs a borrow transaction
//  Args:
//    descriptor (string): description of transaction
//------------------------------------------------------------------------------
Borrow::Borrow(const string& descriptor) : InventoryTransaction()
{
    initFromDescriptor(descriptor, "B");
}

//------------------------------ Transact() ------------------------------------
//  Description:
//    -Performs borrow transaction, if successful, movie stock decremented by 1.
//  Args:
//    state (StoreState&): current state of the movie store
//  Return:
//    True if movie successfully borrowed
//    False if movie not borrowed
//------------------------------------------------------------------------------
bool Borrow::Transact(StoreState& state) 
{
    return changeStockOfMovie(state, -1);
}

