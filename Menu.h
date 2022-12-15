/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Menu																*
*					  Filename: Menu.h															*
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds
{
	class Menu
	{
		char* m_content{};
		unsigned int m_options = 0u;
	public:
		Menu(unsigned int num = 16, const char* str = nullptr);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		virtual ~Menu();
		unsigned int run()const;
	};
}
#endif // !SDDS_MENU_H
