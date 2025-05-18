#include <iostream>
#include <vector>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

vector<int> Merge(vector<int> Arr1,vector<int> Arr2)
{
    int m = Arr1.size();
    int n = Arr2.size();
    int len = m+n;
    vector<int> Ans;

    int i=0,j=0;
    while(i<m && j<n)
    {
        if(Arr1[i]<Arr2[j])
        {
            Ans.push_back(Arr1[i]);
            i++;
        }
        else
        {
            Ans.push_back(Arr2[j]);
            j++;
        }
    }

    while(i<m)
    {
        Ans.push_back(Arr1[i]);
        i++;
    }

    while(j<n)
    {
        Ans.push_back(Arr2[j]);
        j++;
    }

    return Ans;

}

vector<int> sorting(vector<int> Arr,int s,int e)
{
    //cout << "s=" << s << " e=" << e << endl;
    int n = Arr.size();
    if(s==e)
    {
        //cout << "Arr[s]=" << Arr[s] << endl;
        return {Arr[s]};
    }
    int mid = (s+e)/2;
    //cout << "mid=" << mid << endl;

    vector<int> Left = sorting(Arr,s,mid);
    vector<int> Right = sorting(Arr,mid+1,e);

    vector<int> mergedArr = Merge(Left,Right);
    print_1D_v(mergedArr);
    return mergedArr;

}

void merge_Arr(vector<int>& Arr,int low, int mid,int high)
{
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left<=mid && right<=high)
    {
        if(Arr[left]<=Arr[right])
        {
            temp.push_back(Arr[left]);
            left++;
        }
        else
        {
            temp.push_back(Arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(Arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(Arr[right]);
        right++;
    }

    int k=0;
    for(int i=low;i<=high;i++)
    {
        Arr[i]=temp[k++];
    }
}

// TC --> O(NLogN) since Proces get reduced by N/2 everytime
// SC --> O(1)
void mergeSort(vector<int>& Arr,int low,int high)
{
    if(low==high)
        return;

    int mid = (low+high)/2;

    mergeSort(Arr,low,mid);

    mergeSort(Arr,mid+1,high);

    merge_Arr(Arr,low,mid,high);

}


int main()
{
    vector<int> Arr ={3,1,2,4,1,5,2,6,4};
    int s=0;
    int e = Arr.size()-1;
    vector<int> Ans = sorting(Arr,s,e);

    cout << "Sorted Array Technique 1-->" << endl;
    print_1D_v(Ans);

    cout << "Sorted Array Technique 2-->" << endl;
    mergeSort(Arr,s,e);
    print_1D_v(Arr);
    return 0;
}
