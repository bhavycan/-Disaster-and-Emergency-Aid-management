/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Iproduct															*
*					  Filename: Iproduct.cpp													*
*					  Version 1.0																*
*					  Author: Bhavy Piyushkumar Patel											*
*					  Revision History															*
*					  -----------------------------------------------------------				*
*					  Date      Reason															*
*					  2022/04/06  completed MS4													*
*					  -----------------------------------------------------------				*
*					  I have done all the coding by myself and only copied the code				*
*					  that my professor provided to complete my workshops and assignments.		*
*					  ----------------------------------------------------------				*
*												- Bhavy Piyushkumar Patel						*
 ************************************************************************************************/


#include "iProduct.h"
using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const iProduct& i)
	{
		return i.display(ostr);
	}

	std::istream& operator>>(std::istream& istr, iProduct& i)
	{
		return i.read(istr);
	}

}

