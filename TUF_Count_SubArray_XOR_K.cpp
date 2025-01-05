#include <iostream>
#include <vector>
#include <map>

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

/*
  <----------XR---->
    4    2   2     6     4
  <--X--><----K---->


  We have to find X
  X ^ K = XR

  (X^K)^K = XR^K
  X^(K^K) = XR^K
  X^0 = XR^K
  X = XR^K

  To find Prefix X/ remaining XOR values we can perform XR^K where XR is current XOR and K is the input XOR
 Hence  int remaining_XOR = XOR_data ^ K;

 Same way as in Prefix sum

*/

// TC --> O(N)*O(NLogn) for storing in Map
// SC --> O(N)
int CountSubArray_XOR_K_Sol3(vector<int>& Arr,int K)
{
    int n = Arr.size();
    int cnt = 0;
    map<int,int> HashSet;
    HashSet[0]=1;

    int XOR_data = 0;
    for(int i=0;i<n;i++)
    {
        //cout << "XOR_data Before=" << XOR_data << " ";
        XOR_data = XOR_data ^ Arr[i];

        int remaining_XOR = XOR_data ^ K;
        //cout << "remaining_XOR =" << remaining_XOR << " ";
        int freq = HashSet[remaining_XOR];
        //cout << "XOR_data After=" << XOR_data << " freq=" << freq << "   Arr[i]=" << Arr[i] << " cnt Before=" << cnt << " ";
        cnt = cnt+freq;
        //cout << " cnt After=" << cnt << " ";
        HashSet[XOR_data]++;
        //cout << " Inserting HashSet XOR_data=" << XOR_data << endl;
    }

    return cnt;
}

int main()
{
    vector<int> Arr = {4,2,2,6,4};
    int K = 6;
    int ans = CountSubArray_XOR_K_Sol1(Arr,K);
    cout << "Count Sub-Array XOR_K_   Sol1 =" << ans << endl;


    ans = CountSubArray_XOR_K_Sol2(Arr,K);
    cout << "Count Sub-Array XOR_K    _Sol2 =" << ans << endl;

    ans = CountSubArray_XOR_K_Sol3(Arr,K);
    cout << "Count Sub-Array XOR_K_    Sol3 =" << ans << endl;
    return 0;
}
