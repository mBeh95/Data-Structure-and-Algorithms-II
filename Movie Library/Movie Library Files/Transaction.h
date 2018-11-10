// ----------------------------- Transaction -----------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Base class for all transactions.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "Object.h"
#include "Customer.h"
#include "Movie.h"
#include "StoreState.h"

class Transaction : public Object
{
public:
    Transaction();
    Transaction(const string& transactionString);
    
    virtual bool isValid() const override;
    
    virtual bool Transact(StoreState& state);
    
    int getCustomerId() const;
    
    
    
protected:
    int mCustomerId;
    string mDescriptor;
};
