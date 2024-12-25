#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

// TC --> O(N)+O(N/2)
// SC --> O(N)
// Brute Force
vector<int> ReArrangeElementsBySign_Sol1(const vector<int>& Arr)
{
    int n = Arr.size();
    vector<int>Pos,Neg;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]>0) // No Zeros
            Pos.push_back(Arr[i]);
        else
            Neg.push_back(Arr[i]);
    }
    vector<int> Ans(n);
    for(int i=0;i<n/2;i++)
    {
        Ans[2*i] = Pos[i];
        Ans[2*i+1] = Neg[i];
    }
    return Ans;
}

// TC --> O(N)
// SC --> O(N)
// Optimal Solution
vector<int> ReArrangeElementsBySign_Sol2(const vector<int>& Arr)
{
    int n = Arr.size();
    int pos=0,neg=0;
    vector<int> Ans(n);
    for(int i=0;i<n;i++)
    {
        if(Arr[i]>0) // No Zeros
        {
            Ans[2*pos] = Arr[i];
            pos++;
        }

        else
        {
           Ans[2*neg+1] = Arr[i];
           neg++;
        }
    }

    return Ans;
}

// TC --> O(N) + O(min(pos,neg)) + O(neg_sz - min(pos,neg))  in Worst case second part can be O(N)
// So overall TC --> O(2N)
// SC --> O(N)
vector<int> ReArrangeElementsBySign_Sol3(const vector<int>& Arr)
{
    vector<int> Pos,Neg;
    int n = Arr.size();
    vector<int> Ans(n);

    for(int i=0;i<n;i++)
    {
        int val = Arr[i];
        if(val>0)
            Pos.push_back(val);
        else
            Neg.push_back(val);
    }

    int pos_sz = Pos.size();
    int neg_sz = Neg.size();

    int m = min(pos_sz,neg_sz);

    int i=0;
    for(;i<m;i++)
    {
        Ans[2*i] = Pos[i];
        Ans[2*i+1] = Neg[i];
    }

    i=2*m;
    if(m<pos_sz) // Neg exhausted
    {
        for(int j = m;j<pos_sz;j++,i++)
            Ans[i] = Pos[j];
    }
    else
    {
        for(int j = m;j<neg_sz;j++,i++)
            Ans[i] = Neg[j];
    }

    return Ans;
}



int main()
{
    vector<int> Arr = {-3,-2,1,2,3,-1};
    cout << "The Array" << endl;
    print_1D_v(Arr);
    vector<int> Ans = ReArrangeElementsBySign_Sol1(Arr);
    cout << "The  Ans Array Using Sol1" << endl;
    print_1D_v(Ans);


    vector<int> Ans1 = ReArrangeElementsBySign_Sol1(Arr);
    cout << "The  Ans Array Using Sol2" << endl;
    print_1D_v(Ans1);


    vector<int> Arr2 = {-1,-2,3,-4,-3,1};
    cout << "The Array" << endl;
    print_1D_v(Arr2);

    vector<int> Ans3 = ReArrangeElementsBySign_Sol3(Arr2);
    cout << "The  Ans Array Using Sol3" << endl;
    print_1D_v(Ans3);


    return 0;
}
