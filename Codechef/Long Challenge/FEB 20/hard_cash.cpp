#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main() 
{
	// your code goes here

    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        std::vector<ll> arr;
    
        for(ll i=0;i<n;i++)
        {
            ll tmp;
            cin >> tmp ;
            arr.push_back(tmp);

        }

        ll take = 0;
        ll give = 0;

        ll tarry[n];

        if(arr[n-1]%k != 0)
                tarry[n-1]=k-(arr[n-1]%k);
        else
                tarry[n-1] = 0;    
        
        
        for (ll i = n-2; i >=0 ; i--)
        {
            if(arr[i]%k != 0)
                tarry[i]=tarry[i+1]+(k-(arr[i]%k));
            else
                tarry[i] = tarry[i+1];
        }

        ll ans = INT_MAX;
        for (ll i = 0; i < n; ++i)
        {
                    //cout<<"helo\n";

               
            if(arr[i]%k != 0)
                take += arr[i]%k;

            if(i < n-1)
                give = tarry[i+1];
            else
                give = 0;

            if(give>take)
                continue;
            else
                ans = min(ans,take-give);
        }
        //cout<<"helo\n";
        cout<<ans<<endl;
            
      
    }

	return 0;
        
}
