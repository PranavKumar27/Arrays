#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// TC --> O(N*N)
// SC --> O(1)
bool IsTwoSumPossible_Sol1_Variant1(vector<int> Arr,int K)
{
    int n = Arr.size();
    bool IsPossible = false;
    for(int i=0;i<n;i++)
    {
        int rem_sum = K-Arr[i];
        // Now find if rem_sum is present in Arr on index other than i
        for(int j=0;j<n;j++)
        {
            if(Arr[j]==rem_sum && j!=i)
            {
                cout << "Found Remaining Sum =" << rem_sum << endl;
                IsPossible = true;
                break;
            }
        }
        if(IsPossible)
            break;
    }
    return IsPossible;
}

// TC --> O(N*N) sligtly less
// SC --> O(1)

bool IsTwoSumPossible_Sol1_Variant2(vector<int> Arr,int K)
{
    int n = Arr.size();
    bool IsPossible = false;
    for(int i=0;i<n;i++)
    {
        int rem_sum = K-Arr[i];
        // Now find if rem_sum is present in Arr on index other than i
        for(int j=i+1;j<n;j++) // element are checked already from 0---i in previous iterations
            // so j can start from i+1
        {
            if(Arr[j]==rem_sum)
            {
                cout << "Found Remaining Sum =" << rem_sum << endl;
                IsPossible = true;
                break;
            }
        }
        if(IsPossible)
            break;
    }
    return IsPossible;
}
// TC --> O(N*logN)
// SC --> O(N)

bool IsTwoSumPossible_Sol2(vector<int> Arr,int K)
{
    int n = Arr.size();
    bool IsPossible = false;
    map<int,int> Hash;
    for(int i=0;i<n;i++)
    {
        int rem_sum = K-Arr[i];
        cout << "rem_sum =" << rem_sum << endl;
        // Now find if rem_sum is present in Arr on index other than i
        auto itr = Hash.find(rem_sum);
        if(itr==Hash.end()) // Not Found
        {
            Hash[Arr[i]]=i;
        }
        else
        {
            cout << "Pair of indexes = {" << i << "," << itr->second  << " }"<< endl;
            IsPossible = true;
                break;
        }


    }
    return IsPossible;
}

// TC --> O(nLogn) + O(n)
// SC --> O(1)
bool IsTwoSumPossible_Sol3(vector<int>& Arr,int K)
{
    sort(Arr.begin(),Arr.end());

    int n = Arr.size();
    int i = 0,j=n-1;
    while(i<j)
    {
        int sum = Arr[i]+Arr[j];
        if(sum == K)
        {
            return true;
        }
        else if(sum>K)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    vector<int> Arr ={3,6,5,8,11};
    int K = 14;
    bool ans = IsTwoSumPossible_Sol1_Variant1(Arr,K);
    cout << "IsTwoSumPossible Sol1 Varaint1 --> " << ans << endl;

    ans = IsTwoSumPossible_Sol1_Variant2(Arr,K);
    cout << "IsTwoSumPossible Sol1  Variant2 --> " << ans << endl;

    vector<int> Arr1 ={2,6,5,8,11};
    ans = IsTwoSumPossible_Sol2(Arr1,K);
    cout << "IsTwoSumPossible Sol2 --> " << ans << endl;

    ans = IsTwoSumPossible_Sol3(Arr1,K);
    cout << "IsTwoSumPossible Sol3 --> " << ans << endl;

    return 0;
}
