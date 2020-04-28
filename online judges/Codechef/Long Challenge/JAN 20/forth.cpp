#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1;
        cin>>str2;
        
        int a=str1.size(),b=str2.size(),out=0;
        for(int itr=0;itr<b;itr++)
        {
            if(str2[itr]=='1')
            {
                out=1;
                break;
            }
        }
        if(out==0)
        {
            cout<<0<<endl;
            continue;
        }
        
        if(a<b)
        {
            string temp=str2;
            int size;
            str2=str1;
            str1=temp;
            size=b;
            b=a;
            a=size;
        }
        int i=a,j=b,val,m=0,flg=0;
        str1="0"+str1;
        str2="0"+str2;
    
        while(i>=0)
        {
            if((str1[i]==str2[j]))
            {
                if(str1[i]=='0')
                {
                    if(flg==1)
                    {
                        if(val-i>m)
                            m=val-i;
                        flg=0;
                    }
                }
                else
                {
                    if(flg==1)
                    {
                        
                        if(val-i>m)
                        {
                            m=val-i;
                        }
                       
                        //cout<<"if "<<dis<<endl;
                    }
                    else
                    {
                        flg=1;
                       // cout<<"els "<<dis<<endl;
                    }
                     val=i;
                }
                //cout<<"a "<<A[i]<<" b "<<B[j]<<endl;
            }
            i--;

            j--;
            if(j<0)
                j=0;
            
        }
                    cout<<m+1<<endl;
    }
	return 0;
}