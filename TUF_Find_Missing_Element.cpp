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
// SC --> O(1)
int findMissingElement_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    int val = 1;
    int missing_val;
    for(int i=1;i<n+2;i++)
    {
        int j=0;
        for(;j<n;j++)
        {
            if(Arr[j]==i)
                break;
        }
        // Couldn't find i in Arr
        if(j==n)
        {
            missing_val = i;
            break;
        }
    }
    return missing_val;
}
// TC -> O(N+N) for Two For loops
// SC -> O(N) for Hashing
int findMissingElement_Sol2(vector<int> Arr)
{
    int n = Arr.size();
    // Using Hashing to store if data present in Arr
    vector<int> Hash(n+2,0);
    int missing_val = -1;

    for(int i=0;i<n;i++)
    {
        int val = Arr[i];
        Hash[val] = 1;
    }

    print_1D_v(Hash);

    for(int i=1;i<n+2;i++)
    {
        if(Hash[i]==0)
        {
            missing_val = i;
            break;
        }

    }

    return missing_val;

}

// TC --> O(N) for For loop
// SC -->O(1)
int findMissingElement_Sol3(vector<int> Arr)
{
    int missing_val=-1;
    int n = Arr.size();
    // Using Hashing to store if data present in Arr
    // since 1 element is missing Expected N = n+1;
    int N = n+1;
    int Expected_sum = (N*(N+1))/2;
    int Current_sum = 0;

    for(int i=0;i<n;i++)
    {
        Current_sum += Arr[i];
    }

    missing_val = Expected_sum - Current_sum;

    return missing_val;

}

// TC --> O(N+N) for For loop
// SC -->O(1)
int findMissingElement_Sol4(vector<int> Arr)
{
    int missing_val=-1;
    int n = Arr.size();
    // since 1 element is missing Expected N = n+1;

    int XOR1=0,XOR2=0;

    for(int i=1;i<=n+1;i++)
    {
        XOR1 = XOR1^i;
    }

    for(int i=0;i<n;i++)
    {
        XOR2 = XOR2^Arr[i];
    }

    missing_val = XOR1^XOR2;
    cout << "missing_val =" << missing_val << endl;

    return missing_val;

}

// TC --> O(N) for For loop
// SC -->O(1)
int findMissingElement_Sol5(vector<int> Arr)
{
    int missing_val=-1;
    int n = Arr.size();
    // since 1 element is missing Expected N = n+1;
    // 1^1 = 0 
    // 0^6 = 6
    // XOR1 = 1^2^3^4^5^6^7
    // XOR2 = 1^2^3^4^5^7
    // XOR1^XOR2 = (1^2^3^4^5^6^7) ^ (1^2^3^4^5^7)
    //            1^1 ^ 2^2 ^ 3^3 ^ 4^4 ^ 5^5 ^ 6 ^ 7^7
    //              0 ^ 0   ^   0 ^  0  ^   0  ^ 6 ^ 0
    //             = 6
    int XOR1=0,XOR2=0;
    
    for(int i=0;i<n;i++)
    {
        XOR2 = XOR2^Arr[i];
        XOR1 = XOR1^(i+1); // XOR1 has XOR only upto n
    }
    XOR1 = XOR1^(n+1);

    missing_val = XOR1^XOR2;
    cout << "missing_val =" << missing_val << endl;

    return missing_val;

}

int main()
{
    vector<int> Arr = {1,2,3,4,5,7};
    int missing_val = findMissingElement_Sol1(Arr);
    cout << "Missing Value Sol1=" << missing_val << endl;

    missing_val = findMissingElement_Sol2(Arr);
    cout << "Missing Value Sol2=" << missing_val << endl;

    missing_val = findMissingElement_Sol3(Arr);
    cout << "Missing Value Sol3=" << missing_val << endl;

    missing_val = findMissingElement_Sol4(Arr);
    cout << "Missing Value Sol4=" << missing_val << endl;
    return 0;
}
