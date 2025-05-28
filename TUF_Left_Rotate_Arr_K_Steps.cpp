#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}


// Optimal Sol 1 for Left Rotate
// TC - O(N)
// SC - O(N)
void rotate_left(vector<int>& Arr, int k) {
  
    vector<int> temp = Arr;
    int sz = Arr.size();
    k=k%sz;
    for(int i=0;i<sz;i++)
    {
        int move_by = i-k;
        if(move_by>=0)
        {
            Arr[move_by]=temp[i];
        }
        else
        {
            Arr[(move_by+sz)%sz] = temp[i];
        }
    }
}

// Optimal Sol 1 for Right Rotate
// TC - O(N)
// SC - O(N)
void rotate_right(vector<int>& Arr, int k) {
  
    vector<int> temp = Arr;
    int sz = Arr.size();
    k=k%sz;
    for(int i=0;i<sz;i++)
    {
        int move_by = i+k;
        if(move_by<sz)
        {
            Arr[move_by]=temp[i];
        }
        else
        {
            Arr[(move_by)%sz] = temp[i];
        }
    }
}


// TC --> O(N)
// SC --> O(N)
vector<int> RotateArrayLeftByK_Sol1(const vector<int>& Arr,int k)
{
    int n = Arr.size();
    vector<int> New_Arr(n,-1);
    for(int i=0;i<n;i++)
    {
        int Move_from = i;
        int Move_to = i-k;
        if(Move_to<0)
            Move_to+=n;

        New_Arr[Move_to] = Arr[i];
    }
    return New_Arr;
}


// TC --> O(k) + O(n-k) + O(k) = O(k+n)
// SC --> O(N)
void RotateArrayLeftByK_Sol2(vector<int>& Arr,int k)
{
    int n = Arr.size();
    // Array rotated by 'n' times will come back as Arr itself
    // Hence k = k%n
    k = k%n;
    // Create a temp array to store first k Elements
    vector<int> temp;
    for(int i=0;i<k;i++)
       temp.push_back(Arr[i]);

    // Now Rotate Left by K

    for(int i=k;i<n;i++)
    {
        Arr[i-k]=Arr[i];
    }

    int j = 0;
    // Now Add the temp Array k Elements
    for(int i=n-k;i<n;i++)
    {
        Arr[i] = temp[i-(n-k)];
    }
}

void reverse_Arr_K(vector<int>& Arr,int start,int ends)
{
    int temp;
    ends = ends-1; // since zero based indexing and we passed ends as index+1
    while(start<ends)
    {
        temp = Arr[start];
        Arr[start] = Arr[ends];
        Arr[ends] = temp;
        start++;
        ends--;
    }
}
// TC --> O(k) + O(n-k) + O(n) = O(2N)
// SC --> O(1)
void RotateArrayLeftByK_Sol3(vector<int>& Arr,int k)
{
    int n = Arr.size();
    // Array rotated by 'n' times will come back as Arr itself
    // Hence k = k%n
    k = k%n;
    // Reverse first k Elements and store in same Array

    //reverse(Arr.begin(),Arr.begin()+k);
    //reverse(Arr.begin()+k,Arr.begin()+n);
    //reverse(Arr.begin(),Arr.end());

    reverse_Arr_K(Arr,0,k);
    reverse_Arr_K(Arr,k,n);
    reverse_Arr_K(Arr,0,n);

}

int main()
{

    vector<int> Arr = {1,2,3,4,5};
    vector<int> Arr_Cpy = Arr;
    cout << "The Array Before Rotation =" << endl;
    print_1D_v(Arr);
    int k = 2;
    vector<int> New_Arr = RotateArrayLeftByK_Sol1(Arr,k);
    cout << "Arr Rotated By K By Sol1 =" << k << endl;
    print_1D_v(New_Arr);

    RotateArrayLeftByK_Sol2(Arr,k);
    cout << "Arr Rotated By K By Sol2 =" << k << endl;
    print_1D_v(Arr);


    print_1D_v(Arr_Cpy);
    RotateArrayLeftByK_Sol3(Arr_Cpy,k);
    cout << "Arr Rotated By K By Sol3 =" << k << endl;
    print_1D_v(Arr_Cpy);

    return 0;
}
