/**********************************************************************
 * [leetcode] Two Sum
 * File: 01_two_sum_v1.cpp (Embedded version)
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * You can return the answer in any order. *
 **********************************************************************/

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cassert>

//---------------------------------------------------------------------
// Configuration
//---------------------------------------------------------------------
constexpr std::size_t MAX_SIZE = 100;

//---------------------------------------------------------------------
// Logging (disable in production)
//---------------------------------------------------------------------
#ifdef DEBUG
	#define LOG(x) std::cout << x << std::endl;
#else
	#define LOG(x)
#endif

//---------------------------------------------------------------------
// Error handling
//---------------------------------------------------------------------
enum class Status {
	OK = 0,
	ERROR_INVALID_PARAM,
	ERROR_OVERFLOW,
	ERROR_NOT_FOUND
};

//---------------------------------------------------------------------
// Utility functions
//---------------------------------------------------------------------
inline bool is_valid_index(std::size_t idx, std::size_t size)
{
	return idx < size;
}

//---------------------------------------------------------------------
// Core logic: Two Sum (embedded stype)
//---------------------------------------------------------------------
Status two_sum( const int* arr,
		std::size_t size,
		int target,
		int& out_i,
		int& out_j )
{
	if( !arr || 0 == size ) {
		return Status::ERROR_INVALID_PARAM;
	}

	for( std::size_t i = 0; i < size; ++i ) {
		for( std::size_t j = i + 1; j < size; ++j ) {
			if( target == arr[i] + arr[j] ) {
				out_i = static_cast<int>(i);
				out_j = static_cast<int>(j);

				return Status::OK;
			}
		}
	}

	return Status::ERROR_NOT_FOUND;
}

//---------------------------------------------------------------------
// Main (test harness)
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
	int data[MAX_SIZE] = {2, 7, 11, 15};
	std:size_t size = 4;
	
	int i = -1, j = -1;

	Status ret = two_sum(data, size, 13, i, j);
	
	if( Status::OK == ret ) {
		LOG("Found: " << i << "," << j);
		std::cout << "Result: [" << i << "," << j << "]" << std::endl;
	} else {
		std::cout << "No solution found" << std::endl;
	}
	
	return 0;
}


