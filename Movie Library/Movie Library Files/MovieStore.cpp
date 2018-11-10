//runs entire thing
//reads in customers, movies, transactions
//executes all transactions
//assumptions: files formatted correctly

#include "MovieStore.h"
#include "StoreState.h"
#include "DescriptorQueue.h"
#include "Transaction.h"
#include "TransactionFactory.h"
#include "MovieFactory.h"
#include <iostream>


//--------------------------------- Run() --------------------------------------
//  Description:
//    -Runs movie store by reading in inventory data, customer data, and
//    transactions to appropriate queues, then executes all transacions.
//  Args:
//    inventoryPath (string&): path to inventory data
//    customersPath (string&): path to customer data
//    transactionsPath (string&): path to transaction data
//------------------------------------------------------------------------------
void MovieStore::Run(const string& inventoryPath, const string& customersPath,
                     const string& transactionsPath) const
{
	DescriptorQueue transactionQueue(transactionsPath);
    DescriptorQueue inventoryQueue(inventoryPath);
    DescriptorQueue customerQueue(customersPath);

    TransactionFactory transactionFactory;
    MovieFactory movieFactory;

    StoreState state;

    // parse inventory, checks if movie is valid, if not, prints error & deletes.
    // populates 2 maps, one by key and one by title using a vector for all
    // movies that share said title.
    while(inventoryQueue.hasDescriptor())
    {
        string descriptor = inventoryQueue.nextDescriptor();
        Movie* movie = movieFactory.MakeMovie(descriptor);
        if (movie->isValid())
        {
            state.movieDataByKey.insert(make_pair(movie->getKey(), movie));
            auto iter = state.movieDataByTitle.find(movie->getTitle());
            if (iter == state.movieDataByTitle.end())
            {
                std::vector<Movie*> list;
                list.push_back(movie);
                state.movieDataByTitle.insert(make_pair(movie->getTitle(), list));
            }
            else
            {
                iter->second.push_back(movie);
            }
            
        }
        else
        {
            cerr << movie->getError() << endl;
            delete movie;
        }
    }

    // parse customers, checks if customer is valid, if not, prints error & deletes.
    while(customerQueue.hasDescriptor())
    {
        string descriptor = customerQueue.nextDescriptor();
        Customer* customer = new Customer(descriptor);
        if (customer->isValid())
        {
            if(state.customerData.retrieve(customer->getId()) == nullptr)
            {
                state.customerData.insert(customer);
            }
            else
            {
                cerr << "Duplicate customer ID: " + to_string(customer->getId()) << endl;
                delete customer;
            }
        }
        else
        {
            cerr << customer->getError() << endl;
            delete customer;
        }
    }

    // parse transactions, checks if trandaction is valid, if not, prints error.
    while (transactionQueue.hasDescriptor())
    {
        string descriptor = transactionQueue.nextDescriptor();
        Transaction* transaction = transactionFactory.MakeTransaction(descriptor);
        if (transaction->isValid())
        {
            if (!transaction->Transact(state))
            {
                cerr << descriptor << ": " << transaction->getError() << endl;
            }
        }
        else
        {
            cerr << descriptor << ": " << transaction->getError() << endl;
        }
        delete transaction;
    }
}
