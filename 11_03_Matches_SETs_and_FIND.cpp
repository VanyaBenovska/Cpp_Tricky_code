// 11_03_Matches_SETs_and_FIND.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <sstream>
#include <iomanip> 
#include <set>       
#include <algorithm>
#include <iterator> //for std::ostream_iterator


//using namespace std;

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::set <int> dataSet_numbers_sameInBothContainers;
	std::set<int> data_1_numbers;
	std::set<int> data_2_numbers;

	std::string line;
	getline(std::cin, line);

	int number;
	std::istringstream iss1(line);
	while (iss1 >> number)
	{
		data_1_numbers.insert(number);
	}
	getline(std::cin, line);
	std::istringstream iss2(line);
	while (iss2 >> number)
	{
		data_2_numbers.insert(number);
	}
	bool IsPrinted = false;
	for (auto number : data_1_numbers)
	{
		if (data_2_numbers.find(number) != data_2_numbers.end())
		{
			std::cout << number << " ";
			IsPrinted = true;
		}
	}
	if (!IsPrinted)
	{
		std::cout << "no matches" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
