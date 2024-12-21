#include <iostream>
#include <vector>
#include <map>

using namespace std;

// TC --> O(N*N*N)
// SC --> O(1)
int LongestSubArrayLen_Sol1(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int max_len=-1e9,len=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout << Arr[j] << ",";
            int len = j-i+1;
            int sum=0;
            for(int l=i;l<=j;l++)
            {
                cout << Arr[l] << ",";
                sum+=Arr[l];
            }

            if(sum==k)
            {
                cout << "  ** ";
                max_len = max(max_len,len);
            }
            cout << endl;


        }
        cout << endl;
    }

    return max_len;
}

// TC --> O(N*N)
// SC --> O(1)
int LongestSubArrayLen_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int max_len=-1e9,len=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=Arr[j];
            cout << Arr[j] << ",";
            int len = j-i+1;

            if(sum==k)
            {
                cout << "  ** ";
                max_len = max(max_len,len);
            }
            cout << endl;


        }
        cout << endl;
    }

    return max_len;
}
// Ordered Map without any collision will have TC = O(logn)
// Unordered map without any collision will have Best as TC = O(1)  and worst TC as O(N*N)
// TC --> O(N * 2LogN) for Find in Map, TC = O(LogN)
// SC --> O(N) for Hashing
// This solution works for Positive, Negatives and Zeros in Input set
int LongestSubArrayLen_Sol3(vector<int>& Arr,int k)
{
    int n = Arr.size();
    int max_len=-1e9,len;
    int sum = 0;
    map<int,int> Hash; // {sum,index}
    for(int i=0;i<n;i++)
    {
        sum = sum+Arr[i];
        if(sum == k)
        {
            len = i+1;
            max_len = max(max_len,len);
        }
        else
        {
            // look into the Hash map to find sum-k value
            int rem_sum = sum - k;
            if(Hash.find(rem_sum) != Hash.end())
            {
                int index = Hash[rem_sum];
                len = i-index;
                max_len = max(max_len,len);
            }
        }
        if(Hash.find(sum) == Hash.end()) // If Hash doesn't have sum then only insert else Hash[sum] will get over-ridden with higher i means lesser length
                                        // We need the leftmost i for the longest Length
        {
            Hash[sum] = i;
        }
    }

    return max_len;
}

void print_SubArray(vector<int> Arr,int start,int ends)
{
    cout << "SubArray -->"  << endl;
    for(int idx = start;idx<=ends;idx++)
    {
        cout << Arr[idx] << " ";
    }
    cout << endl;
}

// TC --> O(2N)
// SC --> O(1)

int LongestSubArrayLen_Sol4(vector<int> Arr,int k)
{
    int n = Arr.size();
    bool fl = true;
    int sum = 0,max_len = -1e9,len=0;
    int i=0,j=0;
    while(j<n)
    {
        if(fl) // fl true means Add Arr[j]
            sum += Arr[j];
        else // fl as false means subtract Arr[i]
        {
            while(i<=j && sum>k)
            {
                sum -= Arr[i];
                i++;
            }
        }


        if(sum==k)
        {
            len = j-i+1;
            print_SubArray(Arr,i,j);
            max_len = max(max_len,len);
            j++;
            fl = true;
        }
        else if(sum<k)
        {
            j++;
            fl = true;
        }
        else
        {
            fl = false;
        }

    }
    return max_len;
}

// TC --> O(2N)
// SC --> O(1)

int LongestSubArrayLen_Sol5(vector<int> Arr,int k)
{
    int n = Arr.size();
    int sum = Arr[0],max_len = -1e9,len=0;
    int i=0,j=0;
    while(j<n)
    {
        while(i<=j && sum>k)
        {
            sum -= Arr[i];
            i++;
        }

        if(sum==k)
        {
            len = j-i+1;
            print_SubArray(Arr,i,j);
            max_len = max(max_len,len);
        }
        j++;
        if(j<n)
        {
            sum+=Arr[j];
        }



    }
    return max_len;
}


int main()
{

    vector<int> Arr ={1,2,1,1,0,1,0,1,0,3,4,1};
    int k = 3;
    int len = LongestSubArrayLen_Sol1(Arr,k);
    cout << "Longest SubArray Len Sol1 = " << len << endl;

    len = LongestSubArrayLen_Sol2(Arr,k);
    cout << "Longest SubArray Len Sol2 = " << len << endl;

    len = LongestSubArrayLen_Sol3(Arr,k);
    cout << "Longest SubArray Len Sol3 = " << len << endl;

    vector<int> Arr1 ={1,2,3,1,1,1,1,3,3};
    int k1 = 6;

    int len1 = LongestSubArrayLen_Sol4(Arr1,k1);
    cout << "Longest SubArray Len Sol4 = " << len1 << endl;

    len1 = LongestSubArrayLen_Sol5(Arr1,k1);
    cout << "Longest SubArray Len Sol5 = " << len1 << endl;

    return 0;
}
