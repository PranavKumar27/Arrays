#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int>& v)
{
    for(auto d:v)
        cout << d << " ";
    cout << endl;
}
// TC --> O(m+n)
// SC --> O(m+n) for Solving and Returning Ans

vector<int> merge_Sorted_Array_Sol1(vector<int>& Arr1,vector<int>& Arr2)
{
    vector<int> Ans;

    int m = Arr1.size();
    int n = Arr2.size();

    int i=0,j=0;
    while(i<m && j<n)
    {
        if(Arr1[i]<Arr2[j])
        {
            Ans.push_back(Arr1[i]);
            i++;
        }
        else
        {
            Ans.push_back(Arr2[j]);
            j++;
        }
    }

    while(i<m)
    {
        Ans.push_back(Arr1[i]);
        i++;
    }


    while(j<n)
    {
        Ans.push_back(Arr2[j]);
        j++;
    }
    return Ans;
}

// TC --> O(min(m,n)) + O(NLogn) + O(MLogM)
// SC --> O(m+n) for Returning Ans Can be considered solved in O(1) Space
vector<int> merge_Sorted_Array_Sol2(vector<int>& Arr1,vector<int>& Arr2)
{
    int m = Arr1.size();
    int n = Arr2.size();

    int i=m-1,j=0;

    while(i>=0 && j<n)
    {
        if(Arr1[i]>Arr2[j])
        {
            swap(Arr1[i],Arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }


    sort(Arr1.begin(),Arr1.end());
    sort(Arr2.begin(),Arr2.end());

    vector<int> Ans= Arr1;//(Arr1.begin(),Arr1.end());

    for(int j=0;j<n;j++)
    {
        Ans.push_back(Arr2[j]);
    }
    return Ans;
}

/*


NOTE :: This method works only for Unqiue Elements in the Array
 Gap Method Solution
  Gap = 5
                     ^
  1  3  5  7     0   2   6   8  9
  ^

                         ^
  1  3  5  7     0   2   6   8  9
     ^

                             ^
  1  3  5  7     0   2   6   8  9
        ^
                                ^
  1  3  5  7     0   2   6   8  9
           ^

  Gap = 3
           ^
  1  3  5  7     0   2   6   8  9
  ^
                 ^
  1  3  5  7     0   2   6   8  9  left = 1, right = 4, SWAP
     ^
                     ^
  1  0  5  7     3   2   6   8  9  left = 1, right = 5, SWAP
     ^
                         ^
  1  0  2  7     3   5   6   8  9  left = 2, right = 6
        ^
                             ^
  1  0  2  7     3   5   6   8  9 left = 3, right = 7
           ^
                                ^
  1  0  2  7     3   5   6   8  9  left = 4, right = 8
                 ^
                                    ^
  1  0  2  7     3   5   6   8  9      left = 5, right = 9 Exhausted right
                     ^
  Gap = 2

        ^
  1  0  2  7     3   5   6   8  9   left = 0, right = 2
  ^

           ^
  1  0  2  7     3   5   6   8  9   left = 1, right = 3
     ^

                 ^
  1  0  2  7     3   5   6   8  9   left = 2, right = 4
        ^
                     ^
  1  0  2  7     3   5   6   8  9   left = 1, right = 5 , SWAP
           ^

                         ^
  1  0  2  5     3   7   6   8  9   left = 1, right = 6
                 ^

  Gap =1                            ^

     ^
  1  0  2  5     3   7   6   8  9   left = 0, right = 1 , SWAP
  ^

        ^
  0  1  2  5     3   7   6   8  9   left = 1, right = 2
     ^

           ^
  0  1  2  5     3   7   6   8  9   left = 2, right = 3
        ^

                 ^
  0  1  2  5     3   7   6   8  9   left = 3, right = 4 , SWAP
           ^
                     ^
  0  1  2  3     5   7   6   8  9   left = 4, right = 5
                 ^
                         ^
  0  1  2  3     5   7   6   8  9   left = 5, right = 6 , SWAP
                     ^

                             ^
  0  1  2  3     5   6   7   8  9   left = 6, right = 7

  Hence Sorted
                         ^


*/
void swapIfGreater(vector<int>& Arr1,vector<int>& Arr2,int idx1,int idx2)
{
    if(Arr1[idx1]>Arr2[idx2])
        swap(Arr1[idx1],Arr2[idx2]);
}

// TC --> O(Log(m+n)) LogN since gap is divided by 2 everytime + O(M+n)
// SC --> O(1)
vector<int> merge_Sorted_Array_Sol3(vector<int>& Arr1,vector<int>& Arr2)
{
    int m = Arr1.size();
    int n = Arr2.size();

    int sum = m+n;
    int len = m+n;
    int gap;

    gap = sum/2 + sum%2;

    while(gap>0)
    {
        int left = 0;
        int right = left+gap;
        while(right>=0 && right<len)
        {
            // left and right are pointing to Arr1
            if(left<m && right<m)
            {
                swapIfGreater(Arr1,Arr1,left,right);
            }
            else if(left>=m && right>=m)
            {
                swapIfGreater(Arr2,Arr2,left-m,right-m);
            }
            else
            {
                swapIfGreater(Arr1,Arr2,left,right-m);
            }

            left++;
            right++;
        }
        if(gap==1)
            break;
        gap = gap/2 + gap%2;  // Run the loop for the gap = 1 only the First Time, Next time break out
    }

    print_1D_v(Arr1);
    print_1D_v(Arr2);
    vector<int> Ans= Arr1;

    for(int j=0;j<n;j++)
    {
        Ans.push_back(Arr2[j]);
    }
    return Ans;

}
int main()
{
    vector<int> Arr1 = {1,3,5,7};
    vector<int> Arr2 = {0,2,6,8,9};
    vector<int> MergeArr = merge_Sorted_Array_Sol3(Arr1,Arr2);
    cout << "Array 1-->" << endl;
    print_1D_v(Arr1);
    cout << "Array 2-->" << endl;
    print_1D_v(Arr2);
    cout << "Merge Sorted Array -->" << endl;
    print_1D_v(MergeArr);
    return 0;
}
