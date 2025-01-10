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

// TC --> O(N*N)
// SC --> O(1)
int countInversions_Sol1(vector<int>& Arr)
{
    int n = Arr.size();
    int cnt =0 ;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(Arr[i]>Arr[j])
                cnt++;
        }
    }
    return cnt;
}

void Merge(vector<int>& Arr,int low,int mid,int high,int& cnt)
{
    cout << "low=" << low << " mid=" << mid << " high=" << high << endl;
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
            cnt+= mid-i+1;
            cout << "Inside cnt=" << cnt << endl;
            temp.push_back(Arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(Arr[i]);
            i++;
    }

    while(j<=mid)
    {
        temp.push_back(Arr[j]);
            j++;
    }

    int sz = temp.size();
    for(int k=0;k<sz;k++)
    {
        Arr[low+k] = temp[k];
    }

    cout << "cnt=" << cnt << endl;
    print_1D_v(Arr);
}

int Merge_Sort(vector<int>& Arr,int low,int high,int& cnt)
{
    if(low==high)
        return 0;
    int mid = (low+high)/2;

    Merge_Sort(Arr,low,mid,cnt);
    Merge_Sort(Arr,mid+1,high,cnt);
    Merge(Arr,low,mid,high,cnt);
    return cnt;
}

int main()
{
    vector<int> Arr = {5,3,2,4,1};
    int counting=0;
    int cnt = Merge_Sort(Arr,0,4,counting);
    print_1D_v(Arr);
    cout << "countInversions =" << cnt << endl;
    return 0;
}
