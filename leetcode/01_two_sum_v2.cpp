/**********************************************************************
 * Description: [leetcode] Two Sum
 * File: 01_two_sum_v2.cpp (STL version)
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * You can return the answer in any order. *
 **********************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

//---------------------------------------------------------------------
// Core logic: Two Sum (STL style)
//---------------------------------------------------------------------
class Solution {
public:
	std::vector<int> two_sum(const std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		map.reserve(nums.size());	//avoid re-hash

		for( int i = 0; i < nums.size(); ++i ) {
			int complememt = target - nums[i];

			auto it = map.find(complememt);
			if( it != map.end() ) {
				return {it->second, i};
			}

			map.emplace(nums[i],i);	//faster than map(nums[i]) = i;
		}

		return {};	
	}
};

//---------------------------------------------------------------------
// Main (test harness)
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
	Solution sol;

	std::vector<int> nums = {2, 7, 11, 15};
	int target = 22;

	std::vector<int> result = sol.two_sum(nums,target);

	if( !result.empty() ) {
		std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
	} else {
		std::cout << "No solution found" << std::endl;
	}

	return 0;
}


