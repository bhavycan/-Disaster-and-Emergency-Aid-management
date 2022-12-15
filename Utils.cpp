/*
*************************************************************************************************
*					  Name: Patel Bhavy Piyushkumar												*
*					  Id: 121048219																*
*					  Email: bppatel16@myseneca.ca												*
*					  course: OOP244 NDD														*
*																								*
*					  Citation and Sources...													*
*					  Final Project Milestone 4													*
*					  Module: Utils					    										*
*					  Filename: Utils.cpp	       												*
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
#include <ctime>
#include "Utils.h"

using namespace std;

namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        if (source != nullptr)
        {
            delete[] destination;
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    int Utils::getint(const char* prompt)
    {
        int num;
        if (prompt) cout << prompt;
        bool flag = 0;
        do
        {
            cin >> num;

            if (!cin.fail())
            {
                flag = 1;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
                num = 0;
            }
        } while (flag != 1);

        return num;
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        if (prompt) cout << prompt;
        bool flag = 0;
        int num = 0;
        do
        {
            num = getint();
            if (num < min || num > max)
            {
                if (errMes)
                {
                    cout << errMes;
                }
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }
            else
            {
                flag = 1;
            }
        } while (flag != 1);

        return num;
    }
    double Utils::getdouble(const char* prompt)
    {
        double num;
        if (prompt) cout << prompt;
        bool flag = 0;
        do
        {
            cin >> num;

            if (!cin.fail())
            {
                flag = 1;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid number, retry: ";
                num = 0;
            }
        } while (flag != 1);

        return num;
    }
    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {
        if (prompt) cout << prompt;
        bool flag = 0;
        double num = 0;
        do
        {
            num = getdouble();
            if (num < min || num > max)
            {
                if (errMes)
                {
                    cout << errMes;
                }
                else
                {
                    cout << "Value out of range [" << min << ".00" << "<=val<=" << max << ".00" << "]: ";
                }
            }
            else
            {
                flag = 1;
            }
        } while (flag != 1);

        return num;
    }
}