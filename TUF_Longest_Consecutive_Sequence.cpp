#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int find_maxLen_Consecutive_Seq_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    int max_len = -1e9;
    for(int i=0;i<n;i++)
    {
        int len=1;
        int val = Arr[i];
        int next_val = val+1;
        auto itr = find(Arr.begin(),Arr.end(),next_val);
        while(itr!=Arr.end())
        {
            len++;
            next_val = next_val+1;
            max_len = max(max_len,len);
            itr = find(Arr.begin(),Arr.end(),next_val);
        }
    }
    return max_len;
}


// Better than Brute
// TC --> O(NLogN) for Sort + O(N) for traversal
// SC --> O(1)
int find_maxLen_Consecutive_Seq_Sol2(vector<int> Arr)
{
    sort(Arr.begin(),Arr.end());
    int last_smaller = Arr[0];
    int len = 1;
    int max_len = 1;
    int n = Arr.size();
    for(int i=1;i<n;i++)
    {
        if(Arr[i]-last_smaller == 1)
        {
            last_smaller = Arr[i];
            len++;
        }
        else if(Arr[i]-last_smaller > 1)
        {
            len = 1;
            last_smaller = Arr[i];
        }
        else
        {
            // if Arr[i] and last_smaller are same
        }
        max_len = max(max_len,len);
    }
    return max_len;
}

// Optimal Solution
// TC --> O(N) + O(N) + [ O(1) for find if no collision *2 + O(N) ] so overall is O(3N)
// Note the inner while loop at max will only run for times for any sequence where previous is not found so
// Overall loop for_+ while will run O(2N) only, For outer for O(n) and Overall is O(3N)
// SC --> O(N) for Set
int find_maxLen_Consecutive_Seq_Sol3(vector<int> Arr)
{
    unordered_set<int> Sets;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        Sets.insert(Arr[i]);
    }

    int max_len=-1e9,len;
    for(auto itr=Sets.begin();itr!=Sets.end();itr++)
    {
        int val = *itr;
        int prev = val-1;
        auto it = Sets.find(prev);
        if(it==Sets.end()) // Not-Found
        {
            int start = val;
            len = 1;
            int next_val = start+1;
            while(Sets.find(next_val)!=Sets.end()) // Found
            {
                len++;
                next_val++;
            }
            max_len = max(max_len,len);
        }
    }
    return max_len;
}

int main()
{
    vector<int> Arr ={105,3,103,2,3,4,3,2,101,4,4,1,102};

    int ans = find_maxLen_Consecutive_Seq_Sol1(Arr);
    cout << "find maxLen Of Consecutive Seq Using Sol1 =" << ans << endl;

    ans = find_maxLen_Consecutive_Seq_Sol2(Arr);
    cout << "find maxLen Of Consecutive Seq Using Sol2 =" << ans << endl;


    ans = find_maxLen_Consecutive_Seq_Sol3(Arr);
    cout << "find maxLen Of Consecutive Seq Using Sol3 =" << ans << endl;
    return 0;
}
