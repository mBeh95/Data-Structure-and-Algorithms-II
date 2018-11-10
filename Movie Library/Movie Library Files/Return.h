// -------------------------------- Return -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Peforms 'Return' transaction: If successful, adds movie object to map
//    and updates stock.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "InventoryTransaction.h"

class Return : public InventoryTransaction
{
public:
    Return(const string& descriptor);
    virtual bool Transact(StoreState& state) override;
};
