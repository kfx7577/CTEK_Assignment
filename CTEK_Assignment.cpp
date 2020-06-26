// CTEK_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <new>
#include <vector>

int calc_min_cap(std::vector<std::pair<int, int> > input)
{
	const int max = 1000;
	int N;
	int * a;
	int * b;
	int num = 0;
	int min_cap = 0;
	N = input.size();
	a = new int[N + 1];
	b = new int[N + 1];
	// Making sure a and b are dynamic array and can be allocated with memory
	if (a == nullptr || b == nullptr)
		std::cout << "Error: memory could not be allocated" << std::endl;
	else
	{
		// Assuming that initials, a[0] and b[0] are 0 before stop 1
		a[0] = 0;
		b[0] = 0;
		// Extract input vector of pairs into dynamic array a[i] and b[i] starting from i=1
		for (int i = 1; i <= N; i++)
		{
			if (input[i - 1].first >= 0 && input[i - 1].first < max)
			{
				a[i] = input[i - 1].first;
			}
			if (input[i - 1].second >= 0 && input[i - 1].second < max)
			{
				b[i] = input[i - 1].second;
			}
		}
		// Run calculation after extract
		// Bus link starting from 1 to N
		for (int i = 1; i <= N; i++)
		{
			// Any exiting passengers exits before any entering passengers enters
			int exit = a[i];
			int enter = b[i];
			// Number of people who exits should not exceed current number of passengers in bus
			if (exit <= num)
				num -= exit;
			else
				std::cout << "Error: Number of exits exceeded current number of passenger!" << std::endl;
			num += enter;
			// Display current number of people
			std::cout << "Number of passengers on bus at stop " << i << " : " << num << std::endl;
			// Set new minimum capacity if number of passengers exceeded
			if (num > min_cap)
			{
				std::cout << "Number of passengers exceeded minimum capacity!" << std::endl;
				std::cout << "-> Set minimum capacity to: " << num << std::endl;
				min_cap = num;
			}
		}
		// Delete dynamic array after use
		delete[] a;
		delete[] b;
	}
	return min_cap;
}

int main()
{
	// Input: A vector of pairs
	std::vector<std::pair<int, int> > input = { {0,3}, {2,5}, {4,2}, {4,0} };
	// Output: An integer representing the number of minimum capacity
	int output = calc_min_cap(input);
	// Display output as result
	std::cout << "Bus minimum capacity: " << output << std::endl;
	return 0;
}