#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*

Input: arr[] = [2, 2, 2, 2, 2]
Output: [2]
Explanation: All the elements are 2, So only keep one instance of 2.

Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
Output: [1, 2, 3, 4, 5]

Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation : No change as all elements are distinct.

*/
// TC -> O(2N)
// Sc --> O(N)
int countUniqueElements_Sol1(vector<int> Arr)
{
    set<int> S;
    for(int i=0;i<Arr.size();i++)
    {
	int val = Arr[i];
	S.insert(val);
    }

    int i=0;
    for(auto itr:S)
    {
        Arr[i++] = itr;
    }
    return i;
}
// Most Optimal Sol
// TC -> O(N)
// Sc --> O(1)
int countUniqueElements_Sol2(vector<int> Arr)
{
	int sz = Arr.size();
	if(sz<=1)
	 return sz;

	int idx = 1;
	for(int i=1;i<sz;i++)
	{
	 	if(Arr[i]!=Arr[i-1])
		 {
			 Arr[idx++] = Arr[i];
		 }
	}
	//cout << "idx = " << idx << endl;
	Arr.erase(Arr.begin()+idx,Arr.end());
	for(auto d:Arr)
	    cout << d << ",";
	cout << endl;
	return idx;
}

// TC -> O(N)
// Sc --> O(1)
int countUniqueElements_Sol3(vector<int> Arr)
{
    for(int i=0;i<Arr.size();i++)
	{
		int val = Arr[i];

		if(i+1 < Arr.size() && Arr[i+1]==val)
		{
			auto itr = Arr.begin()+i;
			Arr.erase(itr);
			i--;  // Reduce i so that i is not impacted since in for loop we will increment i
		}
	}
	return Arr.size();
}

// TC -> O(N^2)
// Sc --> O(1)
int countUniqueElements_Sol4(vector<int> Arr)
{
    for(int i=0;i<Arr.size();i++)
	{
		int val = Arr[i];

		if(i+1 <Arr.size() && Arr[i+1]==val)
		{
			for(int j=i+1;j<Arr.size();)
			{
				if(Arr[j]==val)
				{
					// remove
					auto itr = Arr.begin()+j;
					Arr.erase(itr);
				}
				else
				{
					break;
				}
			}
		}
	}
	return Arr.size();
}
int main()
{
    vector<int> ArrList = {1,2,2,3,3,3,4};
    int count_Unique = countUniqueElements_Sol1(ArrList);
    cout << "countUniqueElements_Sol1 =" << count_Unique << endl;


    count_Unique = countUniqueElements_Sol2(ArrList);
    cout << "countUniqueElements_Sol2 =" << count_Unique << endl;

    count_Unique = countUniqueElements_Sol3(ArrList);
    cout << "countUniqueElements_Sol3 =" << count_Unique << endl;

    count_Unique = countUniqueElements_Sol4(ArrList);
    cout << "countUniqueElements_Sol4 =" << count_Unique << endl;
    return 0;
}
