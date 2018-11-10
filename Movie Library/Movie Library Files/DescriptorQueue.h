// ---------------------------- DescriptorQueue --------------------------------
// Helen Mirabella, Prarin Behdarvandian  CSS-343-C
// Created:  February 25, 2017
// Modified: March 15, 2017
// -----------------------------------------------------------------------------
//  Purpose:
//    Reads file and parses each string into a queue.
// -----------------------------------------------------------------------------
//  Notes:
//    Assumes well formatted data.
// -----------------------------------------------------------------------------
#pragma once
#include <string>
#include <queue>
using namespace std;

class DescriptorQueue
{
public:
    DescriptorQueue(string path);
    
    bool hasDescriptor() const;
    string nextDescriptor();
private:
	queue<string> mQueue;
};