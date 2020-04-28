#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    map<ll,list<ll> > adjList;
    adjList[2].push_back(1);

    for(ll i=2;i<=1000000;i+=2)
    {
        ll a = i+(i-1);
        ll b = i+(i+1);
        
        adjList[i].push_back(i);
        
        if(a<=1000000)
            adjList[i].push_back(a);
        if(b<=1000000)
            adjList[i].push_back(b);
    }

    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<"1\n";
            cout<<"1 1\n";
        }
        else
        {
            ll trrr;
            trrr = n/2;
            cout<<trrr<<endl;
    
            for(ll i=2;i<=n;i+=2)
            {
                ll cnt = 1 ;
                ll a = i+(i-1);
                ll b = i+(i+1);
                
                if(a<=n)
                {
                    cnt = 2;
                }
                if(b<=n)
                {
                    cnt = 3 ;
                }

//                if(i==2)
  //                  cout<<"1";
  
                if(i == 2)
                {
                    if(cnt == 1)
                    {
                        cout<<cnt+1<<" ";
                        cout<<"1 "<<i<<" ";
                        cout<<"\n";
                    }
                    else if(cnt == 2)
                    {
                        cout<<cnt+1<<" ";
                        cout<<"1 "<<i<<" "<<a<<" ";   cout<<"\n";
                    }
                    else if(cnt == 3)
                    {
                        cout<<cnt+1<<" ";
                        cout<<"1 "<<i<<" "<<a<<" "<<b; cout<<"\n";  
                    }
                       
                    
                }
                else
                {   
                     if(cnt == 1)
                    {
                        cout<<cnt<<" ";
                        cout<<i<<" ";
                        cout<<"\n";
                    }
                    else if(cnt == 2)
                    {
                        cout<<cnt<<" ";
                        cout<<i<<" "<<a<<" ";   cout<<"\n";
                    }
                    else if(cnt == 3)
                    {
                        cout<<cnt<<" ";
                        cout<<i<<" "<<a<<" "<<b; cout<<"\n";  
                    }
                }
        
            }


        }

    }

}
