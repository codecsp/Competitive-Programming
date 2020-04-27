/*

favourite dice spoj : https://www.spoj.com/problems/FAVDICE/

Simple its like a coupan collector problem


BuggyD loves to carry his favorite die around. 
Perhaps you wonder why it's his favorite? 
Well, his die is magical and can be transformed into an N-sided unbiased die with the push of a button. 
Now BuggyD wants to learn more about his die, so he raises a question:

What is the expected number of throws of his die while it has N sides,
so that each number is rolled at least once?SOlution : E[X] = n + (n/2) + (n/3) + (n/4) + (n/5) +...+ (n/n) ;

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		long double ans = 0;
		for (ll i = 1; i <= n; ++i)
		{
			ans+= n/(i*1.0) ;
		}

		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;

}