#include <iostream>
#include <vector>

using namespace std;

int max_Profit_In_Array_Sol1(vector<int>& Arr)
{
    int n = Arr.size();
    int max_Product = -1e9;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int prod = 1;
            for(int k=i;k<=j;k++)
            {
                prod = prod * Arr[k];
            }
            max_Product = max(max_Product,prod);
        }
    }
    return max_Product;
}

int max_Profit_In_Array_Sol2(vector<int>& Arr)
{
    int n = Arr.size();
    int max_Product = -1e9;
    for(int i=0;i<n;i++)
    {
        int prod = 1;
        for(int j=i;j<n;j++)
        {
            prod = prod * Arr[j];
            max_Product = max(max_Product,prod);
        }
    }
    return max_Product;
}


int max_Profit_In_Array_Sol3(vector<int>& Arr)
{
    int n = Arr.size();
    int max_Product = -1e9;

    int prefix = 1;
    int suffix = 1;
    for(int i=0;i<n;i++)
    {
        if(prefix==0)
            prefix = 1;
        if(suffix==0)
            suffix = 1;

        prefix = prefix*Arr[i];
        suffix = suffix*Arr[n-1-i];

        max_Product = max(max_Product,max(prefix,suffix));
    }
    return max_Product;
}

int main()
{
    vector<int> Arr = {1,0,-3,4,1};
    int ans = max_Profit_In_Array_Sol1(Arr);
    cout << "max_Profit_In_Array Using Sol1 =" << ans << endl;

    ans = max_Profit_In_Array_Sol2(Arr);
    cout << "max_Profit_In_Array Using Sol2 =" << ans << endl;

    ans = max_Profit_In_Array_Sol3(Arr);
    cout << "max_Profit_In_Array Using Sol3 =" << ans << endl;
    return 0;
}
