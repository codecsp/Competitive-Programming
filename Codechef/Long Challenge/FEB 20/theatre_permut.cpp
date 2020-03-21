// C++ implementation of the approach 
#include <iostream> 
using namespace std; 

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
		for (int i = 0; i < this->Length; ++i) 
		{ 

			
			//cout << (this->Arr[this->Indexes[i]]) << " "; 
		} 
		cout << endl; 
	} 

	void Swap(int p, int q) 
	{ 
		int tmp = this->Indexes[p]; 
		this->Indexes[p] = this->Indexes[q]; 
		this->Indexes[q] = tmp; 
	} 
}; 

// Driver code 
int main() 
{ 
	int arr[] ={12,3,6,9}; 
	AllPermutation<int> perm(arr, sizeof(arr) / sizeof(int)); 
	perm.GetFirst(); 
	while (perm.HasNext()) 
    { 
		perm.GetNext(); 
	} 

	return 0; 
} 
