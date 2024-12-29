#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << "\t";

    cout << endl;
}

void print_PascalTriangle(int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back(1);

        // For Spaces
        for(int j=0;j<n-i-1;j++)
            cout << setw(4) << " ";

        // For Printing values
        for(int j=0;j<i+1;j++)
        {
            cout << setw(8) << temp[j] ;
        }

        // For Generating Values of Next Row
        if(temp.size()>=2)
        {
            // Resize temp
            vector<int> temp2;
            temp2.push_back(1);
            int x= temp.size();
            for(int k=0;k+1<x;k++)
            {
                int val = temp[k]+temp[k+1];
                temp2.push_back(val);
            }
            temp.clear();
            temp = temp2;
        }
        cout << endl;
    }
}

/*
nCr = n!/(r!*(n-r)!)

nCr = n*(n-1)*(n-2)*(n-3)*......1 / r! * (n-r)!

nCr = n*(n-1)*(n-2)....(n-r+1)*(n-r)! / r! * (n-r)!

nCr = n*(n-1)*(n-2)....(n-r+1)/r!

nCr = n*(n-1)*(n-2)....(n-r+1)/r*(r-1)*(r-2)*.....1

nCr = n*(n-1)*(n-2)....(n-r+1)/1*2*3.....r

nCr = n-i+1/i for any i from 1 to r

eg if i=1,2,3 and n=10

10c3 = 10*9*8/1*2*3

or

nCr = n-i/i+1 for any i from 0 to r

*/
int NcRValue(int n,int r)
{
    int ans = 1;

    for(int i=0;i<r;i++)
    {
        ans = ans*(n-i);
        ans = ans/(i+1);
    }
    return ans;
}

// Brute Approach
// TC --> O(N*N)
// SC --> O(1)
void PascalTri_Row_generation_Sol1(int n)
{
    for(int i=0;i<=n;i++)
    {
        int val = NcRValue(n,i);// Send 5c0 5c1 5c2 5c3 5c4 5c5
        cout << setw(5) << val;
    }
}

/*
For row 5-->  1    4       6     4       1
            4c0   4c1     4c2   4c3     4c4
            1     4/1     4*3/  4*3*2/  4*3*2*1/
                          1*2   1*2*3   1*2*3*4
 For any i , 1     n-i+1/
                    i
*/
// Optimal Approach
// TC --> O(N)
// SC --> O(1)
void PascalTri_Row_generation_Sol2(int n)
{
    int ans = 1;
    for(int i=0;i<=n;i++)
    {
        if(i!=0)
        {
            ans = ans*(n-i+1);
            ans = ans/i;
        }
        cout << setw(5) << ans;
    }
}

// Optimal Approach
// TC --> O(N*N)
// SC --> O(1)
void print_PascalTriangle_Sol2(int n)
{
    for(int i=0;i<=n;i++)
    {
        PascalTri_Row_generation_Sol2(i);
        cout << endl;
    }
}

int main()
{
    int n1 = 6;
    cout << "Pascal Triangle -->" << endl;
    print_PascalTriangle(n1);

    int n=5,r=3;
    int ans = NcRValue(n-1,r-1);
    cout << "Value of n=" << n << " r=" << r << " ans=" << ans << endl;

    cout << "\nRow Generation of Pascal Triangle for row Using Sol1= -->" << n+1 << endl;
    PascalTri_Row_generation_Sol1(n);

    cout << "\nRow Generation of Pascal Triangle for row Using Sol2= -->" << n+1 << endl;
    PascalTri_Row_generation_Sol2(n);

    cout << "Pascal Triangle -->" << endl;
    print_PascalTriangle_Sol2(n);

    return 0;
}
