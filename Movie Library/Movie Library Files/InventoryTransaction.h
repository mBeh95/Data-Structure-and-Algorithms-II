// ------------------------- InventoryTransaction ------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    This is the base class for transaction types that modify the inventory of
//    movies. Also provides helper methods to drive this functionality.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include "Transaction.h"
#include "StoreState.h"

class InventoryTransaction : public Transaction
{
public:
    InventoryTransaction();
    
protected:
    bool initFromDescriptor(const string& descriptor, const string& typeId);
    Movie* findMovie(StoreState& state) const;
    Movie* findMovieByKey(StoreState& state, const string& key, bool checkStock) const;
    bool changeStockOfMovie(StoreState& state, int delta);
    
protected:
    string mDirector;
    string mActor;
    string mTitle;
    int mMonth;
    int mYear;
    MovieType mMovieType;
};
