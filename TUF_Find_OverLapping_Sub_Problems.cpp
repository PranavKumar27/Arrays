#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_1D_vP(vector<pair<int,int>> Vp)
{
    for(auto d:Vp)
    {
        cout << "{ " << d.first << "," << d.second << " }" << endl;
    }
}
int count_Overlapping_SubArrays(vector<pair<int,int>>& Arr)
{
    sort(Arr.begin(),Arr.end());
    int n = Arr.size();
    int cnt = 1;
    pair<int,int> p = Arr[0];
    int s=p.first,e=p.second;
    for(int i=1;i<n;i++)
    {
        //cout << "s=" << s << " e=" << e << endl;
        p = Arr[i];
        int new_s = p.first;
        int new_e = p.second;

        if(s<=new_s && new_s<=e)
        {
            s = min(s,new_s);
            e = max(e,new_e);
        }
        else
        {
            cnt++;
            s = new_s;
            e = new_e;
        }
    }
    return cnt;
}

vector<pair<int,int>> count_Overlapping_SubArrays_Sol1(vector<pair<int,int>>& Arr)
{
    sort(Arr.begin(),Arr.end());
    vector<pair<int,int>> Ans;
    int n = Arr.size();
    int cnt = 1;
    pair<int,int> p = Arr[0];
    int start,ends;
    for(int i=0;i<n;i++)
    {
       pair<int,int> p = Arr[i];
       if(Ans.empty()||p.first>ends)
       {
           Ans.push_back(Arr[i]);
           start = p.first;
           ends = p.second;
       }
       else
       {
           if(p.first<=ends)
           {
               if(p.second>ends)
               {
                   ends = p.second;
               }
               else
                break;
           }
       }
    }
    return Ans;
}

int main()
{
    vector<pair<int,int>> Arr ={{1,3},{2,6} ,{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    int cnt = count_Overlapping_SubArrays(Arr);
    cout << "count Overlapping SubArrays =" << cnt << endl;

    cout << "All Overlapping SubArrays --> " << endl;
    vector<pair<int,int>> Ans = count_Overlapping_SubArrays_Sol1(Arr);
    print_1D_vP(Ans);
    return 0;
}
