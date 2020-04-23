
//problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/

//executable soluntion

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{

		int ans = 0;
		for (auto number : nums)
			ans ^= number;
		return ans;

	}
};