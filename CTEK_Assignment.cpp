// CTEX Mini Coding Assignment 
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

int calc_min_cap(std::vector<std::pair<int, int> > input)
{
	const int max = 1000;
	int min_cap = 0;
	int num = 0;
	int N = input.size();
	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++)
	{
		if (input[i].first > 0 && input[i].first <= num && input[i].first < max)
		{
			a = input[i].first;
		}
		if (input[i].second > 0 && input[i].second < max)
		{
			b = input[i].second;
		}
		num -= a;
		num += b;
		std::cout << "Total number on the bus: " << num << std::endl;
		if (num > min_cap)
			min_cap = num;
	}
	return min_cap;
}

int main()
{
	// Input: A vector of pairs
	std::vector<std::pair<int, int> > bus = { {0,3}, {2,5}, {4,2}, {4,0} };
	// Output: An integer representing the number of minimum capacity
	int output = calc_min_cap(bus);
	std::cout << "Bus minimum capacity: " << output << std::endl;
	return 0;
}