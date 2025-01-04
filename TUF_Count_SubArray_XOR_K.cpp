#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr,int i,int j)
{
    for(int k=i;k<=j;k++)
        cout << Arr[k] << " ";
    cout << endl;
}

// TC --> O(N*N*N)
// SC --> O(1)
int CountSubArray_XOR_K_Sol1(vector<int>& Arr,int K)
{
    int n = Arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        //cout << "i=" << i << endl;
        for(int j=i;j<n;j++)
        {
            //cout << "j=" << j << endl;
            int XOR_data = 0;
            for(int k=i;k<=j;k++)
            {
                //cout << "k=" << k << endl;
                XOR_data = XOR_data ^ Arr[k];

            }
            if(XOR_data == K)
            {
                cout << "Found Sub Array XOR value =" << XOR_data << endl;
                print_1D_v(Arr,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

// TC --> O(N*N)
// SC --> O(1)
int CountSubArray_XOR_K_Sol2(vector<int>& Arr,int K)
{
    int n = Arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int XOR_data = 0;
        for(int j=i;j<n;j++)
        {
            //cout << "j=" << j << endl;
            XOR_data = XOR_data ^ Arr[j];
            if(XOR_data == K)
            {
                cout << "Found Sub Array XOR value =" << XOR_data << endl;
                print_1D_v(Arr,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> Arr = {4,2,2,6,4};
    int K = 6;
    int ans = CountSubArray_XOR_K_Sol1(Arr,K);
    cout << "Count Sub-Array XOR_K_Sol1 =" << ans << endl;


    ans = CountSubArray_XOR_K_Sol2(Arr,K);
    cout << "Count Sub-Array XOR_K_Sol1 =" << ans << endl;
    return 0;
}
