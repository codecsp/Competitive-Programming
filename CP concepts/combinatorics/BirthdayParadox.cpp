// birthday paradox problem

// what is the minimu number of people in the room so that there is 50%
//chance of birthdays coming together

//hint: assume non-leap year

/*solution:

p: find prob of n people having diff birthdays


if 1 people in room :-> proba of diff  = 1 100 %
						proba of same  = 0
if 2 people in room :-> proba of diff  = 99.72 %
						proba of same  = 0.28
if 3 people in room :-> proba of diff  = 99.12 %%
						proba of same  = 0.88 %
.
.
.
go on till proba of same  = 50%


*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n = 2;
	double ans  = 1.0 ;
	double prev = 1.0 ;
	while (ans > 0.50)
	{
		ll tmp = 365 - (n - 1) ;
		ans = prev * (tmp / 365.0);
		prev = ans;
		n++;
	}
	cout << "\nso the minimum no of students are : " << n - 1 << endl;


	return 0 ;
}

