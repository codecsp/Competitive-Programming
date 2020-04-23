//problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/
// status : aaccepted


#include<bits/stdc++.h>

//submitted solution:

class Solution
{
public:

	vector<vector<string>> groupAnagrams(vector<string>& arr)
	{

		map<string, vector<string>> mp;
		//vector<string> arr;

		for (string s : arr)
		{
			//cout << s << "\n";
			string tmp = s;
			sort(tmp.begin(), tmp.end());

			mp[tmp].push_back(s);

		}

		vector<vector<string>> anss;

		for (auto s : mp)
		{
			string sss = s.first;
			vector<string> cnt = s.second;
			//cout << sss << endl;
			std::vector<string> tmpp;

			for (string rr : cnt)
			{
				tmpp.push_back(rr);
			}
			anss.push_back(tmpp);
			//cout << endl;
			//cout << sss << " -->" << cnt << endl;
		}

		return anss;

	}
};