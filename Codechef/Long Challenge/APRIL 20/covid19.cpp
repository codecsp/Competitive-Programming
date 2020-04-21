#include <iostream>
using namespace std;
typedef long long int ll;

int main() 
{
	// your code goes here
    ll t;
    cin>>t;
    while(t--)
    {
            ll n;
            cin>>n;
            ll arr[n];
            
            for(ll i = 0 ; i<n ; i++)
                cin>>arr[i];
                
            ll last_1 = -9 ;
            bool flag = true;
            
            for(ll i=0;i<n;i++)
            {
                if(arr[i]==1)
                {
                    if(last_1==-9)
                    {
                        last_1 = i;
                        continue;
                    }
                    else
                    {
                        if(i- last_1 >=5)
                        {
                            last_1 = i;
                            continue;
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    

                    }
                                            }
                    
                    
                    {
                        last_1 = i;
                    }
                }
            }
            
            if(flag)
                cout<<"YES\n";
            else
                cout<<"NO\n";
    }
	return 0;
}
