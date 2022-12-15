/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Perishable														*
*					  Filename: Perishable.cpp													*
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Perishable.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

	const Date& Perishable::expiry() const
	{
		return m_expiry;
	}

	//destructor

	Perishable::~Perishable()
	{
		delete[] m_instructions;
	}

	int Perishable::readSku(std::istream& istr)
	{
		m_sku = ut.getint(10000, 39999, "SKU: ");
		return 0;
	}

	std::ofstream& Perishable::save(std::ofstream& ofstr) const
	{
		if (Item::m_state)
		{
			Item::save(ofstr);
			ofstr << "\t";
			if (m_instructions)
				ofstr << m_instructions;
			ofstr << "\t";
			m_expiry.displayUnformatted(ofstr);
		}
		return ofstr;
	}

	Perishable::Perishable()
	{
		m_instructions = nullptr;
	}

	Perishable::Perishable(const Perishable& p)
	{
		operator=(p);
	}

	Perishable& Perishable::operator=(const Perishable& p)
	{
		if (this != &p)
		{
			Item::operator=(p);
			ut.alocpy(m_instructions, p.m_instructions);
			m_expiry = p.m_expiry;
		}
		return *this;
	}

	//bool operator
	Perishable::operator bool() const
	{
		bool flag = 0;
		int tempMonth = m_expiry.retMonth();
		if (tempMonth != 4 && Item::operator bool())
		{
			flag = 1;
		}
		return flag;
	}

	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		Item::load(ifstr);
		char tempInstructions[50] = { "\0" };
		ifstr.getline(tempInstructions, 50, '\t');
		ifstr >> m_expiry;
		ifstr.ignore();
		if (ifstr.fail())
		{
			Item::m_state = "Input file stream read (perishable) failed!";
		}
		else
		{
			ut.alocpy(m_instructions, tempInstructions);
		}
		return ifstr;
	}

	std::ostream& Perishable::display(std::ostream& ostr) const
	{


		if (!Item::m_state)
		{
			ostr << m_state;
		}
		else
		{
			if (Item::linear())
			{

				Item::display(ostr);
				if (m_instructions && m_instructions[0] != '\0')
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}
				m_expiry.displayFormatted(ostr);
			}
			else
			{

				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				m_expiry.displayFormatted(ostr);
				if (m_instructions && m_instructions[0] != '\0')
					ostr << endl << "Handling Instructions: " << m_instructions;
				ostr << endl;
			}
		}

		return ostr;
	}

	std::istream& Perishable::read(std::istream& istr)
	{

		Item::m_minSkuNum = 10000;
		Item::m_maxSkuNum = 39999;
		Item::read(istr);
		cout << "Expiry date (YYMMDD): ";
		m_expiry.read(istr);
		istr.ignore();
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n')
		{
			char tempInstructions[1000] = { "\0" };
			istr.getline(tempInstructions, 1000, '\n');
			ut.alocpy(m_instructions, tempInstructions);
		}

		if (istr.fail())
		{
			Item::m_state = "Perishable console date entry failed!";
		}
		return istr;
	}
}