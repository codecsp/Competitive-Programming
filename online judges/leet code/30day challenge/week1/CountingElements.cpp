//problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3289/

// status : accepted

// submitted code

#include<bits/stdc++.h>

class Solution
{
public:
	int countElements(vector<int>& arr)
	{
		int ans = 0;
		vector<int> tmp = arr;
		sort(tmp.begin(), tmp.end());
		map<int, int> mp;
		for (int num : tmp)
		{
			mp[num] += 1 ;
		}

		for (int num : tmp)
		{
			int next = num + 1;
			if (binary_search(tmp.begin(), tmp.end(), next))
			{
				if (mp[next] != 0)
				{
					ans++ ;
					//mp[next] = mp[next] - 1;
				}
			}
		}
		return ans;
	}
};
