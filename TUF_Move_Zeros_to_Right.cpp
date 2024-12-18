#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

// TC --> O(N*N)
// SC --> O(N)
void MoveZeros_to_Right_Sol1(vector<int>& Arr)
{
    // Store all Non-Zeros in temp Array
    vector<int> temp;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        if(Arr[i]!=0)
            temp.push_back(Arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(i>=temp.size())
        {
            Arr[i]=0;
        }
        else
        {
            Arr[i] = temp[i];
        }
    }
}

// TC --> O(N)
// SC --> O(1)
void MoveZeros_to_Right_Sol2(vector<int>& Arr)
{
    // Keep 2 pointers i and j
    // i for Zero and J for Non-Zero

    int n = Arr.size();
    int j=-1;
    for(int i=0;i<n ;i++)
    {
        if(Arr[i]==0 && j==-1)
        {
            j=i; // Executed Only Once
        }
        else if(Arr[i]!=0 && j!=-1) // Here Arr[j] = 0
        {
            Arr[j]=Arr[i];
            Arr[i] = 0;
            j++;
        }
        else
        {
            // Do Nothing
        }
    }
}

// TC --> O(x)+O(n-x) = O(N) where x is the index of 1st 0 Value
// SC --> O(1)
void MoveZeros_to_Right_Sol3(vector<int>& Arr)
{
    // Keep 2 pointers i and j
    // i for Zero and J for Non-Zero

    int n = Arr.size();
    int j=-1;
    for(int i=0;i<n ;i++)
    {
        if(Arr[i]==0)
        {
            j=i; // Executed Only Once
            break;
        }
    }

    if(j==-1)
        return ; // No Zero Found

    for(int i=j+1;i<n ;i++)
    {
        if(Arr[i]!=0)
        {
            swap(Arr[i],Arr[j]);
            j++; // Point J to 0 Value
        }
    }
}

int main()
{
    vector<int> Arr ={1,0,2,3,2,0,0,4,5,1};
    vector<int> Arr_Cpy = Arr;
    vector<int> Arr_Cpy2 = Arr;

    cout << "Arr Before Sol1" << endl;
    print_1D_v(Arr);
    MoveZeros_to_Right_Sol1(Arr);
    cout << "Arr After moving Zeros to Right Sol1" << endl;
    print_1D_v(Arr);

    cout << "Arr Before Sol2" << endl;
    print_1D_v(Arr_Cpy);
    MoveZeros_to_Right_Sol2(Arr_Cpy);
    cout << "Arr After moving Zeros to Right Sol2" << endl;
    print_1D_v(Arr_Cpy);

    cout << "Arr Before Sol3" << endl;
    print_1D_v(Arr_Cpy2);
    MoveZeros_to_Right_Sol2(Arr_Cpy2);
    cout << "Arr After moving Zeros to Right Sol3" << endl;
    print_1D_v(Arr_Cpy2);
    return 0;
}
