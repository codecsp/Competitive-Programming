/*
Given a array of integers containing two unique nos occuring only once and the rest ocuureing twice.
Find those two  numbers in constant space.
*/
 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	int n;
	cout<<"enter size : ";
	cin>>n;
	std::vector<int> arr(n,0);
	int totalExor = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		totalExor^=arr[i];
	}

	int tmp  = totalExor;
	int pos = 0;
	while( (tmp&1)!=1 )
	{
		pos++;
		tmp = tmp>>1;
	}

	int mask = 1<<pos;

	int num1=0;
	for (int i = 0; i < n; ++i)
	{
		if( (arr[i]&mask) >0)
			num1 = num1^arr[i];
	}

	int num2 = 0;

	num2 =totalExor^num1;

	cout<<"Two numbers are : "<<num1<<" "<<num2<<endl;


	return 0;
}
