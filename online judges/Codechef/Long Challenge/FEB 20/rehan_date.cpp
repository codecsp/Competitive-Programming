#include<bits/stdc++.h>
typedef long long ll;
long long int M=1000000007;
using namespace std;


int dayofweek(ll d, ll m, ll y) 
{ 
	static ll t[] = { 0, 3, 2, 5, 0, 3, 
					5, 1, 4, 6, 2, 4 }; 
	y -= m < 3; 
	return ( y + y / 4 - y / 100 + 
			y / 400 + t[m - 1] + d) % 7; 
} 


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll c=0;
        ll year;
        ll m1,m2,y1,y2;
        cin>>m1>>y1>>m2>>y2;
        y1=y1%M;
        y2=y2%M;
        
        if(m1>2)
        y1++;
        
        if(m2<2)
        y2--;
        
        year=y1;
        while(year<=y2)
        {
            bool leap=false;
            if(year%400==0 || (year%4==0 && year%100))
            {
                leap=true;
            }
            
            int day = dayofweek(01, 02, year); 
            if((day==0 && leap==false) || day==6)
            {
                cout<<year<<endl;
                c++;
                if(leap && day==6)
                year=year+5;
                
                if(!leap && day==0)
                year=year+5;
                
                if(!leap && day==6)
                year++;
            }
            else
            year++;
        }
        cout<<c<<endl;
    }
    return 0;
}