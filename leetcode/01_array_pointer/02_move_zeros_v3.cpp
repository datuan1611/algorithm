/**********************************************************************
 * Description: [leetcode] Move Zeros
 * File: 02_move_zeros_v3.cpp (STL version)
 * 
 * Given an integer array nums, move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements. 
 * Note that you must do this in-place without making a copy of the array.
 * You can return the answer in any order. 
 **********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

//---------------------------------------------------------------------
// Core logic: Move Zeros (STL style)
//---------------------------------------------------------------------
class Solution {
public:
	void move_zeros(std::vector<int>& nums) {

		auto it = std::remove(nums.begin(), nums.end(), 0);  //move non-zeros in front, return it at 1st zero
								     //note: elements in back is garbage, need to erase	
		std::size_t count_zeros = nums.end() - it;
		nums.erase(it, nums.end());               //remove complement
		nums.insert(nums.end(), count_zeros, 0);  //add zeros in back

		return;
	}
};

//---------------------------------------------------------------------
// Main (test harness)
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
	Solution sol;

	std::vector<int> nums = {0, 0, 2, 3, 0, 1, 0};

	sol.move_zeros(nums);
	
	std::cout << "Result: [ ";
	for( auto it : nums ) {
		std::cout  << it << ", ";
	}
	std::cout << "]" << std::endl;

	return 0;
}


