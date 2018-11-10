// ------------------------------ Customer -------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Initializes customer object from a string decriptor. Provides additional
//    customer transaction functions.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data: customers have one first and one last name, and
//    a unique 4-digit ID number.
// -----------------------------------------------------------------------------

#pragma once
#include "Object.h"
#include <vector>

const int MAX_VALID_CUST_ID = 9999;

class Customer : public Object
{
public:
    Customer(const string& descriptor);

    void recordTransaction(const string& str);
    bool printHistory() const;
    
    string getName() const;
    const vector<string>& getTransactionHistory() const;    

private:
    string mName;
    vector<string> mTransactionHistory;
    
};
