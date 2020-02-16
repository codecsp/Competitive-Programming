// use of left shift and right shift operators
//left shift (x<<3)=  multiply x by 2, 3 times
// right shift (x>>1) = divide x by 2, 1 times 



#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main()
{
	ll t =4;
	ll doublet = t<<1;

	ll multiplier =  8;
	ll diviosr = 2; 

	cout<<"4 * "<<multiplier <<" = "<<(t<<3) <<endl;
	cout<<"4 / "<<diviosr <<" = "<<(t>>1) <<endl;

return 0;
}