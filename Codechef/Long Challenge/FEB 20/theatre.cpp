#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<char, map<ll, ll> > mp;
ll arara = 0;
ll ante = INT_MIN;

//ll opcnt = 0;
template <typename T> 
class AllPermutation 
{ 
private: 
	const T* Arr; 

	const int Length; 

	int* Indexes; 

	int Increase; 

public: 
	AllPermutation(T* arr, int length) 
		: Arr(arr), Length(length) 
	{ 
		this->Indexes = nullptr; 
		this->Increase = -1; 
	} 

	~AllPermutation() 
	{ 
		if (this->Indexes != nullptr) { 
			delete[] this->Indexes; 
		} 
	} 

	void GetFirst() 
	{ 

		this->Indexes = new int[this->Length]; 
		for (int i = 0; i < this->Length; ++i) { 
			this->Indexes[i] = i; 
		} 
 
		this->Increase = 0; 
		this->Output(); 
	} 
	bool HasNext() 
	{ 
		return this->Increase != (this->Length - 1); 
	} 

	void GetNext() 
	{ 
		if (this->Increase == 0) { 

			this->Swap(this->Increase, this->Increase + 1); 

			// Update Increase 
			this->Increase += 1; 
			while (this->Increase < this->Length - 1 
				&& this->Indexes[this->Increase] 
						> this->Indexes[this->Increase + 1]) { 
				++this->Increase; 
			} 
		} 
		else { 

			if (this->Indexes[this->Increase + 1] > this->Indexes[0]) { 
				this->Swap(this->Increase + 1, 0); 
			} 
			else 
			{ 
				int start = 0; 
				int end = this->Increase; 
				int mid = (start + end) / 2; 
				int tVal = this->Indexes[this->Increase + 1]; 
				while (!(this->Indexes[mid] < tVal 
						&& this->Indexes[mid - 1] > tVal)) 
				{ 
					if (this->Indexes[mid] < tVal) 
					{ 
						end = mid - 1; 
					} 
					else
					{ 
						start = mid + 1; 
					} 
					
					mid = (start + end) / 2; 
				} 
 
				this->Swap(this->Increase + 1, mid); 
			}

			// Invert 0 to Increase 
			for (int i = 0; i <= this->Increase / 2; ++i) 
			{ 
				this->Swap(i, this->Increase - i); 
			} 

			// Reset Increase 
			this->Increase = 0; 
		} 
		this->Output(); 
	} 

private: 
	 
	void Output() 
	{ 

		//opcnt++;
		//ll numm  = 3 ;
		ll maxi = 0 ;
		vector<ll> sp;
		ll amount  = 100;
		char cc ='A';
		vector<ll> qe;
		for (int i = 0; i < this->Length; ++i) 
		{ 
			ll ddd = this->Arr[this->Indexes[i]] ;
			//sp.push_back() ; 
			//cout<<(char)(i+65)<<"-->"<<(this->Arr[this->Indexes[i]])<<"   --  "<<mp[cc][this->Arr[this->Indexes[i]]]<<" ; ";
			qe.push_back(mp[cc][ddd])  ;
			cc++;
			
		}
		sort(qe.begin(),qe.end(),greater<ll>());
		cc ='A';
		for (int i = 0; i < qe.size() ; ++i) 
		{ 
			if(qe[i]==0)
				maxi -= 100;
			else
			{
				maxi +=  (qe[i] * amount );
				amount-=25;
			}	
		}

			

			

		
		//cout<<endl;
		//sort(sp.begin(),sp.end(),greater<ll>());
		// for(ll varrr : sp)
		// {
		// }
		//cout<<" local  maxi = "<<maxi<<endl;
		ante = max(ante,maxi);
		//cout<<ante<<endl;

		//cout << endl; 
	} 

	void Swap(int p, int q) 
	{ 
		int tmp = this->Indexes[p]; 
		this->Indexes[p] = this->Indexes[q]; 
		this->Indexes[q] = tmp; 
	} 
}; 

int main()
{
	ll t   ;
	cin>>t ;
	ll ii = 0;
	while(t--)
	{
		
		ante = INT_MIN;
		ll n;
		cin>>n;
		

		for (ll i = 0; i < n; ++i)
		{	
			char a;
			ll b;
			cin>>a>>b;
			mp[a][b]+=1 ;
		}

		//cout<<"ii = "<<ii<<" : "<<ante<<"\n";
		ll arr[] ={12,3,6,9}; 
		AllPermutation<ll> perm(arr, sizeof(arr) / sizeof(ll)); 
		perm.GetFirst(); 
		while (perm.HasNext())
	    {
			perm.GetNext(); 
		}

		
		mp.clear();

		cout<<ante<<endl;
		arara += ante ;



		//ii++ ;

	}

	//cout<<"arara = "<<arara<<"\n";

	cout<<arara<<endl;



}
