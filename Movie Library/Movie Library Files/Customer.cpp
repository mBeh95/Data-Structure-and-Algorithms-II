#include "Customer.h"
#include <iostream>
#include "StringHelper.h"

//---------------------------------- Customer() --------------------------------
//  Description:
//    -Constructs customer object by parsing and validating inputted string
//  Args:
//    descriptor (string): customer's unique 4-digit id and name
//------------------------------------------------------------------------------
Customer::Customer(const string& descriptor) : Object()
{
    std::vector<string> splits = StringHelper::split(descriptor);
    if(splits.size() != 3)
    {
        return;
    }
    
    int custId = stoi(splits[0]);
    if (custId < 0 || custId > MAX_VALID_CUST_ID)
    {
        return;
    }
    
    mId = custId;
    mName = splits[2] + " " + splits[1];
}

//---------------------------recordTransaction() -------------------------------
//  Description:
//    -Records return and borrow transactions to the transactionHistory vector
//  Args:
//    str (string): transaction
//------------------------------------------------------------------------------
void Customer::recordTransaction(const string& str)
{
	if (str.length() > 0)
    {
        mTransactionHistory.push_back(str);
    }
}

//------------------------------- printHistory() -------------------------------
//  Description:
//    -Prints customer's transaction history
//  Return:
//    true, if printing history is successful
//    falses, if unable to print history
//------------------------------------------------------------------------------
bool Customer::printHistory() const
{
    cout << " ---- HISTORY: " << getName() << " ---- " << endl;
    for (int i = static_cast<int>(mTransactionHistory.size()) - 1; i >= 0; i--)
    {
        cout << mTransactionHistory[i] << endl;
    }
    return true;
}

//---------------------------------- getname() ---------------------------------
//  Description:
//    -Accessor for customer's name
//  Return:
//    string, customer's name
//------------------------------------------------------------------------------
string Customer::getName() const
{
	return mName;
}

//---------------------------------- Customer() --------------------------------
//  Description:
//    -Accessor for transactionHistory vector
//------------------------------------------------------------------------------
const vector<string>& Customer::getTransactionHistory() const
{
    return mTransactionHistory;
}
