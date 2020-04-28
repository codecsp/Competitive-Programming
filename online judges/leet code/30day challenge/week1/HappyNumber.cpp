
//problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/

// status : submitted


#include<map>
class Solution {
public:

	int sum(int n)
	{
		int ans = 0;
		while (n > 0)
		{
			int lastdigit = n % 10;
			ans += (lastdigit * lastdigit);
			n = n / 10;
		}

		return ans;
	}


	bool isHappy(int n)
	{
		bool ans = true;
		map<int, bool>dp ;

		dp[n] = true;
		// cout<<"value of n : "<<n<<endl;

		while (1)
		{
			int s1 = sum(n);
			if (s1 == 1)
			{
				//cout<<"value of n : "<<n<<endl;
				return true;
			}
			else
			{
				n = sum(n);
				//cout<<"value of n : "<<n<<endl;
				if (dp[n] == true)
					return false;
				else
				{
					dp[n] = true;
				}
			}
		}


	}
};