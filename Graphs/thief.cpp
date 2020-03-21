#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

double findMod(double a, double b) 
{ 
    double mod; 
    if (a < 0) 
        mod = -a; 
    else
        mod =  a; 
    if (b < 0) 
        b = -b; 
  

    while (mod >= b) 
        mod = mod - b; 
  
    
    if (a < 0) 
        return -mod; 
  
    return mod; 
} 

// int main()
// {

// 	double p,t;
// 	cin>>p>>t;

// 	double res = 0;
// 	ll cnt = 0;

// 	while(1)
// 	{

// 		if(t-p == 1)
// 		{
// 			cnt++;
// 			break;

// 		}
// 		else
// 		{
// 			p = findMod( (p+t/2.0), t);
// 			cout<<"p = "<<p<<endl;
// 			cnt++;
// 			res += p;
// 			if(res == t)
// 				break;
// 			else
// 				p = res;

// 		}

// 	}
// 	cout<<cnt<<endl;

// 	return 0;
// }


ll func(ll p,ll t)
{
	if(p == t)
		return 1 ;
	if(p>t)
		return 0;
	else
		return func((p+1)%t,t) + func((p+t/2)%t,t) ;
}

int main()
{

	ll p,t;
	cin>>p>>t;

	ll ans = func(p,t);

	cout<<ans<<endl;

	return 0;
}

