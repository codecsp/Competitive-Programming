//problem : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3287/

// status : submitted


class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int size = prices.size();
		int ans = 0;
		for (int i = 1; i < size; i++)
		{
			if (i < size && prices[i] > prices[i - 1] )
				ans += (prices[i] - prices[i - 1]);
		}
		return ans;
	}
};