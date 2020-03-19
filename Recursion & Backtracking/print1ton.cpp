#include<bits/stdc++.h>
using namespace std;

int printRecursive(int n)
{
	if (n==0)
		return 0;
	else
	{
		cout<<n<<" ";
		return printRecursive(n-1);
	}

}

int main()
{
	int n;
	cin>>n;
	cout<<"\n";
	return printRecursive(n);

}
