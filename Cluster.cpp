#include "Cluster.h"

//using Clustering::Point;

namespace Clustering
{
	//########## LNode (struct) #####################################################################################
	
	//---------- CONSTRUCTOR ----------------------------------------------------------------------------------------
	LNode::LNode(const Point &p, LNodePtr n)
	{
		point = p;
		next = n;
	}

	//########## Cluster (class) ####################################################################################

	//========== PRIVATE FUNCTIONS ==================================================================================

	void Cluster::__del()
	{

	}

	void Cluster::__cpy(LNodePtr pts)
	{

	}

	bool Cluster::__in(const Point &p) const
	{
		return false;
	}


	//========== CONSTRUCTORS =======================================================================================

	//---------- DEFAULT (NO-ARGUMENT) CONSTRUCTOR ------------------------------------------------------------------
	Cluster::Cluster()
	{

	}

	//---------- BIG 3: ONE-ARGUMENT CONSTRUCTOR --------------------------------------------------------------------
	Cluster::Cluster(const Cluster &cluster)
	{

	}

	//---------- BIG 3: ASSIGNMENT OPERATOR -------------------------------------------------------------------------
	Cluster &Cluster::operator=(const Cluster &cluster)
	{
	}

	//---------- BIG 3: DESTRUCTOR ----------------------------------------------------------------------------------
	Cluster::~Cluster()
	{

	}


	//========== GETTERS & SETTERS ==================================================================================

	//---------- GET SIZE -------------------------------------------------------------------------------------------
	int Cluster::getSize() const
	{
		return 0;
	}

	//---------- ADD POINT ------------------------------------------------------------------------------------------
	void Cluster::add(const Point &point)
	{

	}

	//---------- REMOVE POINT ---------------------------------------------------------------------------------------
	const Point& Cluster::remove(const Point &point)
	{
	}

	//---------- CONTAINS POINT? ------------------------------------------------------------------------------------
	bool Cluster::contains(const Point &point)
	{
		return false;
	}


	//========== OVERLOADED OPERATORS ===============================================================================

	//---------- [] -------------------------------------------------------------------------------------------------
	const Point& Cluster::operator[](unsigned int index) const
	{
	}

	//---------- += (Point ARGUMENT) --------------------------------------------------------------------------------
	Cluster& Cluster::operator+=(const Point &point)
	{
	}

	//---------- -= (Point ARGUMENT) --------------------------------------------------------------------------------
	Cluster& Cluster::operator-=(const Point &point)
	{
	}

	//---------- += (Cluster ARGUMENT) ------------------------------------------------------------------------------
	Cluster& Cluster::operator+=(const Cluster &cluster)
	{
	}

	//---------- -= (Cluster ARGUMENT) ------------------------------------------------------------------------------
	Cluster &Cluster::operator-=(const Cluster &cluster)
	{
	}


	//---------- << (friend) ----------------------------------------------------------------------------------------
	std::ostream& operator<<(std::ostream &ostream, const Cluster &cluster)
	{
	}

	//---------- >> (friend) ----------------------------------------------------------------------------------------
	std::istream& operator>>(std::istream &istream, Cluster &cluster)
	{
	}

	//---------- == (friend) ----------------------------------------------------------------------------------------
	bool operator==(const Cluster &cluster, const Cluster &cluster1)
	{
		return false;
	}

	//---------- != (friend) ----------------------------------------------------------------------------------------
	bool operator!=(const Cluster &cluster, const Cluster &cluster1)
	{
		return false;
	}

	//---------- + (friend) -----------------------------------------------------------------------------------------
	const Cluster operator+(const Cluster &cluster, const Point &point)
	{
	}

	//---------- - (friend) -----------------------------------------------------------------------------------------
	const Cluster operator-(const Cluster &cluster, const Point &point)
	{
	}

	//---------- + (friend) -----------------------------------------------------------------------------------------
	const Cluster operator+(const Cluster &cluster, const Cluster &cluster1)
	{
		//return Clustering::Cluster();
	}

	//---------- - (friend) -----------------------------------------------------------------------------------------
	const Cluster operator-(const Cluster &cluster, const Cluster &cluster1)
	{
		//return Clustering::Cluster();
	}
}