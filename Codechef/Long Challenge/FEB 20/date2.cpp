        #include<stdio.h>
        #include <bits/stdc++.h>
        using namespace std;

        typedef long long int ll;

        ll dow(ll d, ll m, ll y)  
        {  
            static int t[] = { 0, 3, 2, 5, 0, 3, 
                               5, 1, 4, 6, 2, 4 };  
            y -= m < 3;  
            return ( y + y / 4 - y / 100 +  y / 400 + t[m - 1] + d) % 7;  
        }

        int main()
        {
            
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            
            ll t;
            cin>>t;

            std::map<ll, string> mp_day ;
            std::map<string, ll> mp_day_date ;
            std::map<ll, ll> m_ans;
            

            mp_day_date["Sunday"] = 0;
            mp_day_date["Monday"] = 1;
            mp_day_date["Tuesday"] = 2;
            mp_day_date["Wednesday"] = 3;
            mp_day_date["Thursday"] = 4;
            mp_day_date["Friday"] = 5;
            mp_day_date["Saturday"] = 6;


            mp_day[0] = "Sunday";
            mp_day[1] = "Monday";
            mp_day[2] = "Tuesday";
            mp_day[3] = "Wednesday";
            mp_day[4] = "Thursday";
            mp_day[5] = "Friday";
            mp_day[6] = "Saturday";

            m_ans[0] = 0 ; 
                    
            for ( ll i = 1; i <= 1000000 ; ++i )
            {
                        ll day1 = dow(1,2,i) ; 
            
                        string day = mp_day[day1]; //day at1st date
            
                        ll check_neg = mp_day_date["Friday"]- mp_day_date[day];
                        if(check_neg < 0)
                            check_neg+=7;
                        
                        ll aa = 1+check_neg ;
            
                        ll bb  = aa+10 ;
            
                        //cout<<aa<<" --> "<<bb <<endl;
                        
                        bool Prime = false ;
            
                        if(i % 400 ==0 || (i%4==0 && i%100 != 0))
                            Prime  = true ;
            
                        ll cc ;
                        if(Prime)
                        {
                            ll day2 = dow(29,2,i);
            
                            ll ss = mp_day_date["Sunday"] - mp_day_date[mp_day[day2]] ;
            
                            //ll check = mp_day_date["Friday"]- mp_day_date[day];
                        
                            cc = (29+ss)-7;
            
                        //  cout<<"cookoff --> "<<bb<<endl;
                        }
                        else
                        {
                            ll day2 = dow(28,2,i);
            
                            ll ss = mp_day_date["Sunday"] - mp_day_date[mp_day[day2]] ;
            
                            //ll check = mp_day_date["Friday"]- mp_day_date[day];
                            cc = (28+ss)-7;
            
                        //      cout<<"cookoff non-leap--> "<<bb<<endl;
                        }
            
                        if(cc<bb)
                        {
                            m_ans[i] = m_ans[i-1]+1;
                        }
                        else
                            m_ans[i] = m_ans[i-1] ;   
                            
            }       

                    // for (ll i = 1; i <= 400; ++i)
                    // {
                    //     cout<<"m["<<i<<"] = "<<m_ans[i]<<endl;
                    //     /* code */
                    // }


            while(t--)
            {
                //ll ansss = 0;
                ll m1,y1;
                ll m2,y2;

                cin>>m1>>y1; // 1 1
                cin>>m2>>y2;// 1 401


                if(m1>2)
                    ++y1;
                if(m2<2)
                    --y2;
                    
                if(y1==1000000)
                {
                    ll df = y2% 1000000 ;
                    if(df )
                    cout<<m_ans[y2%1000000]<<"\n";   
                }
                else if(y1 > 1000000 )
                {
                    ll dddddd =(y1-1)%1000000 ;
                    ll cfcf = y2%1000000 ;
                    
                    cout<<m_ans[cfcf]-m_ans[dddddd]<<"\n";
                }
                else if(y1 < 1000000 && y2 >1000000 )
                {
                    ll ooo = ( m_ans[1000000]+m_ans[y2 %1000000] ) - m_ans[y1-1] ;
                    cout<<ooo<<"\n";
                }
                else
                    cout<<m_ans[y2]-m_ans[y1-1]<<"\n";      

            }
            
            return 0;
        }
        //soham
