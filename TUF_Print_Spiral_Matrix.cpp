#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void PrintSprialTraversal(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int top=0,left=0,right=n-1,bottom=m-1;
    while(top<=bottom && left<=right)
    {
        for(int j=left;j<=right;j++)
            cout << setw(3) << matrix[top][j] << " ";

        cout << endl;
        top++;

        for(int i=top;i<=bottom;i++)
            cout << setw(3) << matrix[i][right] << " ";

        cout << endl;
        right--;

        if(top<=bottom) // Checks since top gets modified
        {
            for(int j=right;j>=left;j--)
            cout << setw(3) << matrix[bottom][j] << " ";

            cout << endl;
            bottom--;
        }


        if(left<=right) // Checks since right gets modified
        {
            for(int i=bottom;i>=top;i--)
            cout << setw(3) << matrix[i][left] << " ";

            cout << endl;
            left++;
        }

    }
}

int main()
{
    vector<vector<int>> matrix = { {1,2,3,4,5,6,7}};
    cout << "Spiral Traversal -->" << endl;
    PrintSprialTraversal(matrix);
    return 0;
}
