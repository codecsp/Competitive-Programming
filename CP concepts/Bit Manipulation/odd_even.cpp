// Given a integer find whether the integer is odd or even using bitwise operator 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

	ll n;
	cin >> n;
	
	if(n&1)  // last bit only decides whether a number is od or even
		cout<<n<<" is odd number.\n";
	else
		cout<<n<<" is even number.\n";

	return 0;
}