/*
 N queen problems
  Backtracking + Bitmmasking  (Most efiicient approach)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int ans = 0;
int done;

void solve(int rowmask, int ld, int rd)
{
	if(rowmask == done)
	{
		ans++;
		return;
	}

	int avail = done & (~(rowmask|ld|rd)) ;

	while(avail > 0)
	{
		int pp = avail & (-avail);
		avail = avail - pp;

		solve(rowmask|pp, (ld|pp)<<1, (rd|pp)>>1);

	}	 
	 

}

int main()
{
	int n;
	cin>>n;
	done = (1<<n)-1;

	solve(0,0,0);  //one for rpw asking , one for left diiagonal(ld),
	//rd = for right diagonal
	cout<<"total possible ways : "<<ans<<endl;

	return 0;
}
