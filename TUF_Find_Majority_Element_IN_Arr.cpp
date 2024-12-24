#include <iostream>
#include <vector>
#include <map>

using namespace std;

// TC --> O(N*N)
// SC --> O(1)
// Brute Force Approach
int findMajority_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        int element = Arr[i];
        int cnt =0 ;
        for(int j=0;j<n;j++)
        {
            if(Arr[j]==element)
                cnt++;
        }

        if(cnt>n/2)
        {
            return element;
        }
    }

    return -1;

}

// TC --> O(N) for Traversal + O(NLogN) for Find in Map +O(N/2) for traversal
// SC --> O(1)

// Better than Brute Force Approach
int findMajority_Sol2(vector<int> Arr)
{
    map<int,int> FreqTable; // {element,count}
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        auto itr = FreqTable.find(Arr[i]);
        if(itr==FreqTable.end())
        {
            FreqTable[Arr[i]] = 1;
        }
        else
        {
            FreqTable[Arr[i]] = itr->second+1;
        }
    }

    for(auto mp:FreqTable)
    {
        if(mp.second > n/2)
            return mp.first;
    }
    return -1;

}

/*
Moore's Voting Algorithm
arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
          ^
  el  =  7
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
            ^
  el  =  7
  cnt =  2

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
              ^
  el  =  7
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                ^
  el  =  7
  cnt =  2

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                  ^
  el  =  7
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                    ^
  el  =  7
  cnt =  0
Set 1 = { 7,7,5,7,5,1 } No Majority Found Here

Start Again

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                      ^
  el  =  5
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                        ^
  el  =  5
  cnt =  0

Set 2 = { 5,7 } No Majority Found Here

Start Again

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                          ^
  el  =  5
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                            ^
  el  =  5
  cnt =  2

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                              ^
  el  =  5
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                                ^
  el  =  5
  cnt =  0

Set 2 = { 5,5,7,7 } No Majority Found Here

Start Again

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                                  ^
  el  =  5
  cnt =  1

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                                    ^
  el  =  5
  cnt =  2

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                                      ^
  el  =  5
  cnt =  3

arr[] = { 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5 }
                                        ^
  el  =  5
  cnt =  4

End of Iteration
Majority Element is possibly 5.

If a majority Element exists in an array then it will be the element
Hence find freq of element in Array


*/

// TC --> O(2N)
// SC --> O(1)
// Optimal Approach
int findMajority_Sol3(vector<int>& Arr)
{
    int n = Arr.size();
    int element,cnt;
    element = Arr[0];
    cnt = 1;
    for(int i=1;i<n;i++)
    {
        cout << " Arr[i]=" << Arr[i] << endl;
        if(Arr[i]==element)
            cnt++;
        else if(cnt==0)
        {
            element = Arr[i];
            cnt = 1;
        }
        else if(Arr[i]!=element)
            cnt--;
        else
        {
            cout << "Return -1" << endl;
            return -1;
        }

    }

    cout << "element=" << element << endl;
    cout << "cnt=" << cnt << endl;
    if(cnt>=1)
    {
        // check the freq of element in Array
        int freq = 0;
        for(int i=0;i<n;i++)
        {
            if(Arr[i]== element)
                freq++;
        }
        if(freq>n/2)
            return element;
    }

   return -1;

}

int main()
{
    vector<int> Arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};


    int ans = findMajority_Sol1(Arr);
    cout << "The Majority Element in Arr Using Sol1 =" << ans << endl;


    ans = findMajority_Sol2(Arr);
    cout << "The Majority Element in Arr Using Sol2 =" << ans << endl;


    ans = findMajority_Sol3(Arr);
    cout << "The Majority Element in Arr Using Sol3 =" << ans << endl;
    return 0;
}
