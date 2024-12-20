#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// TC --> O(N) + O(NLogN) for Sorting
// SC --> O(1)
int AppearsOnce_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    // Arr is sorted if not
    sort(Arr.begin(),Arr.end());

    int missing_val=-1;
    int i=0,j=1;
    for(;i<n && j<n;i=i+2,j=j+2)
    {
        if(Arr[i]==Arr[j])
        {
            cout << "Arr[i] =" << Arr[i] << endl;
            cout << "Arr[j] =" << Arr[j] << endl;
            continue;
        }
        else
        {
            missing_val = Arr[i];
            break;
        }

    }
    if(j==n&&i<n)
       missing_val = Arr[i];

    cout << "Missing Val =" << missing_val << endl;
    return missing_val;
}

// TC --> O(N*N)
// SC --> O(1)
int AppearsOnce_Sol2(vector<int> Arr)
{
    // Arr Unsorted
    int n = Arr.size();

    int missing_val=-1;
    // Using linear search
    for(int i=0;i<n;i++)
    {
        int val = Arr[i];
        int freq =0;
        for(int j=0;j<n;j++)
        {
            if(Arr[j]==val)
                freq++;
        }
        if(freq == 1)
        {
            missing_val = Arr[i];
            break;
        }
    }
    return missing_val;
}

// TC --> O(N) + O(NlogN) for Map Insert + O(logN/2) for Map Find + O(N/2+1) for Map traversal
// SC --> O(N/2+1) for storing Map
int AppearsOnce_Sol3(vector<int> Arr)
{
    int n = Arr.size();
    int missing_val = -1;
    map<int,int> Mp; // Hashing Storing Freq of each Value

    for(int i=0;i<n;i++)
    {
        int freq = 1;
        auto itr = Mp.find(Arr[i]);
        if(itr != Mp.end()) // Found
        {
            freq = itr->second;
            freq++;
            Mp[Arr[i]]=freq; // If Already inserted always use as this do not use insert
        }
        else
        {
            Mp.insert({Arr[i],freq}); // Insert can be used Only for First Time
        }
    }

    for(auto d:Mp)
    {
        if(d.second == 1)
        {
            missing_val = d.first;
            break;
        }
    }
    return missing_val;
}

// TC --> O(N)
// SC --> O(1)
int AppearsOnce_Sol4(vector<int> Arr)
{
    int n = Arr.size();

    int XoR_val = 0;
    for(int i=0;i<n;i++)
    {
        XoR_val = XoR_val^Arr[i];
    }
    return XoR_val;
}


int main()
{
    vector<int> Arr = {1,1,2,2,3,4,4};
    int missing_val = AppearsOnce_Sol1(Arr);
    cout << "The Missing Value SOl1 =" << missing_val << endl;


    missing_val = AppearsOnce_Sol2(Arr);
    cout << "The Missing Value Sol2 =" << missing_val << endl;


    missing_val = AppearsOnce_Sol3(Arr);
    cout << "The Missing Value Sol3 =" << missing_val << endl;

    missing_val = AppearsOnce_Sol4(Arr);
    cout << "The Missing Value Sol4 =" << missing_val << endl;
    return 0;
}
