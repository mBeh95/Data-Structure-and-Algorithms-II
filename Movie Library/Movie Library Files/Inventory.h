// -------------------------------- Inventory ----------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Peforms 'Inventory' transaction: If successful, will print current inventory
//    by movie type (Comedy, Drama, Classic) to the console. Classics will also
//    print the major actor.
// -----------------------------------------------------------------------------
//  Notes:
//    None
// -----------------------------------------------------------------------------
#pragma once
#include "Transaction.h"
using namespace std;

class Inventory : public Transaction
{
public:
    virtual bool isValid() const override;
    virtual bool Transact(StoreState& state) override;
};
