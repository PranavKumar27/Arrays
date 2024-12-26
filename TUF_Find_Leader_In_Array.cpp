#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

///A leader is an element such that everything to its right is smaller than the current element

// Brute Force Solution
// TC --> O(N^2)
// SC --> O(N) for Storing Ans
vector<int> findLeaderInArray_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    bool Leader;
    vector<int> LeaderList;
    for(int i=0;i<n;i++)
    {
        Leader = true;
        for(int j=i+1;j<n;j++)
        {
            if(Arr[i]>Arr[j])
                continue;
            else
            {
                Leader = false;
                break;
            }
        }
        if(Leader)
            LeaderList.push_back(Arr[i]);
    }
    return LeaderList;
}

// Most Optimal Solution
// TC --> O(N) for Traversal + O(NLogN) for Sort, Overall TC --> O(2N)0
// SC --> O(N) for Storing Ans
vector<int> findLeaderInArray_Sol2(vector<int> Arr)
{
    int n = Arr.size();
    bool Leader;
    vector<int> LeaderList;
    int max_val = -1e9,val;
    for(int i=n-1;i>=0;i--)
    {
        val = Arr[i];
        if(val>max_val)
        {
            LeaderList.push_back(val);
            // Keep track of the right maximum
            max_val = val;
        }
        else
        {

        }
    }
    sort(LeaderList.begin(),LeaderList.end());
    return LeaderList;
}


int main()
{
    vector<int> Arr = {10,22,12,3,0,6};
    cout << "Input Array -- >" << endl;
    print_1D_v(Arr);
    vector<int> Leaders = findLeaderInArray_Sol1(Arr);
    cout << "Leaders in Array Using Sol1-- >" << endl;
    print_1D_v(Leaders);

    vector<int> Leaders_2 = findLeaderInArray_Sol2(Arr);
    cout << "Leaders in Array Using Sol2-- >" << endl;
    print_1D_v(Leaders_2);
    return 0;
}
