#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}

void print_2D_v(vector<vector<int>> _2DArr)
{
    for(auto Arr:_2DArr)
        print_1D_v(Arr);
    cout << endl;
}

bool cmp(int a,int b)
{
    return (a>b)?a:b;
}

// TC --> O(N!*N)
// SC --> O(N) for ArrList Array + O(N) for Map 
void Generate_Permutaions_Sol1(vector<int> ArrList,map<int,int> Mp,const vector<int>& Arr,vector<vector<int>>& PermutaionsList)
{
    int n = Arr.size();
    int k = ArrList.size();

    if(k==n)
    {
        PermutaionsList.push_back(ArrList);
        //print_1D_v(ArrList);
        return;
    }

    for(int i=0;i<n;i++)
    {
        int val = Arr[i];
        auto itr = Mp.find(val);
        if(itr==Mp.end()) // Not Added to Map
        {
            Mp[val] = 1;
            ArrList.push_back(val);
            Generate_Permutaions_Sol1(ArrList,Mp,Arr,PermutaionsList);
            auto itr_v = find(ArrList.begin(),ArrList.end(),val);
            ArrList.erase(itr_v);
            Mp.erase(val);
        }
    }
}
bool IsSame(const vector<int>& A,const vector<int>& B)
{
    int A_sz = A.size();
    int B_sz = B.size();

    if(A_sz == B_sz)
    {
        for(int i=0;i<A_sz;i++)
        {
            if(A[i]!=B[i])
                return false;
        }
    }
    else
        return false;

    return true;
}

vector<int> find_Next_Permutaions_Sol1(const vector<int>& Arr,const vector<vector<int>>& PermutaionsList)
{
    int sz = PermutaionsList.size();
    vector<int> temp ={};
    for(int i=0;i<sz;i++)
    {
        temp = PermutaionsList[i];
        if(IsSame(temp,Arr))
            return PermutaionsList[(i+1)%sz];
    }
    return temp;
}
void Generate_Permutaions_Sol2(vector<int> Arr)
{
/*
    do
    {
        print_1D_v(Arr);
    }while(next_permutation(Arr.begin(),Arr.end()));

*/
    // We could also do as

    sort(Arr.begin(),Arr.end(),cmp);
    do
    {
        print_1D_v(Arr);
    }while(prev_permutation(Arr.begin(),Arr.end()));


}

vector<int> find_Next_Permutaions_Sol2(const vector<int>& Arr)
{
    vector<int> temp = Arr;
    next_permutation(temp.begin(),temp.end());
    return temp;
}

/*
Step 1: Find the Longest Prefix Match greater than current Arr
        To find this find the breakpoint greater than Arr[i]
        such that Arr[i]<Arr[i+1]
        This will work as partition/breakpoint so we find i using this
                        Arr[i]<Arr[i+1]
    Eg: 2 1 5 4 3 0 0
                  ^     0<0 False
                ^       3<0 False
              ^         4<3 False
            ^           5<4 False
          ^             1<5 True ----> Breakpoint

Step 2: Find the value which is minimum but '>' Arr[index]
        So we find value which is greater than breakpoint but smallest among all

     Eg: 2 1 5 4 3 0 0
           ^
    Breakpoint = 1
    Hence compare
                    1<0
                    1<3 ---> Smallest
                    1<4
                    1<5
    Swap Arr[index] with Smallest Value index

    Ans Arr =  2 3 5 4 1 0 0
                 ^

Step 3: Reverse the array from index+1

    Reverse Arr =  2 3 5 4 1 0 0
                       ^
      Ans Arr =  2 3 0 0 1 4 5


*/
// TC --> O(3N)
// SC --> O(N) for Ans Array
vector<int> find_Next_Permutaions_Sol3(vector<int> Arr)
{
    int n = Arr.size();

    // Step 1: Find the BreakPoint whereby elements value drop for the first time
    int index = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(Arr[i]<Arr[i+1])
        {
            index=i;
            break;
        }
    }

    if(index == -1)
    {
        reverse(Arr.begin(),Arr.end());
        return Arr;
    }
    // Step 2: Find Minimum value in Arr[index+1.......n-1] which is closest or min diff with Arr[index]
    for(int i=n-1;i>index;i--)
    {
        if(Arr[i]>Arr[index])
        {
            swap(Arr[i],Arr[index]);
            break;
        }
    }

    // Step 3: Reverse All the elements from index+1 to n-1
    reverse(Arr.begin()+index+1,Arr.end());
    return Arr;
}

int main()
{
    vector<int> Arr = {1,2,3};
    vector<vector<int>> PermutaionsList;
    cout << "The Permutations Using Sol1 are :: -->" << endl;
    Generate_Permutaions_Sol1({},{},Arr,PermutaionsList);
    print_2D_v(PermutaionsList);

    vector<int> TstArr = {3,2,1};
    cout << "Input Array -->" << endl;
    print_1D_v(TstArr);
    vector<int> Ans_1 = find_Next_Permutaions_Sol1(TstArr,PermutaionsList);
    cout << "Next Permutation Using Sol1 -->" << endl;
    print_1D_v(Ans_1);

    cout << "The Permutations Using Sol2 are :: -->" << endl;
    Generate_Permutaions_Sol2(Arr);

    vector<int> TestArr = {2,1,5,3,0};
    cout << "Input Array -->" << endl;
    print_1D_v(TestArr);
    vector<int> Ans_2 = find_Next_Permutaions_Sol2(TestArr);
    cout << "Next Permutation is Using Sol2 -->" << endl;
    print_1D_v(Ans_2);



    vector<int> TestArr_3 = {2,1,5,4,3,0,0};
    cout << "Input Array -->" << endl;
    print_1D_v(TestArr_3);
    vector<int> Ans_3 = find_Next_Permutaions_Sol3(TestArr_3);
    cout << "Next Permutation is Using Sol3 -->" << endl;
    print_1D_v(Ans_3);

    return 0;
}
