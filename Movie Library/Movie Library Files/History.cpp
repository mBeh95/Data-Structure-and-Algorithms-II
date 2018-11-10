#include "History.h"
#include <string>
#include <iostream>
#include "StringHelper.h"

//-------------------------------- History() ------------------------------------
//  Description:
//    -Constructs a history transaction
//  Args:
//    descriptor (string): description of transaction
//------------------------------------------------------------------------------
History::History(const string& descriptor)
{
    std::vector<string> splits = StringHelper::split(descriptor);
    if(splits.size() < 2)
    {
        return;
    }
    
    if (splits[0] != "H")
    {
        return;
    }
    
    int custId = stoi(splits[1]);
    if (custId < 0 || custId > MAX_VALID_CUST_ID)
    {
        return;
    }
    
    mCustomerId = custId;
}


//-------------------------------- Transact() ----------------------------------
//  Description:
//    -Performs history transaction, if successful, customer's transaction history
//    is printed
//    -Prints error message if customer not found
//  Args:
//    state (StoreState&): current state of the movie store
//  Return:
//    True if customer is found and history printed
//    False if customer is not found and history not printed
//------------------------------------------------------------------------------
bool History::Transact(StoreState& state)
{
    Customer* customer = state.customerData.retrieve(getCustomerId());
    if (customer == nullptr)
    {
        mError = "Invalid customer ID " + to_string(getCustomerId());
        return false;
    }

    return customer->printHistory();
}