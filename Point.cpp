#include "Point.h"
#include <cmath>

using std::sqrt;
using std::pow;

namespace Clustering
{
	unsigned int Point::__idGen = 0;	//ID generator initialization

//============== CONSTRUCTORS ========================================================================================

	//---------- DEFAULT (NO-ARGUMENT) CONSTRUCTOR -------------------------------------------------------------------
	Point::Point()
	{
		//Assign an ID to the point and increment the static ID variable
		__id = __idGen;
		++__idGen;

		//Initialize the Point object with 0 dimensions (might not be necessary)
		__dim = 0;

		//Initialize the Point object's values array to NULL
		__values = NULL;
	}

	//---------- ONE-ARGUMENT CONSTRUCTOR ----------------------------------------------------------------------------
	Point::Point(int i)
	{
		//Assign an ID to the point and increment the static ID variable
		__id = __idGen;
		++__idGen;

		//Assign the value passed in as the number of dimensions of the point
		__dim = i;

		//Dynamically allocate an array of doubles based on the number of dimensions passed in
		__values = new double[__dim];

		//Set all dimensions to a default value of zero
		for (int index = 0; index < __dim; ++index)
		{
			__values[index] = 0;
		}
	}

	//---------- (OPTIONAL) DOUBLE ARRAY ARGUMENT CONSTRUCTOR --------------------------------------------------------
	Point::Point(int i, double* specimenArray)
	{
		//Assign an ID to the point and increment the static ID variable
		__id = __idGen;
		++__idGen;

		//Assign the value passed in as the number of dimensions of the point
		__dim = i;

		//Dynamically allocate an array of doubles based on the number of dimensions passed in
		__values = new double[__dim];

		//Copy the values from the specimen array into this object's array
		for (int index = 0; index < i; ++index)
		{
			__values[index] = specimenArray[index];
		}
	}

//============== BIG 3: cpy ctor, overloaded operator=, dtor =========================================================

	//---------- COPY CONSTRUCTOR ------------------------------------------------------------------------------------
	Point::Point(const Point &specimen)
	{
		//Copy the passed in point's ID
		__id = (unsigned int)specimen.getId();

		//Assign the number of dimensions of the point
		__dim = specimen.getDims();

		//Dynamically allocate an array of doubles based on the number of dimensions passed in
		__values = new double[__dim];

		//Copy all of the passed in point's values
		for (int i = 0; i < specimen.getDims(); ++i)
		{
			__values[i] = specimen.getValue(i);
		}
	}

	//---------- OVERLOADED ASSIGNMENT OPERATOR ----------------------------------------------------------------------
	Point& Point::operator=(const Point &specimen)
	{
		//Check for self-assignment
		if (this == &specimen) return *this;

		//Copy the passed in point's ID
		__id = (unsigned int)specimen.getId();

		//Check to see if the current object's valueArray is the correct size to receive the specimen's values;
		//if not, allocate a new array and de-allocate the existing array
		if (__dim != specimen.getDims())
		{
			//Create a local variable to allocate a new array of the proper size
			double* new_values;
			new_values = new double[specimen.getDims()];

			//De-allocate the existing improperly sized array
			delete [] __values;

			//Point the existing array name at the new array
			__values = new_values;
		}

		//Assign the number of dimensions of the point
		__dim = specimen.getDims();

		//Copy all of the passed in point's values
		for (int i = 0; i < specimen.getDims(); ++i)
		{
			__values[i] = specimen.getValue(i);
		}

		return *this;
	}

	Point::~Point()
	{
		delete [] __values;
	}


//==========ACCESSORS & MUTATORS======================================================================================

	//---------- GET ID ----------------------------------------------------------------------------------------------
	int Point::getId() const
	{
		return (int)__id;
	}

	//---------- GET NUMBER OF DIMENSIONS ----------------------------------------------------------------------------
	int Point::getDims() const
	{
		return __dim;
	}

	//---------- SET VALUE -------------------------------------------------------------------------------------------
	void Point::setValue(int i, double value)
	{
//		__values[i] = value;

		//Make sure the requested position is within the bounds of the values array
		if (i < __dim)
		{
			__values[i] = value;
		}
		else
		{
			std::cout << "\n ERROR: setValue(): Requested position is out of bounds." << std::endl << std::endl;
		}
	}

	//---------- GET VALUE -------------------------------------------------------------------------------------------
	double Point::getValue(int i) const
	{
//		return __values[i];

		//Make sure the requested position is within the bounds of the values array
		if (i < __dim)
		{
			return __values[i];
		}
		else
		{
			std::cout << "\n ERROR: getValue(): Requested position is out of bounds." << std::endl << std::endl;
		}
	}

//============== FUNCTIONS ===========================================================================================
	double Point::distanceTo(const Point &pointB) const
	{
//		double distance = sqrt(pow(pointB.getX()-x,2)
//							   +pow(pointB.getY()-y,2)
//							   +pow(pointB.getZ()-z,2));

		double distance = 0;

		for (int i = 0; i < __dim; ++i)
		{
			distance += pow(pointB.getValue(i) - __values[i],2);
		}

		return sqrt(distance);
	}


//============== OVERLOADED OPERATORS ================================================================================
	//---------- MEMBERS ---------------------------------------------------------------------------------------------

	Point& Point::operator*=(double multiplier) // p *= 6; p.operator*=(6);
	{
		for (int i = 0; i < __dim; ++i)
			{
				__values[i] = __values[i] * multiplier;
			}

		return *this;
	}

	Point& Point::operator/=(double divisor)
	{
		for (int i = 0; i < __dim; ++i)
		{
			__values[i] = __values[i] / divisor;
		}

		return *this;
	}

	const Point Point::operator*(double d) const // prevent (p1 * 2) = p2;
	{
		//return Point(0);
	}

	const Point Point::operator/(double d) const // p3 = p2 / 2;
	{
		//return Point(0);
	}

	//---------- [] OVERLOADED SUBSCRIPT OPERATORS -------------------------------------------------------------------
	double& Point::operator[](int index)
	{
		return __values[index];
	}

	//---------- FRIENDS ---------------------------------------------------------------------------------------------

	Point& operator+=(Point &point1, const Point &point2)
	{
		if (point1.getDims() == point2.getDims())
		{
			for (int i = 0; i < point1.getDims(); ++i)
			{
				point1.setValue(i, point1.getValue(i) + point2.getValue(i));
			}
		}
		else std::cout << "\nERROR: Point::operator+=: Unequal dimensions." << std::endl << std::endl;

		return point1;
	}

	Point& operator-=(Point &point1, const Point &point2)
	{
		if (point1.getDims() == point2.getDims())
		{
			for (int i = 0; i < point1.getDims(); ++i)
			{
				point1.setValue(i, point1.getValue(i) - point2.getValue(i));
			}
		}
		else std::cout << "\nERROR: Point::operator+=: Unequal dimensions." << std::endl << std::endl;

		return point1;
	}

	//---------- + OVERLOADED ADDITION OPERATOR (friend) -------------------------------------------------------------
	const Point operator+(const Point &point1, const Point &point2)
	{
		Point newPoint(point1.getDims());

		if (point1.getDims() == point2.getDims())
		{
			for (int i = 0; i < point1.getDims(); ++i)
			{
				newPoint.setValue(i, point1.getValue(i) + point2.getValue(i));
			}
		}
		else std::cout << "\nERROR: Point::operator+: Unequal dimensions." << std::endl << std::endl;

		return newPoint;
	}
	//---------- - OVERLOADED SUBTRACTION OPERATOR (friend) ----------------------------------------------------------
	const Point operator-(const Point &point1, const Point &point2)
	{
		Point newPoint(point1.getDims());

		if (point1.getDims() == point2.getDims())
		{
			for (int i = 0; i < point1.getDims(); ++i)
			{
				newPoint.setValue(i, point1.getValue(i) - point2.getValue(i));
			}
		}
		else std::cout << "\nERROR: Point::operator-: Unequal dimensions." << std::endl << std::endl;

		return newPoint;
	}

	//---------- == OVERLOADED EQUALITY OPERATOR (friend) ------------------------------------------------------------
	bool operator==(const Point &point1, const Point &point2)
	{
		bool sameness = true;

		if (point1.getId() == point2.getId())
		{
			for (int i = 0; sameness && i < point1.getDims(); ++i)
			{
				if (point1.getValue(i) != point2.getValue(i)) sameness = false;
			}
		}
		else sameness = false;

		return sameness;
	}

	//---------- != OVERLOADED INEQUALITY OPERATOR (friend) ----------------------------------------------------------
	bool operator!=(const Point &point1, const Point &point2)
	{
		return !(point1 == point2);
	}

	//---------- < OVERLOADED LESS THAN OPERATOR (friend) ------------------------------------------------------------
	bool operator<(const Point &point1, const Point &point2)
	{
		bool lessThan = false;

		//If the same point is being compared to itself, there's no need to compare each dimension
		if (point1.getId() != point2.getId())
		{
			for (int i = 0; !lessThan && i < point1.getDims(); ++i)
			{
				if (point1.getValue(i) < point2.getValue(i)) lessThan = true;
			}
		}

		return lessThan;
	}

	//---------- > OVERLOADED GREATER THAN OPERATOR (friend) ---------------------------------------------------------
	bool operator>(const Point &point1, const Point &point2)
	{
		bool greaterThan = false;

		//If the same point is being compared to itself, there's no need to compare each dimension
		if (point1.getId() != point2.getId())
		{
			for (int i = 0; !greaterThan && i < point1.getDims(); ++i)
			{
				if (point1.getValue(i) > point2.getValue(i)) greaterThan = true;
			}
		}

		return greaterThan;
	}

	//---------- <= OVERLOADED LESS THAN OR EQUAL TO OPERATOR (friend) -----------------------------------------------
	bool operator<=(const Point &point1, const Point &point2)
	{
		bool lessThanOrEqual = true;

		//If the same point is being compared to itself, there's no need to compare each dimension
		if (point1.getId() != point2.getId())
		{
			for (int i = 0; lessThanOrEqual && i < point1.getDims(); ++i)
			{
				if (point1.getValue(i) > point2.getValue(i)) lessThanOrEqual = false;
			}
		}

		return lessThanOrEqual;
	}

	//---------- >= OVERLOADED GREATER THAN OR EQUAL TO OPERATOR (friend) --------------------------------------------
	bool operator>=(const Point &point1, const Point &point2)
	{
		bool greaterThanOrEqual = true;

		//If the same point is being compared to itself, there's no need to compare each dimension
		if (point1.getId() != point2.getId())
		{
			for (int i = 0; greaterThanOrEqual && i < point1.getDims(); ++i)
			{
				if (point1.getValue(i) < point2.getValue(i)) greaterThanOrEqual = false;
			}
		}

		return greaterThanOrEqual;
	}

	std::ostream& operator<<(std::ostream &ostream, const Point &point)
	{
	}

	std::istream& operator>>(std::istream &istream, Point &point)
	{
	}
}