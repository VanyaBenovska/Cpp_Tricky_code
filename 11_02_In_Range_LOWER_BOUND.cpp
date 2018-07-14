// 11_02_In_Range_LOWER_BOUND.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <sstream>
#include <iomanip> 
#include <algorithm>
#include <set>           
#include <iterator> //for std::ostream_iterator

//using namespace std;

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::set <int> dataSet_Numbers;

	std::string line;
	getline(std::cin, line);

	int fromNumber, toNumber;
	std::cin >> fromNumber >> toNumber;

	int number;
	std::istringstream iss(line);

	while (iss >> number)
	{

		dataSet_Numbers.insert(number);

	}
	//if (number >= fromNumber && number < toNumber)

	for (auto it = dataSet_Numbers.lower_bound(fromNumber); it != dataSet_Numbers.lower_bound(toNumber); it++)
	{
		//it e iterator !!!!!!!!!!
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	return 0;
}

