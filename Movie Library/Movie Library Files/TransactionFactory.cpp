#include "TransactionFactory.h"
#include "StringHelper.h"
#include "Inventory.h"
#include "Return.h"
#include "Borrow.h"
#include "History.h"


//----------------------------- makeTransaction() ------------------------------
//  Description:
//    -Constructs transaction object by parsing inputted string
//  Args:
//    str (string): descriptor of transaction
//  Return:
//    Transaction*, pointer to the transaction object
//------------------------------------------------------------------------------
Transaction* TransactionFactory::MakeTransaction(const string& str) const
{
    vector<string> splits = StringHelper::splitAndTrim(str, ' ');
    if(splits.size() == 0)
    {
        return new Transaction();
    }
    
    string transactionType = splits[0];
    if (transactionType == "R")
    {
        return new Return(str);
    }
    else if (transactionType == "I")
    {
        return new Inventory();
    }
    else if (transactionType == "B")
    {
        return new Borrow(str);
    }
    else if (transactionType == "H")
    {
        return new History(str);
    }

    return new Transaction();
    
}