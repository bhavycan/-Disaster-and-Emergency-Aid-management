/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: status															*
*					  Filename: status.cpp													*
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

#include <iostream>
#include "Utils.h"
#include "Status.h"

using namespace std;

namespace sdds
{
	Status::Status(const Status& s)
	{
		if (!s)
		{
			*this = s;
		}
	}

	Status& Status::operator=(const Status& s)
	{
		if (this != &s)
		{
			ut.alocpy(m_description, s.m_description);
			m_code = s.m_code;
		}
		return *this;
	}

	Status& Status::operator=(int num)
	{
		m_code = num;
		return *this;
	}
	Status::Status(const char* str)
	{
		if (str != nullptr)
		{
			ut.alocpy(m_description, str);
		}
		else
		{
			m_description = nullptr;
		}
		m_code = 0;
	}
	Status::operator int() const
	{
		return m_code;
	}
	Status::operator const char* () const
	{
		return m_description;
	}
	Status::operator bool() const
	{
		bool flag = 1;
		if (m_description != nullptr)
		{
			flag = 0;
		}
		return flag;
	}


	Status& Status::operator=(const char* str)
	{
		ut.alocpy(m_description, str);
		return *this;
	}

	Status::~Status()
	{
		delete[] m_description;
	}
	Status& Status::clear()
	{
		delete[] m_description;
		m_description = nullptr;
		m_code = 0;
		return *this;
	}

	ostream& operator<<(ostream& ostr, const Status& s)
	{
		if (!s)
		{
			if ((int)s != 0)
			{
				ostr << "ERR#" << (int)s << ": ";
			}
			ostr << (const char*)s;
		}

		return ostr;
	}
}

