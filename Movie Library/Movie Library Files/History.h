// -------------------------------- History -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Peforms 'History' transaction: If successful, customer's history will be
//    printed to the console.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------

#pragma once
#include "Transaction.h"

class History : public Transaction
{
public:
    History(const string& descriptor);
    virtual bool Transact(StoreState& state) override;

};
