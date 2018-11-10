// ----------------------------- StoreState ------------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Responsible for storing customer data in hash table and movie data in a map.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <map>
#include <vector>
#include "HashTable.h"
#include "Customer.h"
#include "Movie.h"

typedef HashTable<Customer> CustomerData;
typedef std::map<string, Movie*> MovieDataByKey;
typedef std::map<string, std::vector<Movie*>> MovieDataByTitle;

struct StoreState
{
    //------------------------------ ~StoreState() -----------------------------
    //  Description:
    //    -Destructor for store state, deletes all data in customer hash table
    //    and movie map
    //--------------------------------------------------------------------------
    ~StoreState()
    {
        customerData.deleteContents();
        for (auto movie : movieDataByKey)
        {
            delete movie.second;
        }
    }
    
    CustomerData customerData;
    MovieDataByKey movieDataByKey;
    MovieDataByTitle movieDataByTitle;
};
