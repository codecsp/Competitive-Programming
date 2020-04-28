/*
	given a string s; 
	print all the subsets of s.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void subfun(int i,string s)
{
	int iter = 0;
	while(i>0)
	{
		int lastbt = i & 1;

		if(lastbt == 1)
			cout<<s[iter];

		i = i>>1;
		iter++;
	}

	cout<<endl;

}

void printsubsets(string s)
{
	int len =  s.length();
	for (int i = 0; i < (1<<len); ++i)
	{
		subfun(i,s);
	}
}


int main()
{

	string s;
	cin>>s;

	printsubsets(s);

	return 0;
}
