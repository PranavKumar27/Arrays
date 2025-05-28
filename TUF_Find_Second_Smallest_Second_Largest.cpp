#include <bits/stdc++.h>

// Link: https://www.geeksforgeeks.org/find-second-largest-element-array/
 
int Second_largest(vector<int> Arr)
{
    int f_largest = Arr[0];
    int s_largest = -1e9;
    int n = Arr.size();

    for(int i=1;i<n;i++)
    {
        if(Arr[i]>f_largest)
        {
            s_largest = f_largest;
            f_largest = Arr[i];
        }
        else if(Arr[i]>s_largest && Arr[i]!=f_largest)
        {
            s_largest = Arr[i];
        }
        else
        {

        }
    }
    return s_largest;
}

int Second_Smallest(vector<int> Arr)
{
    int f_smallest = Arr[0],s_smallest = 1e9;
    int n = Arr.size();

    for(int i=1;i<n;i++)
    {
        if(Arr[i]<f_smallest)
        {
            s_smallest = f_smallest;
            f_smallest = Arr[i];
        }
        else if(Arr[i]<s_smallest && Arr[i]!=f_smallest)
        {
            s_smallest = Arr[i];
        }
        else
        {

        }
    }
    return s_smallest;
}


vector<int> getSecondOrderElements(int n, vector<int> Arr) {
    // Write your code here.
    // sort(arr.begin(),arr.end(),[](int a,int b)
    // { return (a>b);});


    // vector<int> ans;
    // ans.push_back(arr[1]);
    // n = arr.size();
    // sort(arr.begin(),arr.end());
    // int s_smallest = arr[1];
    
    // ans.push_back(s_smallest);


    int s_largest = Second_largest(Arr);
    int s_smallest = Second_Smallest(Arr);

    vector<int> ans;
    ans.push_back(s_largest);
    ans.push_back(s_smallest);

    return ans;
    
}

