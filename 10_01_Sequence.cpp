// 10_01_Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <iomanip> 
//using namespace std;

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	int n;
	std::cin >> n;
	if (n == 0)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	int currNumber, previousNumber;
	int maxCount = 1, currCount = 1;
	std::cin >> previousNumber;
	for(int i = 1; i < n; i++)
	{
		std::cin >> currNumber;
		if (currNumber > previousNumber)
		{
			currCount++;
		}
		else
		{
			if (currCount > maxCount)
			{
				maxCount = currCount;
			}
			currCount = 1;
		}
		previousNumber = currNumber;
	}
	if (currCount > maxCount)
	{
		maxCount = currCount;
	}
	std::cout << maxCount << std::endl;
    return 0;
}

