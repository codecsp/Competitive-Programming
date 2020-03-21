#include <bits/stdc++.h>
using namespace std;

int main() 
{

    long int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            if(tmp == 2)
                cnt++;
        }
        
        int ans=0;
        if(cnt>0)
            cnt--;
            
        ans = ((cnt)*(cnt+1)) / 2;
        
        cout<<ans<<endl;
    }


	return 0;
}