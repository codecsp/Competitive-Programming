//problem :https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

//status : submitted

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int iter = 0;
		for (int num : nums)
		{
			if (num == 0)
			{
				continue;
			}
			else
			{
				nums[iter] = num;
				iter++;
			}
		}
		for (int i = iter; i < nums.size(); i++)
			nums[i] = 0;

	}
};