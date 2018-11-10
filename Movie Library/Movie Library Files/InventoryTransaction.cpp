#include <stdio.h>
#include "InventoryTransaction.h"
#include "StringHelper.h"


//------------------------- InventoryTransaction() -----------------------------
//  Description:
//    -Constructs a transaction that affects inventory with default values
//------------------------------------------------------------------------------
InventoryTransaction::InventoryTransaction() : Transaction()
{
    mDescriptor = "";
    mCustomerId = -1;
}

//--------------------------- initFromDescriptor) ------------------------------
//  Description:
//    -Parses and validates transaction strings
//  Args:
//    descriptor (string&): transaction descriptor
//    typeId (string&): transaction type

//  Return:
//    True if string is valid and parsed
//    False if string contains invalid format/information
//------------------------------------------------------------------------------
bool InventoryTransaction::initFromDescriptor(const string& descriptor, const string& typeId)
{
    std::vector<string> splits = StringHelper::splitAndTrim(descriptor, ',');
    if(splits.size() < 1)
    {
        return false;
    }
    
    std::vector<string> splits2 = StringHelper::splitAndTrim(splits[0], ' ');
    if (splits2.size() < 5)
    {
        return false;
    }
    
    if (splits2[0] != typeId)
    {
        return false;
    }
    
    int custId = stoi(splits2[1]);
    if (custId < 0 || custId > MAX_VALID_CUST_ID)
    {
        return false;
    }
    
    if (splits2[2] != "D") //dvd
    {
        return false;
    }
    
    if (splits2[3] == "D") //drama
    {
        mDirector = StringHelper::concat(splits2, 4, splits2.size() - 1);
        mTitle = splits[1];
        mMovieType = MovieType::Drama;
    }
    else if (splits2[3] == "F") //comedy
    {
        mTitle = StringHelper::concat(splits2, 4, splits2.size() - 1);
        mYear = stoi(splits[1]);
        mMovieType = MovieType::Comedy;
    }
    else if (splits2[3] == "C") //classic
    {
        mMonth = stoi(splits2[4]);
        mYear = stoi(splits2[5]);
        mActor = StringHelper::concat(splits2, 6, splits2.size() - 1);
        mMovieType = MovieType::Classic;
    }
    else
    {
        return false;
    }
    
    mCustomerId = custId;
    return true;
}

//-------------------------------- findMovie() ----------------------------------
//  Description:
//    -Locates movie in map, and returns pointer to movie object if in stock, by
//    first searching by key, then title.
//    -If found by title, checks stock before returning movie
//    -If movie not found, returns null
//  Args:
//    state (StoreState&): current state of the movie store
//  Return:
//    Movie*, pointer to the movie object searched for
//------------------------------------------------------------------------------
Movie* InventoryTransaction::findMovie(StoreState& state) const
{
    if (mMovieType == MovieType::Drama)
    {
        return findMovieByKey(state, mDirector + "_" + mTitle, true);
    }
    else if (mMovieType == MovieType::Comedy)
    {
        return findMovieByKey(state, mTitle + "_" + to_string(mYear), true);
    }
    else if (mMovieType == MovieType::Classic)
    {
        //trying to find movie by key
        string key = to_string(mMonth) + "_" + to_string(mYear) + "_" + mActor;
        Movie* movie = findMovieByKey(state, key, false);
        if (movie == nullptr)
        {
            return nullptr;
        }
        if (movie->getStock() > 0)
        {
            return movie;
        }
        
        //couldn't find by key, find by title
        auto iter = state.movieDataByTitle.find(movie->getTitle());
        if (iter == state.movieDataByTitle.end())
        {
            return nullptr;
        }
        
        //found by title, search title list for stock
        std::vector<Movie*>& list = iter->second;
        for (Movie* movie : list)
        {
            if (movie->getStock() > 0)
            {
                return movie;
            }
        }
    }
    return nullptr;
}
//--------------------------- findMovieByKey() ---------------------------------
//  Description:
//    -Searches map for movie by key
//    -If not found, iterator will point to end of map, and return null
//  Args:
//    state (StoreState&): current state of the movie store
//    key (string&): movie's key
//    checkStock (bool): check if movie is in stock
//  Return:
//    Movie*, pointer to the movie object searched for
//------------------------------------------------------------------------------
Movie* InventoryTransaction::findMovieByKey(StoreState& state, const string& key,
                                            bool checkStock) const
{
    auto iter = state.movieDataByKey.find(key);
    if (iter == state.movieDataByKey.end())
    {
        return nullptr;
    }
    if (iter->second->getStock() <= 0 && checkStock)
    {
        return nullptr;
    }
    return iter->second;
}

//--------------------------- changeStockOfMovie() -----------------------------
//  Description:
//    -Updates stock of movie based on successful borrow or return functions.
//    -Validates customer Id and checks for stock of movie before updating
//  Args:
//    state (StoreState&): current state of the movie store
//    delta (int): change of stock (+1 for return, -1 for borrow)
//  Return:
//    true, if successfully updates stock
//    false, if invalid customer id or movie is out of stock for borrow
//------------------------------------------------------------------------------
bool InventoryTransaction::changeStockOfMovie(StoreState& state, int delta)
{
    Customer* customer = state.customerData.retrieve(getCustomerId());
    if (customer == nullptr)
    {
        mError = "Invalid customer ID " + to_string(getCustomerId());
        return false;
    }
    
    Movie* movie = findMovie(state);
    if (movie == nullptr)
    {
        mError = "Movie out of stock.";
        return false;
    }
    
    movie->changeStock(delta);
    
    string changeType = delta < 0 ? "B" : "R";
    customer->recordTransaction(changeType + " " + movie->getTitle());
    return true;
}






