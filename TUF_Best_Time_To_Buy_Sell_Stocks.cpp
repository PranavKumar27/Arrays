#include <iostream>
#include <vector>

using namespace std;

// Brute Force Solution
// TC --> O(N*N)
// SC = O(1)
int max_Profit_Sol1(vector<int> Arr)
{
    int n = Arr.size();
    int profit,max_profit=0;
    for(int i=0;i<n;i++) // Buy on i day
    {
        for(int j=i+1;j<n;j++) // Sell on i+1 day
        {
            profit = Arr[j]-Arr[i];
            max_profit = max(max_profit,profit);
        }
    }
    return max_profit;
}

// Optimal Solution
// TC --> O(N)
// SC = O(1)
int max_Profit_Sol2(vector<int> Arr)
{
    int n = Arr.size();
    int profit,max_profit=0;
    int min_prices = Arr[0];
    for(int i=1;i<n;i++) // Sell on i day
    {
        min_prices = min(min_prices,Arr[i]);
        profit = Arr[i]-min_prices;
        max_profit = max(max_profit,profit);
    }
    return max_profit;
}

int main()
{
    vector<int> Prices = {7,1,5,3,6,4};
    int ans = max_Profit_Sol1(Prices);
    cout << "max_Profit_Sol1 =" << ans << endl;

    ans = max_Profit_Sol2(Prices);
    cout << "max_Profit_Sol2 =" << ans << endl;
    return 0;
}
