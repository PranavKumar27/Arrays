#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> v)
{
    for(auto d:v)
        cout << d << " ";
    cout << endl;
}


/*
Dutch Flag Algorithm : An Array can be divided into 3 sets
0 0 0 0 0       1 1 1 1           0 1 2 0         2 2 2 2
<---A--->   |  <----B--->    |  <----M--->  |    <---C--->
^       ^      ^        ^       ^        ^       ^       ^
0     low-1    low      mid     mid+1    high    high+1  n-1

Part A, B and C are sorted and Part M is un-sorted

We scan each element in Part M, and decide in which part the value should be swapped/moved to

Extreme left Part   0       --> low-1
                    low     --> mid
Extreme Right Part  high+1  --> n-1

Arr[mid] = 0  --> swap(Arr[low],Arr[mid])
                    low++ mid++

Arr[mid] = 1  --> mid++

Arr[mid] = 2  --> swap(Arr[mid],Arr[high])
                    high--


*/

// TC --> O(N)
// SC --> O(1)
void sort_Array_Sol3(vector<int>& Arr)
{
    int low,mid,high,n;
    n= Arr.size();
    low=mid=0;
    high = n-1;

    while(mid<=high)
    {
        if(Arr[mid]==0)
        {
            swap(Arr[low],Arr[mid]);
            low++;
            mid++;
        }
        else if(Arr[mid]==1)
        {
            mid++;
        }
        else if(Arr[mid]==2)
        {
            swap(Arr[mid],Arr[high]);
            high--;
        }
        else
            return;
    }
}


// TC --> O(NLogN) for Merge Sort
// SC --> O(1)
void sort_Array_Sol1(vector<int>& Arr)
{
    sort(Arr.begin(),Arr.end());
}

// TC --> O(2N)
// SC --> O(1)
void sort_Array_Sol2(vector<int>& Arr)
{
    // Count the freq of 0,1,2 and then update the Arr
    int cnt_0,cnt_1,cnt_2;
    cnt_0=cnt_1=cnt_2=0;

    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==0)
            cnt_0++;
        else if(Arr[i]==1)
            cnt_1++;
        else if(Arr[i]==2)
            cnt_2++;
        else
            return;
    }

    for(int i=0;i<cnt_0;i++)
        Arr[i]=0;
    for(int i=cnt_0;i<cnt_0+cnt_1;i++)
        Arr[i]=1;
    for(int i=cnt_0+cnt_1;i<n;i++)
        Arr[i]=2;
}

int main()
{
    vector<int> Arr_1 = {0,1,1,0,1,2,1,2,0,0,0};
    cout << "The Arr 1-->" << endl;
    print_1D_v(Arr_1);
    cout << "The Sorted Arr Using Sol 1-->" << endl;
    sort_Array_Sol1(Arr_1);
    print_1D_v(Arr_1);

    vector<int> Arr_2 = {0,1,1,0,1,2,1,2,0,0,0};
    cout << "The Arr 2 -->" << endl;
    print_1D_v(Arr_2);
    cout << "The Sorted Arr Using Sol 2 -->" << endl;
    sort_Array_Sol2(Arr_2);
    print_1D_v(Arr_2);

    vector<int> Arr_3 = {0,1,1,0,1,2,1,2,0,0,0};
    cout << "The Arr 3 -->" << endl;
    print_1D_v(Arr_3);
    cout << "The Sorted Arr Using Sol 3 -->" << endl;
    sort_Array_Sol3(Arr_3);
    print_1D_v(Arr_3);
    return 0;
}
