#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>
#include <fstream>
using namespace std;
#pragma warning(disable: 4996)
#pragma warning(disable: 4290)


static const int k_MaxLength = 30;
static const int sr_YEAR = 2020;
static const int sr_LegalAgeToVote = 18;
enum eFaction { Right, Left, Center };
//const char* os_Factions[] = { "Right", "Left", "Center" };
static const int FirstName_Error = 1;
static const int LastName_Error = 2;
static const int ID_Error = 3;
static const int YearOfBirth_Error = 4;