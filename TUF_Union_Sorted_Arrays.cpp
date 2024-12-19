#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

//TC --> O(mLogn) + (nLogn) + O(m+n)
// for Arr1 loop m*Set has logn , for Arr2 loop n*Set has logn , and O(n) for reading from Set and puttng in Union Array
//SC --> O(m+n) + O(m+n) for Set and Union Array

vector<int> UnionSortedArray_Sol1(vector<int>& Arr1,vector<int>& Arr2)
{
    vector<int> Union_Arr;
    int m = Arr1.size(),n=Arr2.size();
    set<int> S;

    for(int i=0;i<m;i++)
        S.insert(Arr1[i]);

    for(int j=0;j<n;j++)
        S.insert(Arr2[j]);

    for(auto d:S)
        Union_Arr.push_back(d);

    return Union_Arr;

}

// TC --> O(m) + O(n)
// SC --> O(m+n)
vector<int> UnionSortedArray_Sol2(vector<int> Arr1,vector<int> Arr2)
{
    vector<int> Union_Arr;
    int m = Arr1.size(),n=Arr2.size();
    int prev = -1e9;
    for(int i=0;i<m;i++)
    {
        if(Arr1[i]!=prev)
        {
            Union_Arr.push_back(Arr1[i]);
        }
        prev = Arr1[i];
    }

    for(int j=0;j<n;j++)
    {
        auto itr = find(Union_Arr.begin(),Union_Arr.end(),Arr2[j]);
        if(itr==Union_Arr.end())
        {
            Union_Arr.push_back(Arr2[j]);
        }
    }
    return Union_Arr;
}

// Optimal Approach for UnSorted Array
// TC --> O(m+n) + O(n) for find()
// SC --> O(m+n) for storing Union Array
vector<int> UnionOfUnSortedArray_Sol3(vector<int> Arr1,vector<int> Arr2)
{
    vector<int> Union_Arr;
    int m = Arr1.size(),n=Arr2.size();
    int j=0;
    int i =0;
    while(i<m && j<n)
    {
        if(Arr1[i]<=Arr2[j])
        {
            auto itr = find(Union_Arr.begin(),Union_Arr.end(),Arr1[i]);
            if(itr!=Union_Arr.end()) // Found in Union_Arr
                i++;
            else
            {
                Union_Arr.push_back(Arr1[i]);
                i++;
            }

        }
        else
        {
            // Find if Arr2[j] is already present in Union_Arr
            auto itr = find(Union_Arr.begin(),Union_Arr.end(),Arr2[j]);
            if(itr!=Union_Arr.end()) // Found in Union_Arr
                j++;
            else
            {
                Union_Arr.push_back(Arr2[j]);
                j++;
            }
        }
    }

    while(j<n)
    {
       auto itr = find(Union_Arr.begin(),Union_Arr.end(),Arr2[j]);
       if(itr!=Union_Arr.end()) // Found in Union_Arr
            j++;
       else
       {
            Union_Arr.push_back(Arr2[j]);
            j++;
       }
    }

    while(i<m)
    {
        auto itr = find(Union_Arr.begin(),Union_Arr.end(),Arr1[i]);
        if(itr!=Union_Arr.end()) // Found in Union_Arr
            i++;
        else
        {
            Union_Arr.push_back(Arr1[i]);
            i++;
        }
    }

    return Union_Arr;
}
// Optimal Approach for Sorted Array
// TC --> O(m+n)
// SC --> O(m+n) for Storing Union Array
vector<int> UnionOfSortedArray_Sol3(vector<int> Arr1,vector<int> Arr2)
{
    vector<int> Union_Arr;
    int m = Arr1.size(),n=Arr2.size();
    int j=0;
    int i=0;
    while(i<m && j<n)
    {
        if(Arr1[i]<=Arr2[j])
        {
            if(Union_Arr.size()==0 ||
                Union_Arr.back()!=Arr1[i])
            {
                Union_Arr.push_back(Arr1[i]);
            }
            i++;
        }
        else
        {
            // Find if Arr2[j] is already present in Union_Arr
            if(Union_Arr.size()==0 ||
                Union_Arr.back()!=Arr2[j])
            {
                Union_Arr.push_back(Arr2[j]);
            }
            j++;
        }
    }

    while(i<m)
    {
       if(Union_Arr.size()==0 ||
            Union_Arr.back()!=Arr1[i])
        {
            Union_Arr.push_back(Arr1[i]);
        }
        i++;
    }

    while(j<n)
    {
       if(Union_Arr.size()==0 ||
            Union_Arr.back()!=Arr2[j])
        {
            Union_Arr.push_back(Arr2[j]);
        }
        j++;
    }

    return Union_Arr;
}

int main()
{
    vector<int> Arr1 = {1,2,3,3,4,5};
    vector<int> Arr2 = {2,2,3,4,4,5,6,6};

    cout << " Array1 -->" << endl;
    print_1D_v(Arr1);
    cout << " Array2 -->" << endl;
    print_1D_v(Arr2);

    /*vector<int> Union_Arr = UnionSortedArray_Sol1(Arr1,Arr2);
    cout << "Union Array Using Sol1-->" << endl;
    print_1D_v(Union_Arr);


    vector<int> Union_Arr2 = UnionSortedArray_Sol2(Arr1,Arr2);
    cout << "Union Array Using Sol2-->" << endl;
    print_1D_v(Union_Arr2);

    */

    vector<int> Union_Arr3 = UnionOfSortedArray_Sol3(Arr1,Arr2);
    cout << "Union Array Using Sol3-->" << endl;
    print_1D_v(Union_Arr3);

    vector<int> Union_Arr4 = UnionOfUnSortedArray_Sol3(Arr1,Arr2);
    cout << "Union Array Of Unsorted Array Using Sol3-->" << endl;
    print_1D_v(Union_Arr4);
    return 0;
}
