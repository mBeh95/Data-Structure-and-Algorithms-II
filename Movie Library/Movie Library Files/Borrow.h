// -------------------------------- Borrow -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Peforms 'Borrow' transaction: If successful, removes movie object from map
//    and updates stock.
// -----------------------------------------------------------------------------
//  Notes:
//    If the requested movie/actor combination is out of stock, and the requested
//    movie is in stock featuring a different actor, the transaction will process
//    on the requested movie/alternative actor.
//
//    Assumes well formatted data
// -----------------------------------------------------------------------------

#pragma once
#include "InventoryTransaction.h"

class Borrow : public InventoryTransaction
{
public:
    Borrow(const string& descriptor);
    virtual bool Transact(StoreState& state) override;
};
