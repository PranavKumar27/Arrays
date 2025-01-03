#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> Arr,int i,int j)
{
    for(int k=i;k<=j;k++)
        cout << Arr[k] << " ";
    cout << endl;
}

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}


void print_2D_v(vector<vector<int>> Arr)
{
    for(auto v:Arr)
        print_1D_v(v);
    cout << endl;
}

// TC --> O(N^4)
// SC --> O(M*4) * 2 for storing Ans in set and in vector where M is the number of Quads
vector<vector<int>> find_4_num_Sum_Sol1(vector<int> Arr,int K)
{
    int n = Arr.size();
    set<vector<int>> SS;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    int sum = Arr[i]+Arr[j]+Arr[k]+Arr[l];
                    //cout << "sum =" << sum << endl;
                    if(sum==K)
                    {
                        vector<int> temp = {Arr[i],Arr[j],Arr[k],Arr[l]};
                        sort(temp.begin(),temp.end());
                        SS.insert(temp);
                        //print_1D_v(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> Ans(SS.begin(),SS.end());
    return Ans;
}

// TC --> O(N^3)*LogM  here LogM is for M items in HashSet and find used over it
// SC --> O(N) for HashSet Size + O(M*4) * 2 for storing Ans in set and in vector where M is the number of Quads
vector<vector<int>> find_4_num_Sum_Sol2(vector<int> Arr,int K)
{
    int n = Arr.size();
    set<vector<int>> SS;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            set<int> HashSet;
            for(int k=j+1;k<n;k++)
            {
                int sum = Arr[i]+Arr[j]+Arr[k];

                int ValueNeeded = K - (sum);

                auto itr = HashSet.find(ValueNeeded);
                if(itr!=HashSet.end())
                {
                    vector<int> temp = {Arr[i],Arr[j],Arr[k],ValueNeeded};
                    sort(temp.begin(),temp.end());
                    SS.insert(temp);
                }
                else
                {
                    HashSet.insert(Arr[k]);
                }
            }
        }
    }
    vector<vector<int>> Ans(SS.begin(),SS.end());
    return Ans;
}

// TC -->  O(N^3)  Explanation  O(n^2)  -> for loop * O(n) -> while loop
// SC --> O(no of Quads) for storing Ans
vector<vector<int>> find_4_num_Sum_Sol3(vector<int> Arr,int K)
{
    int n = Arr.size();
    sort(Arr.begin(),Arr.end());
    vector<vector<int>> Ans;
    for(int i=0;i<n;i++)
    {
        if(i>0 && Arr[i]==Arr[i-1])
            continue;
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && Arr[j]==Arr[j-1])
                continue;

            int l=j+1;
            int k = n-1;
            while(l<k)
            {
                int sum = Arr[i]+Arr[j]+Arr[l]+Arr[k];
                //cout << "sum=" << sum << endl;
                if(sum==K)
                {
                    vector<int> temp = {Arr[i],Arr[j],Arr[l],Arr[k]};
                    Ans.push_back(temp);
                    //print_1D_v(temp);
                    l++;
                    k--;
                    while(l<k && Arr[l]==Arr[l-1])
                        l++;
                    while(l<k && Arr[k]==Arr[k+1])
                        k--;
                }
                else if(sum<K)
                {
                    l++;
                }
                else
                {
                    k--;
                }
            }
        }
    }
    return Ans;
}

int main()
{
    vector<int> Arr = {1,0,-1,0,2,-2};
    int k = 0;
    vector<vector<int>> Ans = find_4_num_Sum_Sol1(Arr,k);
    cout << "Quad Set Using Sol1 -->" << endl;
    print_2D_v(Ans);


    vector<vector<int>> Ans2 = find_4_num_Sum_Sol2(Arr,k);
    cout << "Quad Set Using Sol2 -->" << endl;
    print_2D_v(Ans2);

    vector<vector<int>> Ans3 = find_4_num_Sum_Sol3(Arr,k);
    cout << "Quad Set Using Sol3 -->" << endl;
    print_2D_v(Ans3);

    return 0;
}
