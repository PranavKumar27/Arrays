#include <iostream>
#include <vector>


using namespace std;


/* Input ARR = 1, 2, 3, 4
               5, 6, 7, 8
               9,10,11,12
               13,14,15,16

   Output ARR = 13, 9, 5, 1
                14,10, 6, 2
                15,11, 7, 3
                16,12, 8, 4
*/

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

// Brute Force Solution
// TC --> O(M*N)
// SC --> O(M*N)
void Rotate_Matrix_90_Degress_SOl1(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> Ans_Mat(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            Ans_Mat[j][n-i-1] = matrix[i][j];
        }
    }
    print_2D_v(Ans_Mat);

}

void Rotate_Matrix_90_Degress_SOl2(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    
    // Step 1: Find the transpose
    
    // Step 2: Reverse all the rows
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            Ans_Mat[j][n-i-1] = matrix[i][j];
        }
    }
    print_2D_v(Ans_Mat);

}
int main()
{

    vector<vector<int>> Mat = { {1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9,10,11,12},
                               {13,14,15,16} };
    cout << "Matrix Rotation" << endl;
    Rotate_Matrix_90_Degress_SOl1(Mat);

    return 0;
}
