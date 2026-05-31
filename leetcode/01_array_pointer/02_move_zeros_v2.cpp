/**********************************************************************
 * [leetcode] Move Zeros
 * File: 01_move_zeros_v2.cpp (Embedded version - no swap)
 *
 * Given an integer array nums, move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements. 
 * Note that you must do this in-place without making a copy of the array.
 **********************************************************************/

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cassert>

//---------------------------------------------------------------------
// Configuration
//---------------------------------------------------------------------
constexpr int MAX_SIZE = 100;

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

//---------------------------------------------------------------------
// Core logic: Move Zeros (embedded style)
//---------------------------------------------------------------------
Status move_zeros( int* arr, std::size_t size)
{
	if( !arr || size == 0 ) {
		return Status::ERROR_INVALID_PARAM;
	}

	std::size_t j = 0;	//position of first zero

	//write non-zero
	for( std::size_t i = 0; i < size; ++i ) {
		if( arr[i] != 0) {
			arr[j] = arr[i];
			++j;
		}
	}

	//fill zero
	while( j < size ) {
		arr[j] = 0;
		++j;
	}

	return Status::OK;
}

//---------------------------------------------------------------------
// Main (test harness)
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
	int data[MAX_SIZE] = {0, 0, 2, 3, 0, 1, 0};
	std::size_t size = 7;
	
	int i = -1, j = -1;

	Status ret = move_zeros(data, size);
	
	if( ret == Status::OK ) {
		std::cout << "Result: [" << data[0];
		for( std::size_t i = 1; i < size; ++i ) {
			std::cout << "," << data[i];
		}
		std::cout << "]" << std::endl;
	} else {
		std::cout << "No solution found" << std::endl;
	}
	
	return 0;
}
