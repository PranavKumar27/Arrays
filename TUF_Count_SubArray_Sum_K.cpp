#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_1D_v(vector<int> Arr,int i,int j)
{
    for(int k=i;k<=j;k++)
        cout << Arr[k] << " ";
    cout << endl;
}

// Brute Approach:
// TC --> O(N*N*N)
// SC --> O(1)
int countSubArray_Sol1(vector<int> Arr,int K)
{
    int n = Arr.size();

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum+=Arr[k];

            }
            if(sum==K)
            {
                print_1D_v(Arr,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}


// Better than Brute Approach:
// TC --> O(N*N)
// SC --> O(1)
int countSubArray_Sol2(vector<int> Arr,int K)
{
    int n = Arr.size();

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
            sum+=Arr[j];
            if(sum==K)
            {
                print_1D_v(Arr,i,j);
                cnt++;
            }
        }

    }
    return cnt;
}


// Optimal Approach 1:
// TC --> O(N) + O(logN) for Map
// SC --> O(1)
int countSubArray_Sol3(vector<int> Arr,int K)
{
    int n = Arr.size();

    map<int,int> Hash; // {sum,cnt}
    int cnt=0;
    int sum = 0;
    int max_len = -1e9,len;
    Hash[0]=1; // sum =0 is always possible
    cout << "Hash -->{" << 0 << " , " << Hash[0] << " }" << endl;
    for(int i=0;i<n;i++)
    {
        sum+=Arr[i];

        //if(sum==K)
        {
            int rem_sum = sum-K;
            if(Hash.find(rem_sum)!=Hash.end())// Found
            {

                int freq = Hash[rem_sum];
                cout << "freq =" << freq << endl;
                cnt=cnt+freq;
                cout << "cnt =" << cnt << endl;
            }
        }

        auto itr = Hash.find(sum);
        if(itr==Hash.end()) // Not Found
        {
            Hash[sum]=1;
        }
        else
        {
            Hash[sum]++;// = itr->second+1;
        }
        cout << "Hash -->{" << sum << " , " << Hash[sum] << " }" << endl;

    }
    return cnt;
}

// Optimal Approach 2:
// TC --> O(N) + O(logN) for Map
// SC --> O(1)
int countSubArray_Sol4(vector<int> Arr,int K)
{
    int n = Arr.size();

    map<int,int> Hash; // {sum,cnt}
    int cnt=0,sum = 0;
    Hash[0]=1; // sum =0 is always possible
    for(int i=0;i<n;i++)
    {
        sum+=Arr[i];

        int rem_sum = sum-K;
        int freq = Hash[rem_sum];
        cnt=cnt+freq;
        Hash[sum]++;// This increase key/Value irrespective of key present or not

    }
    return cnt;
}

/*
int countSubArray_Sol5(vector<int> Arr,int K)
{
    int n = Arr.size();

    map<int,vector<int>> Hash; // {sum,cnt}
    int cnt=0;
    int sum = 0;
    Hash[0]=1; // sum =0 is always possible
    cout << "Hash -->{" << 0 << " , " << Hash[0] << " }" << endl;
    for(int i=0;i<n;i++)
    {
        sum+=Arr[i];

        //if(sum==K)
        {
            int rem_sum = sum-K;
            if(Hash.find(rem_sum)!=Hash.end())// Found
            {

                vector<int> temp = Hash[rem_sum];
                Hash[rem_sum].push_back(i);
                int freq = temp.size();
                cout << "freq =" << freq << endl;
                print_1D_v(temp);
                cnt=cnt+freq;
                cout << "cnt =" << cnt << endl;
            }
        }

        auto itr = Hash.find(sum);
        if(itr==Hash.end()) // Not Found
        {
            Hash[sum]=1;
        }
        else
        {
            Hash[sum]++;// = itr->second+1;
        }
        cout << "Hash -->{" << sum << " , " << Hash[sum] << " }" << endl;

    }
    return cnt;
}

*/
int main()
{
    vector<int> Arr = {1,2,3,-3,3,1,1,1,4,2,-3};
    int K = 3;
    int ans = countSubArray_Sol1(Arr,K);
    cout << "count Sub-Array -->" << ans << endl;


    ans = countSubArray_Sol2(Arr,K);
    cout << "count Sub-Array -->" << ans << endl;

    ans = countSubArray_Sol3(Arr,K);
    cout << "count Sub-Array -->" << ans << endl;

    ans = countSubArray_Sol4(Arr,K);
    cout << "count Sub-Array -->" << ans << endl;
    return 0;
}
