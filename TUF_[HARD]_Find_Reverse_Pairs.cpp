#include <iostream>
#include <vector>

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

int countPairs_Sol1(vector<int>& Arr)
{
    int n = Arr.size();

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Arr[i]>2*Arr[j])
                cnt++;
        }
    }
    return cnt;
}

int count_Pair_Only(vector<int>& Arr,int low,int mid,int high)
{
    int cnt = 0;
    int left = low,right=mid+1;
    for(;left<=mid;left++)
    {
        while(right<=high && Arr[left] > 2*Arr[right])
            right++;
        cnt = cnt + ( right - (mid+1) );
    }
    return cnt;

}

void Merge(vector<int>& Arr,int low,int mid,int high)
{
    print_1D_v(Arr,low,mid);
    print_1D_v(Arr,mid+1,high);

    int i=low,j=mid+1;

    vector<int> temp;
    while(i<=mid && j<=high)
    {
       if(Arr[i]<Arr[j])
       {
           temp.push_back(Arr[i]);
           i++;

       }
       else
       {
           temp.push_back(Arr[j]);
           j++;
       }
    }

    while(i<=mid)
    {
        temp.push_back(Arr[i]);
           i++;
    }

    while(j<=high)
    {
        temp.push_back(Arr[j]);
           j++;
    }

    for(int k=0;k<temp.size();k++)
        Arr[low+k] = temp[k];
    print_1D_v(Arr);
}



int MergeSort(vector<int>& Arr,int low,int high)
{
    int cnt = 0;
    if(low==high)
        return cnt;

    int mid = (low+high)/2;
    cnt+=MergeSort(Arr,low,mid);
    cnt+=MergeSort(Arr,mid+1,high);
    cnt+=count_Pair_Only(Arr,low,mid,high);
    Merge(Arr,low,mid,high);
    return cnt;
}

// TC --> O(2NLogn) NLogn for Merge and NLogn for Count Pairs
// SC --> O(1)
int countPairs_sol2(vector<int>& Arr)
{
    int cnt = 0;
    int n = Arr.size();
    cnt = MergeSort(Arr,0,n-1);
    print_1D_v(Arr);
    return cnt;
}

int main()
{
    vector<int> Arr = {40,19,25,9,12,6,2};
    int cnt = countPairs_sol2(Arr);
    print_1D_v(Arr);
    cout << "Pairs in Array =" <<  cnt << endl;
    return 0;
}
