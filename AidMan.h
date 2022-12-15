/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: AidMan															*
*					  Filename: AidMan.h														*
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


#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"
#include "Perishable.h"

namespace sdds
{
	const int sdds_max_num_items = 100;

	class AidMan :public Menu

	{
		char* m_file{};			//private member

		iProduct* m_ptr[sdds_max_num_items]{};

		int m_iItemsProduct{};

		unsigned int menu()const;

	public:

		AidMan(unsigned int num = 7, const char* str = "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");

		AidMan(const AidMan& a) = delete;

		AidMan& operator=(const AidMan& a) = delete;


		void sort();

		virtual ~AidMan();			//destructor

		void run();

		int list(const char* sub_desc = nullptr);

		AidMan& save();
	
		AidMan& deallocate();

		int search(int sku)const;	

		AidMan& addItem();

		void remove();

		bool load(const char* tempFileName);

		void updateQuantity();

		void shipItems();		

		int removeIndex(int index);

		
	};
}
#endif // !SDDS_AIDMAN_H
