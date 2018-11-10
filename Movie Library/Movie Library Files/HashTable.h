// ------------------------------- HashTable -----------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Partially implemented container class that hashes items into a vector
//    based on ID number.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes perfect hash.
//    Resizes dynamically upon insert.
// -----------------------------------------------------------------------------

#pragma once
#include <vector>


template <class T>
class HashTable
{
public:
    
    //-------------------------------- resize() --------------------------------
    //  Description:
    //    -Resizes vector to inputted capacity, sets all new buckets to null
    //  Args:
    //    capacity (int): size
    //--------------------------------------------------------------------------
    void resize(int capacity)
    {
        size_t oldCapacity = mTable.capacity();
        
        mTable.resize(capacity + 1);
        
        for (size_t i = oldCapacity; i < capacity + 1; i++)
        {
            mTable[i] = nullptr;
            
        }
    }
    
    //--------------------------- deleteContents() -----------------------------
    //  Description:
    //    -deletes contents of hash table
    //--------------------------------------------------------------------------
    void deleteContents()
    {
        for (int i = 0; i < mTable.capacity(); i++)
        {
            if (mTable[i] != nullptr)
            {
                delete mTable[i];
                mTable[i] = nullptr;
            }
        }
    }
    
    //---------------------------------- insert() ------------------------------
    //  Description:
    //    - inserts item into hashtable, resizing as needed
    //    - assumes perfect hash
    //  Args:
    //    pItem (T*): pointer to item to be inserted
    //  Return:
    //    true, item is successfully inserted into hashtable
    //    false, item fails to be inserted into hashtable
    //--------------------------------------------------------------------------
    bool insert(T* pItem)
    {
        int hash = pItem->getId();
        if (hash >= mTable.capacity())
        {
            resize(hash * 2);
        }
        if (mTable[hash] != nullptr)
        {
            return false;
        }
        mTable[hash] = pItem;
        return true;
    }
    
    //-------------------------------- retrieve() ------------------------------
    //  Description:
    //    -Retrieves an item from the Hashtable via id number
    //  Args:
    //    id (int): item's id number
    //  Return:
    //    T*, pointer to the item, returns null if item not found
    //--------------------------------------------------------------------------
    T* retrieve(int id) const
    {
        if(id >= mTable.capacity())
        {
            return nullptr;
        }
        return mTable[id];
    }
    
private:
    
    std::vector<T*> mTable;
    
};


