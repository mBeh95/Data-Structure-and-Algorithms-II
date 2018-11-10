#include "DescriptorQueue.h"
#include <string>
#include <fstream>
#include <queue>
#include "StringHelper.h"
using namespace std;

//---------------------------- DescriptorQueue() -------------------------------
//  Description:
//    -Constructs a queue of strings from inputted file
//  Args:
//    path (string): data file
//------------------------------------------------------------------------------
DescriptorQueue::DescriptorQueue(string path)
{
	ifstream infile(path);
	string line;
	while (getline(infile, line))
	{
        mQueue.push(StringHelper::trim(line));
	}
}

//----------------------------- hasDescriptor() --------------------------------
//  Description:
//    -Checks if queue has a descriptor
//  Return:
//    true, queue has a descriptor
//    false, queue is empty
//------------------------------------------------------------------------------
bool DescriptorQueue::hasDescriptor() const
{
	return !mQueue.empty();
}

//---------------------------- nextDescriptor() --------------------------------
//  Description:
//    -removes and returns descriptor from front of queue
//  Return:
//    string, the first descriptor in the queue
//------------------------------------------------------------------------------
string DescriptorQueue::nextDescriptor()
{
	string result = mQueue.front();
	mQueue.pop();
	return result;
}
