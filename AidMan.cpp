/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Aidman															*
*					  Filename: Aidman.cpp													*
*					  Version 1.0																*
*					  Author: Bhavy Piyushkumar Patel											*
*					  Revision History															*
*					  -----------------------------------------------------------				*
*					  Date      Reason															*
*					  2022/04/06  completed MS4													*
*					  -----------------------------------------------------------				*
*					  I have flag all the coding by myself and only copied the code				*
*					  that my professor provided to complete my workshops and assignments.		*
*					  ----------------------------------------------------------				*
*												- Bhavy Piyushkumar Patel						*
 ************************************************************************************************/

#include <iostream>
#include "Utils.h"
#include "AidMan.h"

using namespace std;

namespace sdds
{
	AidMan& AidMan::save()
	{
		if (m_file != nullptr)
		{
			ofstream file;
			file.open(m_file);
			for (int i = 0; i < m_iItemsProduct; i++)
			{
				m_ptr[i]->save(file) << endl;
				
			}
			
		}
		return *this;

	}

	AidMan& AidMan::deallocate()
	{
		for (int i = 0; i < m_iItemsProduct; i++)
		{
			delete m_ptr[i];
		}
		delete[] m_file;
		m_file = nullptr;
		m_iItemsProduct = 0;
		return *this;
	}

	bool AidMan::load(const char* tempFileName)
	{
		bool isDone = 0;
		bool flag = 0;
		int count = 0;
		save();
		deallocate();
		ut.alocpy(m_file, tempFileName);
		ofstream newFile;
		ifstream file;
		file.open(m_file);

		if (!file.is_open())
		{
			cout << "Failed to open " << m_file << " for reading!";
			cout << "Would you like to create a new data file?";
			cout << "1- Yes!\n0- Exit\n>";

			int tempNum = ut.getint();
			switch (tempNum)
			{
			case 1:
				newFile.open(m_file);
				flag = 1;
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		if (file.is_open() && flag != 1)
		{
			while (!file.eof())
			{
				char peek = file.peek();
				if (peek == '1' || peek == '2' || peek == '3')
				{
					m_ptr[m_iItemsProduct] = new Perishable;

					m_ptr[m_iItemsProduct]->load(file);
					if (m_ptr[m_iItemsProduct]->operator bool())
					{
						m_iItemsProduct++;
						count++;
					}
					else
					{
						delete m_ptr[m_iItemsProduct];
					}
				}
				else if (peek == '4' || peek == '5' || peek == '6' || peek == '7' || peek == '8' || peek == '9')
				{
					m_ptr[m_iItemsProduct] = new Item;
					m_ptr[m_iItemsProduct]->load(file);
					if (m_ptr[m_iItemsProduct]->operator bool())
					{
						m_iItemsProduct++;
						count++;
					}
					else
					{
						delete m_ptr[m_iItemsProduct];
					}
				}
				else if (!isdigit(peek))
				{
					file.setstate(ios::badbit);
				}
			}
		}
		if (m_iItemsProduct > 0)
		{
			isDone = 1;
		}
		return isDone;
	}

	


	AidMan::AidMan(unsigned int num, const char* str) :Menu(num, str)
	{
		m_file = nullptr;
	}

	AidMan::~AidMan()			//destructor
	{
		deallocate();
	}

	void AidMan::run()
	{
		int num = 0;
		char tempChar[30] = { "\0" };
		do
		{
			num = menu();
			if (m_file == nullptr && num != 0)
			{
				switch (num)
				{
				default:
					cout << "\n****New/Open Aid Database****" << endl;
					cout << "Enter file name: ";
					char tempChar[30] = { "\0" };
					cin >> tempChar;
					if (load(tempChar))
					{
						cout << m_iItemsProduct << " records loaded!" << endl << endl;
					}
					break;
				}
			}
			else
			{
				switch (num)			//switch construct
				{
				case 0:
					cout << "Exiting Program!" << endl;
					save();
					break;
				case 1:
					cout << "\n****List Items****" << endl;
					list();
					break;
				case 2:
					cout << "\n****Add Item****" << endl;
					addItem();
					break;
				case 3:
					cout << "\n****Remove Item****" << endl;
					remove();
					break;
				case 4:
					cout << "\n****Update Quantity****" << endl;
					updateQuantity();
					break;
				case 5:
					cout << "\n****Sort****" << endl;
					sort();
					break;
				case 6:
					cout << "\n****Ship Items****" << endl;
					shipItems();
					break;
				case 7:
					cout << "\n****New/Open Aid Database****" << endl;
					cout << "Enter file name: ";

					cin >> tempChar;
					if (load(tempChar))
					{

						cout << m_iItemsProduct << " records loaded!" << endl;
					}
					break;
				default:
					break;
				}
			}
		} while (num != 0);
	}

	//formatting display

	int AidMan::list(const char* sub_desc)
	{
		int count = 0;
		bool isRow = 1;
		if (m_iItemsProduct > 0) {
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			if (sub_desc == nullptr)
			{

				for (int i = 0; i < m_iItemsProduct; i++)
				{
					cout << " ";
					cout.setf(ios::right);
					cout.width(3);
					cout.fill(' ');
					cout << i + 1;
					cout.unsetf(ios::right);
					cout << " | ";
					m_ptr[i]->linear(1);
					m_ptr[i]->display(cout);
					cout << endl;
					count++;
				}
			}
			else
			{
				for (int i = 0; i < m_iItemsProduct; i++)
				{
					if (m_ptr[i]->operator==(sub_desc))
					{
						cout << " ";
						cout.setf(ios::right);
						cout.width(3);
						cout.fill(' ');
						cout << i + 1;
						cout.unsetf(ios::right);
						cout << " | ";
						m_ptr[i]->linear(1);
						m_ptr[i]->display(cout);
						cout << endl;
						count++;
						isRow = 0;
					}
				}
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

			if (isRow) {
				cout << "Enter row number to display details or <ENTER> to continue:\n> ";
				cin.ignore();
				if (cin.peek() != '\n') {
					char temp[4] = "";
					cin >> temp;
					int tempNum = atoi(temp);
					m_ptr[tempNum - 1]->linear(0);
					m_ptr[tempNum - 1]->display(cout);
				}
				cout << endl;
			}
		}
		else
		{
			cout << "The list is emtpy!" << endl;
		}
		return count;
	}


	int AidMan::search(int sku) const
	{
		int retIndex = -1;
		bool flag = 0;
		for (int i = 0; i < m_iItemsProduct && flag != 1; i++)
		{
			if (m_ptr[i]->operator==(sku))
			{
				retIndex = i;
				flag = 1;
			}
		}
		return retIndex;
	}

	AidMan& AidMan::addItem()
	{
		if (m_iItemsProduct > sdds_max_num_items)
		{
			cout << "Database full!" << endl;
		}
		else
		{
			bool flag = 0;
			iProduct* tempPerishable;
			iProduct* tempItem;
			int tempSku = 0;
			cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit\n> ";
			int num = 0;
			cin >> num;
			switch (num)
			{
			case 1:
				tempPerishable = new Perishable;
				cout << "SKU: ";
				cin >> tempSku;
				for (int i = 0; i < m_iItemsProduct && flag != 1; i++)
				{
					if (m_ptr[i]->operator==(tempSku))
					{
						cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n" << endl;
						flag = 1;
						delete tempPerishable;
					}
				}

				if (flag == 0)
				{
					tempPerishable->read(cin);
					cout << endl;
					if (tempPerishable->operator bool())
					{
						m_ptr[m_iItemsProduct] = tempPerishable;
						m_iItemsProduct++;
					}
					else
					{
						tempPerishable->display(cout);
						delete tempPerishable;
					}
				}
				break;
			case 2:
				tempItem = new Item;
				cout << "SKU: ";
				cin >> tempSku;
				for (int i = 0; i < m_iItemsProduct && flag != 1; i++)
				{
					if (m_ptr[i]->operator==(tempSku))
					{
						cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n" << endl;
						flag = 1;
						delete tempItem;
					}
				}
				if (flag == 0)
				{
					tempItem->read(cin);
					cout << endl;
					if (tempItem->operator bool())
					{
						m_ptr[m_iItemsProduct] = tempItem;
						m_iItemsProduct++;
					}
					else
					{
						tempItem->display(cout);
						delete tempItem;
					}
				}
				break;
			case 0:
				cout << "Aborted\n";
				break;
			default:
				break;
			}
		}
		return *this;
	}

	void AidMan::updateQuantity()
	{
		bool done = false;
		char tempDescription[100] = { "\0" };
		cout << "Item description: ";
		cin.ignore(1000, '\n');
		cin.getline(tempDescription, 100, '\n');

		int num = list(tempDescription);
		if (num > 0)
		{
			int tempSku = ut.getint("Enter SKU: ");
			for (int i = 0; i < m_iItemsProduct && done != true; i++)
			{
				if (m_ptr[i]->operator==(tempSku))
				{
					int value = 0;
					cout << "1- Add\n2- Reduce\n0- Exit\n> ";
					cin >> value;
					switch (value)
					{
					case 1:
						if (m_ptr[i]->qty() >= m_ptr[i]->qtyNeeded())
						{
							cout << "Quantity Needed already fulfilled!\n" << endl;
						}
						else
						{
							int addValue = ut.getint(1, m_ptr[i]->qtyNeeded(), "Quantity to add: ");
							m_ptr[i]->operator+=(addValue);
							cout << addValue << " items added!\n" << endl;
						}
						break;
					case 2:
						if (m_ptr[i]->qty() == 0)
						{
							cout << "Quaintity on hand is zero!\n" << endl;
						}
						else
						{
							int reduceValue = ut.getint(1, m_ptr[i]->qtyNeeded(), "Quantity to reduce: ");
							m_ptr[i]->operator-=(reduceValue);
							cout << reduceValue << " items removed!\n" << endl;
						}
						break;
					case 0:
						cout << "Aborted!\n" << endl;
						break;
					default:
						break;
					}
					done = true;
				}
			}

			if (done != true)
			{
				cout << "SKU not found!\n";
			}

		}
		else
		{
			cout << "No matches found!\n";
		}
	}

	void AidMan::sort()
	{

		for (int i = 0; i < m_iItemsProduct - 1; i++)
		{

			for (int j = 0; j < m_iItemsProduct - i - 1; j++)
			{
				int left_Qty = m_ptr[j]->qty();
				int leftQtyNeeded = m_ptr[j]->qtyNeeded();
				int leftValue = leftQtyNeeded - left_Qty;
				int right_Qty = m_ptr[j + 1]->qty();
				int rightQtyNeeded = m_ptr[j + 1]->qtyNeeded();
				int rightValue = rightQtyNeeded - right_Qty;
				if (leftValue < rightValue)
				{
					iProduct* temp;
					temp = m_ptr[j];
					m_ptr[j] = m_ptr[j + 1];
					m_ptr[j + 1] = temp;
				}
			}
		}
		cout << "Sort completed!\n" << endl;

	}

	void AidMan::remove()
	{
		bool flag = 0;
		int index = 0;
		char tempDescription[100] = { "\0" };
		cout << "Item description: ";
		cin.ignore(1000, '\n');
		cin.getline(tempDescription, 100, '\n');
		int num = list(tempDescription);
		if (num > 0)
		{
			int tempSku = ut.getint("Enter SKU: ");
			for (int i = 0; i < m_iItemsProduct && flag != 1; i++)
			{
				if (m_ptr[i]->operator==(tempSku))
				{
					cout << "Following item will be removed: " << endl;
					m_ptr[i]->linear(0);
					m_ptr[i]->display(cout) << endl;
					cout << "Are you sure?\n1- Yes!\n0- Exit\n> ";
					int num = 0;
					cin >> num;
					switch (num)
					{
					case 1:
						index = i;
						delete m_ptr[i];
						for (int j = index; j < m_iItemsProduct; j++)
						{
							m_ptr[j] = m_ptr[j + 1];
						}
						m_iItemsProduct--;
						cout << "Item removed!" << endl << endl;
						flag = 1;
						break;

					case 0:
						cout << "Aborted!" << endl;
						break;
					default:
						break;
					}
				}
			}
		}
	}

	unsigned int AidMan::menu() const
	{
		int year = 0;
		int month = 0;
		int day = 0;
		ut.getSystemDate(&year, &month, &day);
		cout << "Aid Management System" << endl;
		cout << "Date: " << year << "/0" << month << "/" << day << endl;
		cout << "Data file: ";
		if (m_file != nullptr)
		{
			cout << m_file << endl;
		}
		else
		{
			cout << "No file" << endl;
		}
		cout << "---------------------------------" << endl;
		int  num = Menu::run();
		return num;
	}

	void AidMan::shipItems()
	{
		int shippingCount = 0;
		int day = 0;
		int month = 0;
		int year = 0;
		ut.getSystemDate(&year, &month, &day);
		ofstream file;
		file.open("shippingOrder.txt");
		file << "Shipping Order, Date: " << year << "/0" << month << "/" << day << endl;
		file << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		file << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < m_iItemsProduct; i++)
		{
			if (m_ptr[i]->qty() == m_ptr[i]->qtyNeeded())
			{
				m_ptr[i]->linear(true);
				shippingCount++;
				file << " ";
				file.setf(ios::right);
				file.width(3);
				file << shippingCount;
				file.unsetf(ios::right);
				file << " | ";
				m_ptr[i]->display(file) << endl;
				removeIndex(i);
			}
		}
		file << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		cout << "Shipping Order for " << shippingCount << " times saved!\n" << endl;
	}
	int AidMan::removeIndex(int index)
	{
		int delete_Index = index;
		delete m_ptr[index];
		for (int j = delete_Index; j < m_iItemsProduct; j++)
		{
			m_ptr[j] = m_ptr[j + 1];
		}
		m_iItemsProduct--;
		return 0;
	}

}