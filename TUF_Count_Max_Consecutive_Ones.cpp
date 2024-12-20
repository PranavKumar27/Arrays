#include <iostream>
#include <vector>

using namespace std;

// TC --> O(n)
// SC --> O(1)
int maxConsecutive_Ones(vector<int> Arr)
{
    int max_ones=-1e9,consecutive_Ones=0;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==1)
        {
            consecutive_Ones=consecutive_Ones+1;
            if(max_ones<consecutive_Ones)
                max_ones = consecutive_Ones;
        }
        else
        {
            consecutive_Ones = 0;
        }
    }
    return max_ones;
}
int main()
{
    vector<int> Arr = {2,3,1,1,4,1,1,1,5,7};
    int max_ones = maxConsecutive_Ones(Arr);
    cout << "maxConsecutive_Ones =" << max_ones << endl;
    return 0;
}
