#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}
// TC --> O(m+n) Either i moves or j moves at worst it is m+n
// Sc --> O(m+n) for Storing intersection Array
vector<int> SortedArrayInterSection_Sol2(vector<int> Arr1,vector<int> Arr2)
{
    int m = Arr1.size();
    int n = Arr2.size();
    vector<int> InterSection_Arr;
    int i=0,j=0;

    while(i<m && j<n)
    {
        if(Arr1[i] == Arr2[j])
        {
            InterSection_Arr.push_back(Arr1[i]);
            i++;
            j++;

        }
        else if(Arr1[i]<Arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return InterSection_Arr;
}

// TC --> O(m*n)
// SC --> O(n) + O(m+n) O(n) for storing visited and O(m+n) for storing intersection Array
vector<int> SortedArrayInterSection_Sol1(vector<int> Arr1,vector<int> Arr2)
{
    int m = Arr1.size();
    int n = Arr2.size();
    vector<int> InterSection_Arr;
    vector<int> visited(n,0);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[j] ==0 && Arr1[i] == Arr2[j])
            {
                visited[j]=1;
                InterSection_Arr.push_back(Arr1[i]);
                break;
            }
            else if(Arr2[j]>Arr1[i])
                break;
            else
                continue;
        }
    }

    return InterSection_Arr;
}

int main()
{
    vector<int> Arr1 ={1,2,2,3,3,4,5,5,6};
    vector<int> Arr2 ={2,3,3,5,6,6,7};

    vector<int> IntersectionArr = SortedArrayInterSection_Sol1(Arr1,Arr2);

    cout << "Sorted Array Intersection Solution 1 -->" << endl;
    print_1D_v(IntersectionArr);


    vector<int> IntersectionArr1 = SortedArrayInterSection_Sol2(Arr1,Arr2);

    cout << "Sorted Array Intersection Solution 2 -->" << endl;
    print_1D_v(IntersectionArr1);


    return 0;
}
