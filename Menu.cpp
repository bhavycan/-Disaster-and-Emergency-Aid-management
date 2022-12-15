/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Menu															*
*					  Filename: Menu.cpp													*
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
#include <cstring>
#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace sdds
{
	Menu::Menu(unsigned int num, const char* str)
	{
		if (num < 15)
		{
			if (str != nullptr)
			{
				m_options = num;
				m_content = new char[strlen(str) + 1];
				strcpy(m_content, str);
			}
		}
	}

	Menu::~Menu()
	{
		delete[] m_content;
	}

	unsigned int Menu::run() const
	{
		cout << m_content;
		cout << "0- Exit" << endl;
		cout << "> ";
		int num = ut.getint(0, m_options);
		return num;
	}
}