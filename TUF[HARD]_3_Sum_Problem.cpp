#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define THREE 3

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


void print_2D_Set_v(set<vector<int>> Arr)
{
    for(auto v:Arr)
        print_1D_v(v);
    cout << endl;
}

int findSum(vector<int> Arr)
{
    int sum = 0;
    for(auto d: Arr)
      sum+=d;
    return sum;
}

bool checkUnique(vector<int> Arr)
{
    int sum = 0;
    map<int,int> Hash;
    int sz = Arr.size();
    for(int i=0;i<sz;i++)
    {
        if(Hash[Arr[i]]==0)
            Hash[Arr[i]]=1;
        else
            return false;
    }
    return true;
}
int findTripletSum_K(vector<int>& Arr,int K)
{
    sort(Arr.begin(),Arr.end());
    set<vector<int>> SS;
    int n = Arr.size();
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {

            for(int k=j+1;k<n;k++)
            {
                int sum =0;
                sum = Arr[i]+Arr[j]+Arr[k];
                vector<int> temp = {Arr[i],Arr[j],Arr[k]};
                auto itr = SS.find(temp);
                if(sum==K && itr==SS.end())
                {
                    SS.insert(temp);
                    cout << Arr[i] << "," << Arr[j] << "," << Arr[k] << endl;
                    cnt++;
                }

            }


        }
    }
    return cnt;
}

// TC --> O(N*N) + O(LogM) for storing in set
// SC --> O(N) + O(M)*2 for storing Ans in set and then vector
vector<vector<int>> findTripletSum_K_Sol2(vector<int>& Arr,int K)
{
    print_1D_v(Arr);
    set<vector<int>> St;
    int n = Arr.size();
    for(int i=0;i<n;i++)
    {
        set<int> HashSet;
        for(int j=i+1;j<n;j++)
        {
            int valNeeded = -(Arr[i]+Arr[j]);
            cout << "valNeeded =" << valNeeded << endl;
            // find if valNeeded is present in HashSet
            auto itr = HashSet.find(valNeeded);
            if(itr!=HashSet.end())
            {
                vector<int> temp = {Arr[i],Arr[j],valNeeded};
                sort(temp.begin(),temp.end());
                St.insert(temp);
                cout << "Triplet --> " << Arr[i] << "," << Arr[j] << "," << valNeeded << endl;
            }
           // else
            {
                HashSet.insert(Arr[j]);
            }
        }
        //HashSet.clear();
    }

    vector<vector<int>> Ans(St.begin(),St.end());


    return Ans;
}
//TC --> O(NLOgN) + O(N*N)
//SC --> O(N) for storing Ans

vector<vector<int>> findTripletSum_K_Sol3(vector<int>& Arr,int K)
{
    int n = Arr.size();
    sort(Arr.begin(),Arr.end());

    set<vector<int>> St;
    for(int i=0;i<n;i++)
    {
        if(i>=1 && Arr[i]==Arr[i-1])
            continue;
        int j = i+1;
        int k = n-1;

        while(j<k && j<n && k>=0)
        {
            int sum = Arr[i]+Arr[j]+Arr[k];
            if(sum == 0)
            {
                vector<int> temp = {Arr[i],Arr[j],Arr[k]};
                St.insert(temp);
                j++;
                k--;


                while(j<k && Arr[j-1]==Arr[j])
                    j++;

                while(j<k && Arr[k]==Arr[k+1])
                    k--;
            }
            else if(sum<0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    vector<vector<int>> Ans(St.begin(),St.end());
    return Ans;
}
// TC --> O(Exponential)
// SC --> O(N) for Map
int findTripletSum_K_Recursion(int index,vector<int> Arr,vector<int> ArrList,int K,map<vector<int>,int>& Hash)
{
   int sum = findSum(ArrList);
   sort(ArrList.begin(),ArrList.end());
   int sz = ArrList.size();
   int n = Arr.size();
   if(sum == K && sz == THREE && Hash[ArrList]==0)
   {
       Hash[ArrList] = 1;
       cout << "Found A Triplet" << endl;
       print_1D_v(ArrList);
       return 1;
   }
   if(index==n)
   {
       return 0;
   }


   ArrList.push_back(Arr[index]);
   int take = findTripletSum_K_Recursion(index+1,Arr,ArrList,K,Hash);


   // Remove from ArrList
   auto itr = find(ArrList.begin(),ArrList.end(),Arr[index]);
   ArrList.erase(itr);

   int not_take = findTripletSum_K_Recursion(index+1,Arr,ArrList,K,Hash);

   return (take+not_take);
}

int main()
{
    //vector<int> Arr = {0,0,0};
    vector<int> Arr = {-1,0,1,-1,2,-4};
    //sort(Arr.begin(),Arr.end());
    int k =0;
    int ans = findTripletSum_K(Arr,k);
    cout << "Count of Triplets with Sum as " << k << " equals --> " << ans << endl;

    cout << "Count of Triplets with Sum as " << k << " equals --> " << ans  << " Using Sol 2 "<< endl;
    vector<vector<int>> Ans = findTripletSum_K_Sol2(Arr,k);
    print_2D_v(Ans);

    vector<int> Arr1 = {0,0,-1,-1,2,2,-1,0,2,-1,0,-2,-2};
    cout << "Count of Triplets with Sum as " << k << " equals --> " << ans  << " Using Sol 3 "<< endl;
    vector<vector<int>> Ans1 = findTripletSum_K_Sol3(Arr1,k);
    print_2D_v(Ans1);


    map<vector<int>,int> Hash;
    ans = findTripletSum_K_Recursion(0,Arr,{},k,Hash);
    cout << "Count of Triplets with Sum as " << k << " equals --> " << ans << endl;
    return 0;
}
