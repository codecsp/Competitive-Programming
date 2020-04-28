#include <iostream>
#include <cmath>
using namespace std;

int primeFactors(int n)
{
    int count = 0;
    while(n%2 == 0)
    {
        count++; // 2
        n = n/2;
    }
    
    for(int i=3;i<= sqrt(n); i = i+2)
    {
        while(n%i == 0)
        {
            count++;
            n = n/i;  // i
        }
    }
    
    if(n>2)
    {
        count++; // n
    }
    
    return count;
}

int main() 
{

    int t;
    cin>>t;
    while(t--)
    {
        int x,k;
        cin>>x>>k;
        
        int size = primeFactors(x);
        if(k <= size)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}


// lack of facility shouldn't depress us & presence and luxury and facility shouldn't distract us.