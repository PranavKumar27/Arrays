#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void print_1D_v(vector<int> Arr)
{
    for(auto d:Arr)
        cout << d << " ";
    cout << endl;
}
pair<int,int> Missing_No_Repeating_No_Sol1(vector<int>& Arr,int n)
{
    int missing_no = INT_MAX;
    int repeating_no = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int cnt = 0;
        for(int j=0;j<n;j++)
        {
            if(Arr[j]==i)
                cnt++;
        }
        if(cnt == 2)
            repeating_no = i;
        if(cnt == 0)
            missing_no = i;

        if(repeating_no != INT_MAX && missing_no != INT_MAX) // We found the missing and repeating Nos
            break;

    }
    return {missing_no,repeating_no};
}


pair<int,int> Missing_No_Repeating_No_Sol2(vector<int>& Arr,int n)
{
    int missing_no = INT_MAX;
    int repeating_no = INT_MAX;

    vector<int> Hash(n+1);
    for(int i=0;i<n;i++)
    {
        Hash[Arr[i]]++; // Freq Table
    }

    for(int i=1;i<=n;i++)
    {
        if(Hash[i]==2)
            repeating_no = i;
        else if(Hash[i]==0)
            missing_no = i;

        if(repeating_no != INT_MAX && missing_no != INT_MAX) // We found the missing and repeating Nos
            break;

    }

    return make_pair(missing_no,repeating_no);
}

pair<int,int> Missing_No_Repeating_No_Sol3(vector<int>& Arr,int n)
{
    int X; // Missing No
    int Y; // Repeating No

    int sumOfNums = (n*(n+1))/2;
    int sumOfSquares = (n*(n+1)*(2*n+1))/6;

    int IterativeSum=0,IterativeSumOfSqaures=0;
    for(int i=0;i<n;i++)
    {
        IterativeSum+=Arr[i];
        IterativeSumOfSqaures+=Arr[i]*Arr[i];
    }

    // X - Y  = sumOfNums - IterativeSum
    int X_minus_Y = sumOfNums - IterativeSum;

    int X_sq_minus_Y_sq = sumOfSquares - IterativeSumOfSqaures;
    int X_plus_y = X_sq_minus_Y_sq/X_minus_Y;

    int Twice_X = X_plus_y + X_minus_Y ;
    X = Twice_X/2;
    Y = X_plus_y - X;

    return {X,Y};
}

vector<int> convert_to_binary(int n)
{
    vector<int> binary(3,0);

    int rem,quo;
    quo = n;
    int j =0;
    if(quo!=1)
    {
        do
        {
            rem = quo%2;
            quo = quo/2;
            binary[j] =rem;
            j++;
        }while(quo!=1);
    }


    binary[j]=quo;
    reverse(binary.begin(),binary.end());
    return binary;
}
int find_different_bit(vector<int> bin)
{
    reverse(bin.begin(),bin.end());
    int n = bin.size();
    for(int i=0;i<n;i++)
    {
        if(bin[i]==1)
            return i;
    }
    return -1;
}
pair<int,int> Missing_No_Repeating_No_Sol4(vector<int>& Arr,int n)
{
    int X; // Missing  No
    int Y; // Repeating No
    X = INT_MAX,Y=INT_MAX;

    int XOR_all_Nums = 0; // X^Y
    for(int i=0;i<n;i++)
    {
        XOR_all_Nums = XOR_all_Nums ^ (i+1) ^ Arr[i];
    }

    cout << "XOR_all_Nums -->" << XOR_all_Nums<< endl;
    // convert XOR_all_Nums to binary Equivalent

    vector<int> binary_equivalent = convert_to_binary(XOR_all_Nums);
    int bit = find_different_bit(binary_equivalent);

    cout << "binary_equivalent -->" << endl;
    print_1D_v(binary_equivalent);
    cout << "bit set index =" << bit << endl;

    if(bit!=-1)
    {
        vector<int> bit_Club_0,bit_Club_1;
        int XOR_Club_0=0,XOR_Club_1=0;
        for(int i=0;i<2*n;i++)
        {
            int val;
            if(i<n)
                val = Arr[i];
            else
                val = i-n+1;
            binary_equivalent = convert_to_binary(val);
           // cout << "binary_equivalent -->" << endl;
            print_1D_v(binary_equivalent);
            reverse(binary_equivalent.begin(),binary_equivalent.end());

            if(binary_equivalent[bit]==1)
            {

                bit_Club_1.push_back(val);
                XOR_Club_1 = XOR_Club_1^val;
            }

            else
            {
                bit_Club_0.push_back(val);
                XOR_Club_0 = XOR_Club_0^val;
            }


        }

        cout << "XOR_Club_1 =" << XOR_Club_1 << endl;
        cout << "XOR_Club_0 =" << XOR_Club_0 << endl;

        print_1D_v(bit_Club_0);
        print_1D_v(bit_Club_1);



        // Find if XOR_Club_0 exists in Array, If Yes, XOR_Club_0 is Repeating No

        bool IsFound = false;
        for(int i=0;i<n;i++)
        {
            if(Arr[i]==XOR_Club_0)
            {
                IsFound = true;
                break;
            }

        }
        if(IsFound)
        {
            X = XOR_Club_1; // Missing No
            Y = XOR_Club_0; // Repeating No

        }
        else
        {
            X = XOR_Club_0;
            Y = XOR_Club_1;
        }


    }
    return {X,Y};
}

pair<int,int> Missing_No_Repeating_No_Sol5(vector<int>& Arr,int n)
{
     int X; // Missing  No
    int Y; // Repeating No
    X = INT_MAX,Y=INT_MAX;

    int XOR_all_Nums = 0; // X^Y
    for(int i=0;i<n;i++)
    {
        XOR_all_Nums = XOR_all_Nums ^ Arr[i];
        XOR_all_Nums = XOR_all_Nums ^ (i+1);
    }

    cout << "XOR_all_Nums -->" << XOR_all_Nums<< endl;
    // find the bit set

    int set_bit=0;
    while(1)
    {
        if((XOR_all_Nums & (1<<set_bit))==0)
            set_bit++;
        else
            break;
    }
    cout << "Set_bit=" << set_bit << endl;
    int Ones=0,Zeros=0;
    for(int i=0;i<n;i++)
    {
        if( (Arr[i] & (1<<set_bit)) != 0)
            Ones = Ones^Arr[i];
        else
            Zeros = Zeros^Arr[i];
    }

    for(int i=1;i<=n;i++)
    {
        if( (i & (1<<set_bit)) != 0 )
            Ones = Ones^i;
        else
            Zeros = Zeros^i;
    }

    cout << "Ones=" << Ones << "Zeros=" << Zeros << endl;

    int cnt =0;
    for(int i=0;i<n;i++)
    {
        if(Arr[i]==Ones)
            cnt++;
    }

    if(cnt==2) // Repeating No is Ones
        return {Zeros,Ones};
    else
        return {Ones,Zeros};

}
int main()
{
    vector<int> Arr = {4,3,6,2,1,1};
    int n = Arr.size();

    pair<int,int> res = Missing_No_Repeating_No_Sol1(Arr,n);
    cout << "Using Sol1 Missing No =" << res.first << " Repeating No =" << res.second << endl;

    pair<int,int> res1 = Missing_No_Repeating_No_Sol2(Arr,n);
    cout << "Using Sol2 Missing No =" << res1.first << " Repeating No =" << res1.second << endl;

    pair<int,int> res3 = Missing_No_Repeating_No_Sol3(Arr,n);
    cout << "Using Sol3 Missing No =" << res3.first << " Repeating No =" << res3.second << endl;

    pair<int,int> res4 = Missing_No_Repeating_No_Sol4(Arr,n);
    cout << "Using Sol4 Missing No =" << res4.first << " Repeating No =" << res4.second << endl;

    pair<int,int> res5 = Missing_No_Repeating_No_Sol5(Arr,n);
    cout << "Using Sol5 Missing No =" << res5.first << " Repeating No =" << res5.second << endl;

    return 0;
}
