// ------------------------------------------------ poly.cpp -------------------------------------------------------- 
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Jan 5, 2017
// Date of Last Modification: Jan 14, 2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The program takes in polynomial values and will do basic arthmetic, copy from one object to another, and
//			will output all the values from the object in proper polynomial format. The cpp file contains all of the 
//			necesarry code for this program to work.
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
//				Assumptions: I'm assuming that if we recieve a negative exponent, we do not enter it into our array at
//							all. So if there are only negative exponents being read in, it will return a 0.
//				Assumption: if we recieved Poly(2,-5), I assumed that we would just set it up to be 0x^0
// --------------------------------------------------------------------------------------------------------------------

#include "poly.h"
#include <iostream>
using namespace std;

// ------------------------------------Constructor---------------------------------------------------- 
// Description: Takes in the number and power(exponent), places them into the pointer array and will
//				intialize the size to be one value greater than the power in order to have access to 
//				the full array. If the power is negative it will be set to 0x^0.
// ---------------------------------------------------------------------------------------------------
Poly::Poly(int num, int power)
{
	this->num = num;
	this->power = power;

	if (power >= 0)
	{
		size = (power + 1);

		coeffPtr = new int[size];

		for (int i = 0; i < size; i++)
		{
			coeffPtr[i] = 0;
		}

		setCoeff(num, power);
	}
	else //if the power given is negative then set it to be 0x^x
	{
		size = 1;
		coeffPtr = new int[1];
		coeffPtr[0] = 0;
	}

}

// ------------------------------------Constructor---------------------------------------------------- 
// Description: Takes in the number provided and initializes it as #x^0 and sets size to 1
// ---------------------------------------------------------------------------------------------------
Poly::Poly(int num)
{
	size = 1;
	coeffPtr = new int[1];
	coeffPtr[0] = num;
}

// ------------------------------------DeepCopyConstructor--------------------------------------------
// Description: Copies all the values from the source and places them accordingly into the object.
// ---------------------------------------------------------------------------------------------------
Poly::Poly(const Poly & source)
{
	size = source.size;
	coeffPtr = new int[size];

	for (int i = 0; i < size; i++)
	{
		coeffPtr[i] = source.coeffPtr[i];
	}
}

// ------------------------------------DefaultConstructor----------------------------------------------- 
// Description: The default constructor that will set the polynomial as 0x^0 until more values are
//				added.
// ---------------------------------------------------------------------------------------------------
Poly::Poly()
{
	size = 1;
	coeffPtr = new int[1];
	coeffPtr[0] = 0;
}

// ------------------------------------Destructor----------------------------------------------- 
// Description: Deletes the pointer array, to make sure no memory was leaked.
// ---------------------------------------------------------------------------------------------------
Poly::~Poly()
{
	delete[] coeffPtr;
	coeffPtr = NULL;
}

// --------------------------------------------getCoeff----------------------------------------------- 
// Description: The function will return the coefficient if it is within the bounds of the exponent, otherwise
//				it will just return 0.
// ---------------------------------------------------------------------------------------------------
int Poly::getCoeff(int power) const
{
	if (power < size && power >= 0)//Keep within the bounds given
	{
		return coeffPtr[power];
	}
	else
	{
		return 0;
	}
}

// ------------------------------------setCoeff------------------------------------------------------- 
// Description: Will set the coefficient to the power that is indicated. If the power is bigger than 
//				the changeSize function will be called. And if a negative power is given then you return
//				zero.
// ---------------------------------------------------------------------------------------------------
int Poly::setCoeff(int num, int power)
{
	if(power < 0)
	{
		return 0;
	}
	else if (power >= size)
	{
		changeSize(power);
	}
	if (coeffPtr[power] != num)
	{
		coeffPtr[power] = num;
	}
	return coeffPtr[power];
}

// ------------------------------------changeSize----------------------------------------------- 
// Description: This function will be called if power is greater than the size. First it creates a 
//				temp pointer and initializes the tempSize to be power+1, after giveing tempPtr its 
//				new size, it will use the for loop to first enter all the values of the coeffPtr and
//				in the second loop it will go from the smaller size of coeffPtr to the bigger tempSize
//				and set everything to become zero. Then delete coeffPtr and set it to Null. Set coeffPtr 
//				equal to tempPtr and then set tempPtr to Null.
// ---------------------------------------------------------------------------------------------------
void Poly::changeSize(int power)
{
	int tempSize;
	int *tempPtr;

	if (size <= power)
	{
		tempSize = (power + 1);
	}
	tempPtr = new int[tempSize];

	for (int i = 0; i < size; i++)
	{
		tempPtr[i] = coeffPtr[i];
	}

	for (int i = size; i < tempSize; i++)
	{
		tempPtr[i] = 0;
	}

	size = tempSize;
	delete[] coeffPtr;
	coeffPtr = NULL;
	coeffPtr = tempPtr;
	tempPtr = NULL;
}

// ------------------------------------operator*----------------------------------------------- 
// Description: Calls on the operator*= to multiply the terms
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly & rhs) const
{
	Poly multiOn = *this;
	multiOn *= rhs;
	return multiOn;
}

// ------------------------------------------operator*=----------------------------------------------- 
// Description: Multiply the coefficients while adding the exponents, and place the new values into
//				the sum of the exponents. The temp pointer is given the multiplication size and then in the
//				nested for loops, you would add to the temp pointer the multiplication value of the two pointer
//				arrays. Set the size to the multiSize and set coeffPtr equal to tempPtr.
// ---------------------------------------------------------------------------------------------------
Poly & Poly::operator*=(const Poly & rhs)
{
	int multiSize = size + rhs.size - 1; //Add the two sizes to get the new size
	int *tempPtr = new int[multiSize];

	for (int i = 0; i < multiSize; i++) //Set everything to zero
	{
		tempPtr[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rhs.size; j++)
		{
			tempPtr[j + i] += coeffPtr[i] * rhs.coeffPtr[j];
		}
	}
	size = multiSize;
	delete[] coeffPtr;
	coeffPtr = NULL;
	coeffPtr = tempPtr;
	tempPtr = NULL;

	return *this;
}

// ------------------------------------operator------------------------------------------------ 
// Description: Calls on the operator-= to substract the terms.
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly & rhs) const
{
	Poly subOn = *this;
	subOn -= rhs;
	return subOn;

}

// ------------------------------------------operator-=----------------------------------------------- 
// Description: Subtracts the terms if their exponents are the same. 
//				I create a temp pointer and set it up to the bigger size of the two pointers. The first
//				loop initializes all tempPtr values to zero. The second loop adds values from the coeffPtr
//				and third loops lets the rhs pointer do subtraction to the tempPtr.
//				After we set the coeffPtr to TempPtr and set the size to the tempSize.
// ---------------------------------------------------------------------------------------------------
Poly & Poly::operator-=(const Poly & rhs)
{
	int tempSize;
	if (size > rhs.size)//Takes the bigger size to set it for the temp pointer
	{
		tempSize = size;
	}
	else
	{
		tempSize = rhs.size;
	}

	int *tempPtr = new int[tempSize];

	for (int i = 0; i < tempSize; i++)
	{
		tempPtr[i] = 0;
	}

	for (int i = 0; i < size; i++)//Add in the values in the temp point
	{
		tempPtr[i] += coeffPtr[i];
	}

	for (int i = 0; i < rhs.size; i++)//Subtract
	{
		tempPtr[i] -= rhs.coeffPtr[i];
	}
	size = tempSize;
	delete[] coeffPtr;
	coeffPtr = NULL;
	coeffPtr = tempPtr;
	tempPtr = NULL;

	return *this;
}

// ------------------------------------operator+----------------------------------------------- 
// Description: Calls on the operator+= to add the terms.
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly & rhs) const
{
	Poly addOn = *this;
	addOn += rhs;
	return addOn;

}

// ------------------------------------------operator+=----------------------------------------------- 
// Description: I creat a temp pointer and set it up to the bigger size of the two pointers. The first
//				loop initializes all tempPtr values to zero. The second and third loops add the both 
//				the pointers to the tempPtr. After we set the coeffPtr to TempPtr and set the size to 
//				the tempSize.
// ---------------------------------------------------------------------------------------------------
Poly & Poly::operator+=(const Poly & rhs)
{
	int tempSize;
	if (size > rhs.size)//Take the bigger size for the temp pointer
	{
		tempSize = size;
	}
	else
	{
		tempSize = rhs.size;
	}

	int *tempPtr = new int[tempSize];

	for (int i = 0; i < tempSize; i++)//set everything to zero
	{
		tempPtr[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		tempPtr[i] = tempPtr[i] + coeffPtr[i];
	}

	for (int i = 0; i < rhs.size; i++)
	{
		tempPtr[i] = tempPtr[i] + rhs.coeffPtr[i];
	}
	size = tempSize;
	delete[] coeffPtr; //Delete coeffPtr
	coeffPtr = tempPtr; // Set it to tempPtr to recieve new values
	tempPtr = NULL;
	return *this;
}

// ---------------------------------------Operator==----------------------------------------------- 
// Description: Takes the values and checks to see if they match each other. If equal, it will 
//				return true. If even one pair of values are not equal then it will return false. If 
//				one size is bigger than the other, then the rest of the bigger size pointer after checking
//				it to the smaller size should be equal to zero.
// ---------------------------------------------------------------------------------------------------
bool Poly::operator==(const Poly & rhs) const
{
	if (size == rhs.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (coeffPtr[i] != rhs.coeffPtr[i])
			{
				return false;
			}
		}
	}
	else if (size > rhs.size)
	{
		for (int i = 0; i < rhs.size; i++)//first loop checks up to the smaller size to see if they are equal
		{
			if (coeffPtr[i] != rhs.coeffPtr[i])
			{
				return false;
			}
		}
		for (int i = rhs.size; i < size; i++)// Checks from the smaller size to bigger 
		{									// size for larger Array to make sure they are zero.
			if (coeffPtr[i] != 0)
			{
				return false;
			}
		}
	}
	else if (size < rhs.size)// Similar to the if statement before it, just with size being smaller.
	{
		for (int i = 0; i < size; i++)
		{
			if (coeffPtr[i] != rhs.coeffPtr[i])
			{
				return false;
			}
		}
		for (int i = size; i < rhs.size; i++)
		{
			if (rhs.coeffPtr[i] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

// -----------------------------------------!=Operator----------------------------------------------- 
// Description: Takes the equality operator and reverses the process to check for inequalities in the
//				pointer array. If equal, it will return false. If even one pair of values are not equal
//				then it will return true;
// ---------------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly & rhs) const
{
	return !(coeffPtr == rhs.coeffPtr);
}

// -------------------------------------------=Operator----------------------------------------------- 
// Description: Sets it up so that the object values will be equal to the rhs values along with creating
//				a new size if needed. If the size is bigger than the rhs size, set everything after it to
//				to be 0. If size is smaller, increase it. I do not use the changeSize function because 
//				the values will be replaced by the rhs values.
// ---------------------------------------------------------------------------------------------------
Poly & Poly::operator=(const Poly & rhs)
{
	if (size == rhs.size)
	{
		for (int i = 0; i < size; i++)
		{
			coeffPtr[i] = rhs.coeffPtr[i];
		}
	}
	else if (size > rhs.size)
	{
		for (int i = 0; i < rhs.size; i++)
		{
			coeffPtr[i] = rhs.coeffPtr[i];
		}
		for (int i = rhs.size; i < size; i++) // set every after rhs size to 0
		{
			coeffPtr[i] = 0;
		}
	}
	else if (size < rhs.size)
	{
		delete[] coeffPtr; // if the rhs size is bigger, delete coeffPtr
		coeffPtr = new int[rhs.size]; //set new size to rhs size
		size = rhs.size;
		for (int i = 0; i < size; i++) // set coeffPtr to rhs
		{
			coeffPtr[i] = rhs.coeffPtr[i];
		}
	}
	return *this;
}

// ------------------------------------istream &operator>>------------------------------------------ 
// Description: Recieves input from the user and places them into the pointer array according to the
//				exponent value. The while loop will keep going until the end of the input but the first
//				if statement declares that if the termination values are called then break the loop, 
//				indicating the end of the loop. If any negative powers are given besides the termination
//				pair then it will continue to the next loop without adding anything to the pointer array
//				If the input is valid, the values will be added to the pointer array.
// ---------------------------------------------------------------------------------------------------
istream &operator >> (istream &inStream, Poly &rhs)
{
	while (!cin.eof())
	{
		inStream >> rhs.num >> rhs.power;
		if (rhs.num == -1 && rhs.power == -1)
		{
			break;
		}
		else if (rhs.power <= -1 && rhs.num != -1)//if given a negative number, skip it and don't add it in
		{
			continue;
		}
		else
		{
			if (rhs.size <= rhs.power)//If the power given is greater or equal to the size, then call the changeSize function
			{
				rhs.changeSize(rhs.power);
			}
			rhs.setCoeff(rhs.num, rhs.power);
		}
	}
	return inStream;
}

// ------------------------------------Ostream& Operator----------------------------------------------- 
// Description: Output all values from the coeffPtr and formats them as polynomials. The bool will check 
//				to see that if all the numbers are zero, then it will only return a single zero. In the for 
//				loop, if the pointer value keeps being zero then it will not advance to setting the bool
//				to become false. Otherwise it will add to the outStream according to what values are being
//				given.
// ---------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & outStream, Poly & rhs)
{
	outStream << " ";
	bool zeroBool = true;

	for (int i = rhs.size - 1; i >= 0; i--)
	{
		if (rhs.coeffPtr[i] == 0)// if the value is zero, skip the current loop
		{
			continue;
		}
		else if (rhs.coeffPtr[i] > 0)// for positve values
		{
			outStream << "+" << rhs.coeffPtr[i];
			if (i == 1)
			{
				outStream << "x" << " ";
			}
			else if (i == 0)
			{
				outStream << " ";
			}
			else
			{
				outStream << "x^" << i << " ";
			}
		}
		else if (rhs.coeffPtr[i] < 0)// For negative values
		{
			outStream << rhs.coeffPtr[i];
			if (i == 1)
			{
				outStream << "x" << " ";
			}
			else if (i == 0)
			{
				outStream << " ";
			}
			else
			{
				outStream << "x^" << i << " ";
			}
		}
		zeroBool = false; //becomes false only if there are non-zero values
	}
	if (zeroBool == true)
	{
		outStream << 0;
	}

	return outStream;
}