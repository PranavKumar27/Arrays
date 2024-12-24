#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void print_SubArray(vector<int> Arr,int start,int ends)
{
    cout << "SubArray -->"  << endl;
    for(int idx = start;idx<=ends;idx++)
    {
        cout << Arr[idx] << " ";
    }
    cout << endl;
}

// Brute Solution
// TC --> O(N^3)
// SC --> O(1)
int maxSum_Sol1(vector<int>& Arr)
{
    int n = Arr.size();
    int max_sum=-1e9,Max_Start,Max_End;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum+=Arr[k];
            }
            if(sum>max_sum)
            {
                max_sum = sum;
                Max_Start = i;
                Max_End = j;
            }

        }
    }
    print_SubArray(Arr,Max_Start,Max_End);
    return max_sum;
}

// Better than Brute Solution
// TC --> O(N^2)
// SC --> O(1)
int maxSum_Sol2(vector<int>& Arr)
{
    int n = Arr.size();
    int max_sum=-1e9,Max_Start,Max_End;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
            sum+=Arr[j];
            if(sum>max_sum)
            {
                max_sum = sum;
                Max_Start = i;
                Max_End = j;
            }
        }
    }
    print_SubArray(Arr,Max_Start,Max_End);
    return max_sum;
}


/*
Kadane's Algorithm
An Arr as [-2,-3,4,-1,-2,1,5,-3]
            ^
    sum =  0
New sum = -2
Reset sum =0 since No advantage in carry-forward of Negative sum

---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                 ^
    sum =  0
New sum = -3
Reset sum =0 since No advantage in carry-forward of Negative sum


---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                   ^
    sum =  0
New sum =  4
Since New sum is Positive, we can carry forward Positive sum


---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                      ^
    sum =  4
New sum =  3
Since New sum is Positive, we can carry forward Positive sum


---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                         ^
    sum =  3
New sum =  1
Since New sum is Positive, we can carry forward Positive sum

---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                           ^
    sum =  1
New sum =  2
Since New sum is Positive, we can carry forward Positive sum


---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                             ^
    sum =  2
New sum =  7  --- > MAX SUM FOUND
Since New sum is Positive, we can carry forward Positive sum

---> Arr as [-2,-3,4,-1,-2,1,5,-3]
                             ^
    sum =  7
New sum =  4
Since New sum is Positive, we can carry forward Positive sum

At the end return the Max SUM Stored

*/
// Most Optimal Solution
// TC --> O(N)
// SC --> O(1)
int maxSum_Sol3(vector<int>& Arr)
{
    int n = Arr.size();
    int sum = 0,max_sum = INT_MIN,start,Max_Start,Max_End;

    for(int i=0;i<n;i++)
    {
        if(sum==0)
            start = i;

        sum+=Arr[i];

        if(sum>max_sum)
        {
            max_sum = sum;
            Max_Start = start;
            Max_End = i;
        }

        if(sum<0)
            sum = 0;
    }
    print_SubArray(Arr,Max_Start,Max_End);
    return max_sum;
}


int main()
{
    vector<int> Arr ={-2,-3,4,-1,-2,1,5,-3};
    int ans = maxSum_Sol1(Arr);
    cout << "maxSum for Array Using Sol1 =" << ans << endl;

    ans = maxSum_Sol2(Arr);
    cout << "maxSum for Array Using Sol2 =" << ans << endl;

    ans = maxSum_Sol3(Arr);
    cout << "maxSum for Array Using Sol3 =" << ans << endl;
    return 0;
}
