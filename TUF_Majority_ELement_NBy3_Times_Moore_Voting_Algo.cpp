#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

vector<int> MooreVotingALgo_Max_Occurence(vector<int> Arr)
{
    int n = Arr.size();
    vector<int> Ans;
    int max_occur = (n/3)+1;
    int element_1,element_2,cnt_1=0,cnt_2=0;
    for(int i=0;i<n;i++)
    {
        if(cnt_1==0 && element_2 != Arr[i])
        {
            element_1 = Arr[i];
            cnt_1=1;
        }
        else if(cnt_2==0 && element_1 != Arr[i])
        {
            element_2 = Arr[i];
            cnt_2 = 1;
        }
        else if(element_1 == Arr[i])
        {
            cnt_1++;
        }
        else if(element_2 == Arr[i])
        {
            cnt_2++;
        }
        else
        {
            cnt_1--;
            cnt_2--;
        }
    }


    // Find freq of element_1 and element_2 in Arr
    int freq_1=0,freq_2=0;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==element_1)
            freq_1++;
        if(Arr[i]==element_2)
            freq_2++;
    }

    cout << "freq1=" << freq_1 << " freq2=" << freq_2 << endl;

    if(freq_1>=max_occur)
       Ans.push_back(element_1);

    if(freq_2>=max_occur)
        Ans.push_back(element_2);

    return Ans;
}

int main()
{
    vector<int> Arr = {2,1,1,4,1,4,4,6};
    vector<int> Ans = MooreVotingALgo_Max_Occurence(Arr);

    cout << "Elements occuring More than N/3 times -->" << endl;
    print_1D_v(Ans);
    return 0;
}
