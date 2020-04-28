#include<bits/stdc++.h>
using namespace std;

//ll N ;// = 100000;


typedef long long ll;

void primeSieve(ll *p)
{

	//base cases
	p[0] = p[1]= 0;
	p[2] = 1;
	// mark all odd prime 
	for (ll i = 3; i<100000; i+=2)
	{
		p[i] = 1;
	}

	for (ll i = 3; i < 100000; i+=2)
	{
		if(p[i]==1)
		{
			for (ll j = i*i; j < 100000; j+=i)
			{
				p[j] = 0 ;
			}
		}
	}

	//p[2] = 1;
	//p[1] = p[0] = 0 ;
	return;
}


int main()
{
	//N = 100000;
	ll arr[100000] = {0};

	primeSieve(arr);

	//cout<<"check : "<<arr[3];

	ll num;
	cout<<"enter a number:";
	cin>>num;
	cout<<"Prime numbers are : ";
	for (ll i = 0; i < num; ++i)
	{
		if(arr[i] == 1 )
			cout<<i<<" ";
		
	}

	return 0;
}


