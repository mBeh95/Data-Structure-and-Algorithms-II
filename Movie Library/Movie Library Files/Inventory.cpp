#include "Inventory.h"
#include "StringHelper.h"
#include <iostream>


//------------------------------- isValid() ------------------------------------
//  Description:
//    -Default validitiy implementation
//  Return:
//    true, if valid
//
//------------------------------------------------------------------------------
bool Inventory::isValid() const
{
    return true;
}

//-------------------------------- Transact() ----------------------------------
//  Description:
//    -Performs inventory transaction, if successful, the movie store's inventory
//    is printed to the console.
//    -Prints all comedies, dramas, then classics, displaying the current stock
//    for all movies and the major actor for classics
//    -Prints error message if customer not found
//  Args:
//    state (StoreState&): current state of the movie store
//  Return:
//    True if inventory transaction successful
//------------------------------------------------------------------------------
bool Inventory::Transact(StoreState& state)
{
    cout << " ---------- INVENTORY ---------- " << endl;
    for (int i = static_cast<int>(MovieType::First); i < static_cast<int>(MovieType::Count); i++)
    {
        MovieType curType = static_cast<MovieType>(i);
        cout << Movie::movieTypeName(curType) << endl;
        cout << endl;
        for (auto movie : state.movieDataByKey)
        {
            if (movie.second->getMovieType() != curType)
            {
                continue;
            }
            cout << movie.second->getStock() << " - ";
            cout << movie.second->getTitle() << endl;
            
            if (movie.second->getMovieType() == MovieType::Classic)
            {
                cout << "         starring " << movie.second->getActor() << endl;
            }
            cout << endl;
        }
    }
    return true;
}


