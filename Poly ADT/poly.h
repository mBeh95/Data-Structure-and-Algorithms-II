// ------------------------------------------------ poly.h -------------------------------------------------------- 
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Jan 5, 2017
// Date of Last Modification: Jan 14, 2017
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The program takes in polynomial values and will do basic arthmetic, copy from one object to another, and
//			will output all the values from the object in proper polynomial format. The header contains all the 
//			functions needed for the cpp file
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
//				Assumptions: I'm assuming that if we recieve a negative exponent, we do not enter it into our array at
//							all. So if there are only negative exponents being read in, it will return a 0.
//				Assumption: if we recieved Poly(2,-5), I assumed that we would just set it up to be 0x^0
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Poly
{
public:
	//Constructors and destructor
	Poly(int num, int power);
	Poly(int num);
	Poly(const Poly &source);
	Poly();
	~Poly();

	//Getters and setters
	int getCoeff(int power) const;
	int setCoeff(int num, int power);


	//Operators
	Poly operator*(const Poly &rhs) const;
	Poly& operator*=(const Poly &rhs);

	Poly operator-(const Poly &rhs) const;
	Poly& operator-=(const Poly &rhs);

	Poly operator+(const Poly &rhs) const;
	Poly& operator+=(const Poly &rhs);

	bool operator==(const Poly &rhs) const;
	bool operator!=(const Poly &rhs) const;
	Poly& operator=(const Poly &rhs);

	friend istream& operator >> (istream &inStream, Poly &rhs);
	friend ostream& operator<<(ostream &outStream, Poly &rhs);

private:
	int num;
	int power;
	int size;
	int *coeffPtr;

	void changeSize(int power);
};

