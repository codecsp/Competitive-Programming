#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll   t   ;
	cin >> t ;
	
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		vector<ll> arr ;
		for (ll i = 0; i < n; ++i) //input array
		{
			ll tmp ;
			cin >> tmp;
			arr.push_back(tmp);
		}

		map<ll, ll> m_ind; // storing indices

		for (ll i = 0; i < n; ++i)
		{
			m_ind[i] = arr[i];
		}



		bool flag = true;
		for (ll i = 0; i < n; ++i)
		{
			if(p%arr[i] == 0)
				continue;
			else
				flag = false;
		}

		sort(arr.begin(),arr.end(),greater<ll>());

	//	ll mini = arr[n-1] ;

		std::map<ll, ll> ans_map ;

		ll summp = 0;

		ll tmp_p = p;

		if(flag)
		{
			cout<<"NO\n";
		}
		else
		{
				cout<<"YES ";
				for (ll i = 0; i < n; ++i)
				{
					if(p%arr[i] == 0)
					{
						ans_map[arr[i]] = 0;
					}
					else
					{
						ll ere = p/arr[i] ;

						if( summp + (ere*arr[i]) <= p )
						{
							ans_map[arr[i]] += p/arr[i] ;
							summp += ere*arr[i];
							p-= ere*arr[i];
						}
						else
							break;

					}
				}


				for (ll i = n-1; i >=0; i--)
				{
								if( p%arr[i] != 0 )
								{
									ans_map[arr[i]]+=1;
									summp+=arr[i];
									if(summp>p)
										break;
								}
							
				}


				for ( ll i = 0; i < n; ++i)
				{
					cout<<ans_map[m_ind[i]]<<" ";
				}

		}


		
	}

	return 0;
}
