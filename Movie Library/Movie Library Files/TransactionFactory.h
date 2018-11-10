// --------------------------- TransactionFactory ------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Creates transaction objects based on inputed data.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <string>
#include "Transaction.h"
using namespace std;

class TransactionFactory
{
public:
    
    Transaction* MakeTransaction(const string& str) const;
};

