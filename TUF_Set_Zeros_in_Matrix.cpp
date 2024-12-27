#include <iostream>
#include <vector>

using namespace std;


void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

void print_2D_v(vector<vector<int>> _2DArr)
{
    for(auto Arr:_2DArr)
        print_1D_v(Arr);
    cout << endl;
}

void MarkRow(int i,vector<vector<int>>& Arr)
{
    int n = Arr[0].size();

    for(int j=0;j<n;j++)
    {
        Arr[i][j]=-1;
    }
}

void MarkCol(int j,vector<vector<int>>& Arr)
{
    int m = Arr.size();

    for(int i=0;i<m;i++)
    {
        Arr[i][j]=-1;
    }
}
// Brute Solution
// TC --> O(M*N *( M+N ) ) + O(M*N) ~~ O(N^3)
// SC --> O(1)
void SetZerosInMatrix_Sol1(vector<vector<int>>& Arr)
{
    int m = Arr.size();
    int n = Arr[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==0)
            {
                // Traverse in row i and Set every 1 in row as -1
                MarkRow(i,Arr);

                // Traverse in col j and Set every 1 in col as -1
                MarkCol(j,Arr);
            }
        }
    }

    // Now convert all -1 values as 0
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==-1)
            {
                Arr[i][j]=0;
            }
        }
    }
    return;
}

// Better Solution
// TC --> O(M*N ) + O(M*N) ~~ O(N^2)
// SC --> O(M+N)
void SetZerosInMatrix_Sol2(vector<vector<int>>& Arr)
{
    int m = Arr.size();
    int n = Arr[0].size();
    vector<int> Row(m,0),Col(n,0);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==0)
            {
                // set as 1 in the row index in Row vector
                Row[i]=1;

                // set as 1 in the col index in Col Vector
                Col[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Row[i]==1||Col[j]==1)
            {
                Arr[i][j]=0;
            }
        }
    }

}

// Optimal Solution
// TC --> O(M*N ) + O(M*N) + O(M) + O(N) ~~ O(N^2)
// SC --> O(1)
void SetZerosInMatrix_Sol3(vector<vector<int>>& Arr)
{
    int m = Arr.size();
    int n = Arr[0].size();
    //vector<int> Row(m,0);  Arr[i][...]
    // vector<int> Col(n,0); Arr[...][j]
    int Col_0=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Arr[i][j]==0)
            {
                if(j!=0)
                    Arr[0][j]=0;
                else
                    Col_0 = 0;

                Arr[i][0]=0;
            }
        }
    }

    for(int i=m-1;i>=1;i--)
    {
        for(int j=n-1;j>=1;j--)
        {
            if(Arr[i][j]!=0)
            {
               if(Arr[i][0]==0||Arr[0][j]==0)
                {
                    Arr[i][j]=0;
                } 
            }
        }
    }

    // For row 0, we have dependency with col 0
    for(int j=n-1;j>=1;j--)
    {
        if(Arr[0][0]==0)
        {
            Arr[0][j]=0;
        }
    }

    // For Col 0, we have dependency with Col_0
    if(Col_0==0)
    {
        for(int i=m-1;i>=0;i--)
        {
            Arr[i][0]=0;
        }
    }

}
int main()
{
    vector<vector<int>> Arr = { {1,1,1,1},{1,0,0,1},{1,1,0,1},{0,1,1,1} };

    cout << "Processing Using SOl1    2 D Array -->" << endl;
    print_2D_v(Arr);

    cout << "Ans - Set Zeroes in Matrix Using Sol 1-->" << endl;
    SetZerosInMatrix_Sol1(Arr);
    print_2D_v(Arr);

    vector<vector<int>> Arr1 = { {1,1,1,1},{1,0,0,1},{1,1,0,1},{0,1,1,1} };
    cout << "Processing Using SOl2   2 D Array -->" << endl;
    print_2D_v(Arr1);

    cout << "Ans - Set Zeroes in Matrix Using SOl 2-->" << endl;
    SetZerosInMatrix_Sol2(Arr1);
    print_2D_v(Arr1);


    vector<vector<int>> Arr3 = { {1,1,1,1},{1,0,0,1},{1,1,0,1},{0,1,1,1} };
    cout << "Processing Using SOl3    2 D Array -->" << endl;
    print_2D_v(Arr3);

    cout << "Ans - Set Zeroes in Matrix Using SOl 3-->" << endl;
    SetZerosInMatrix_Sol3(Arr3);
    print_2D_v(Arr3);

    return 0;
}
