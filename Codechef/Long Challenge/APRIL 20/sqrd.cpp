
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define MAX 1000002 
#define pb push_back 

//typedef long long int ll;

vector<ll> primes; 

unordered_map<ll, ll> k_cnt, current_map; 

void sieve() 
{ 

	ll prime[MAX]; 
	prime[0] = prime[1] = 1; 
	for (ll i = 2; i < MAX; i++) 
	{
		if (prime[i] == 0) 
		{ 
			for (ll j = i * 2; j < MAX; j += i) 
			{ 
				if (prime[j] == 0) 
				{ 
					prime[j] = i; 
				} 
			} 
		} 
	} 

	for (ll i = 2; i < MAX; i++) 
	{ 
		if (prime[i] == 0) 
		{ 
			prime[i] = i; 
			primes.pb(i); 
		} 
	} 
} 
 
ll countSubarrays(ll* arr, ll n, ll k) 
{ 

	if (k == 1) 
	{ 
		cout << (1LL * n * (n + 1)) / 2; 
		return 0; 
	} 

	vector<ll> k_primes; 

	for (auto p : primes) { 
		while (k % p == 0) { 
			k_primes.pb(p); 
			k /= p; 
		} 
	} 

	if (k > 1) { 
		k_primes.pb(k); 
	} 

	for (auto num : k_primes) { 
		k_cnt[num]++; 
	} 

	ll l = 0, r = 0; 

	ll ans = 0; 

	while (r < n) 
	{ 

		for (auto& it : k_cnt) 
		{ 

			ll p = it.first; 

			while (arr[r] % p == 0) { 
				current_map[p]++; 
				cnts[r][p]++; 
				arr[r] /= p; 
			} 
		} 

		ll flag = 0; 
		for (auto& it : k_cnt) { 
			ll p = it.first; 
			if (current_map[p] < k_cnt[p]) { 
				flag = 1; 
				break; 
			} 
		} 


		if (!flag) 
		{ 

			ans += n - r; 

			for (auto& it : k_cnt) 
			{ 
				ll p = it.first; 
				current_map[p] -= cnts[l][p]; 
			} 

			l++; 
		} 
		else 
		{ 
			r++; 
		} 
	} 

	return ans; 
} 

int main() 
{ 
	ll arr[] = { 6, 2, 8 }; 
	ll n = sizeof(arr) / sizeof(arr[0]); 
	ll k = 4; 
	k_cnt.clear();
	current_map.clear();
	unordered_map<ll, ll>cnts[MAX];

	sieve(); 

	cout << countSubarrays(arr, n, k,cnts); 

	return 0; 
} 
