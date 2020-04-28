#include<bits/stdc++.h>
using namespace std;

bool isArraySorted(int arr[],int n)
{
	if(n == 1)
		return true;
	else
		return (arr[n-1]<arr[n-2]) ? false: isArraySorted(arr,n-1);	
}

int main()
{
	int n;
	cout<<"Enter count of elements: ";
	cin>>n;
	int arr[n+1];
	cout<<"\nEnter elements: ";
	for (int i = 1; i <=n; ++i)
	{
		cin>>arr[i];
	}

	if(isArraySorted(arr,n))
	{
		cout<<"array is sorted.\n";
	}
	else
		cout<<"Array is not sorted\n";
	
	return  0;
}