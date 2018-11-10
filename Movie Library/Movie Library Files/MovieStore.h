// -------------------------------- MovieStore ---------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Runs entire store by first reading in customers, movies, and transactions,
//    then processing all transactions.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <string>
using namespace std;

class MovieStore
{
public:
    void Run(const string& inventoryPath, const string& customersPath,
             const string& transactionsPath) const;
};
